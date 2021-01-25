# THE CRUX: HOW TO UPDATE THE DISK DESPITE CRASHES
The system may crash or lose power between any two writes, and thus the on-disk state may only partially get updated. After the crash, the system boots and wishes to mount the file system again (in order to access files and such). Given that crashes can occur at arbitrary points in time, how do we ensure the file system keeps the on-disk image in a reasonable state?


# 41.1 Problem may happen
__crash-consistency problem__:
1. inconsistency
2. space leak
3. return garbage data


# 42.2 Solution #1: The File System Checker
1. let inconsistencies happen and then fix them later(when rebooting)
2. Note that such an approach can’t fix all problems; consider, for example, the case above where the file system looks consistent but the inode points to garbage data.
3. The only real goal is to make sure the file system metadata is internally consistent.

4. The tool fsck operates in a number of phases:
    * It is run before the file system is mounted and made available (fsck assumes that no other file-system activity is on-going while it runs)
    * once finished, the on-disk file system should be consistent and thus can be made accessible to users.

5. summary of what fsck dose:
    * Superblock
    * Free blocks: if there is any inconsistency between bitmaps and inodes, it is resolved by trusting the information within the inodes
    * Inode state
    * Inode links: If there is a mismatch between the newly-calculated count and that found within an inode, corrective action must be taken, usually by fixing the count within the inode. If an allocated inode is discovered but no directory refers to it, it is moved to the lost+found directory.
    * Duplicates: caseswhere two different inodes refer to the same block. 
        1. If one inode is obvi- ously bad, it may be cleared. 
        2. Alternately, the pointed-to block could be copied, thus giving each inode its own copy as desired.
    * BadblocksA pointer is considered “bad” if it obviously points to something outside its valid range. it just removes (clears) the pointer from the inode or indirect block.
    * Directory checks: Thus, fsck performs additional integrity checks on the contents of each directory, making sure that:
        1. “.” and “..” are the first entries
        2. each inode referred to in a directory entry is allocated
        3. ensuring that no directory is linked to more than once in the entire hierarchy

6. Disadvantage:
    1. too slow
    2. basic premise is irrational. it is incredibly expensive to scan the entire disk to fix prob- lems that occurred during an update of just three blocks (search-the-entire-house-for-keys recovery algorithm)


# 42.3 Solution #2: Journaling (or Write-Ahead Logging)
1. Linux apply journaling
2. The basic idea is as follows:
    * When updating the disk, before over- writing the structures in place, first write down a little note (somewhere else on the disk, in a well-known location) describing what you are about to do.
    * Writing this note is the “write ahead” part, and we write it to a structure that we organize as a “log”

3. By writing the note to disk, you are guaranteeing that if a crash takes places during the update (overwrite) of the structures you are updating, you can go back and look at the note you made and try again; thus, you will know exactly what to fix (and how to fix it) after a crash, instead of having to scan the entire disk.
4. By design, journaling thus adds a bit of work during updates to greatly reduce the amount of work required during recovery.

### Data Journaling
1. the components of log:
    1. The transaction begin (TxB) tells us about this update, including information about the pend- ing update to the file system (e.g., the final addresses of the blocks I[v2], B[v2], and Db), as well as some kind of transaction identifier (TID)
    2. middle three blocks just contain the exact contents of the blocks themselves(physical logging)
    3. The final block (TxE) is a marker of the end of this transaction, and will also contain the TID.

2. Things get a little trickier when a crash occurs during the writes to the journal.
4. 解释了五个block如何写入disk的顺序！（因为这五个block写入时，本身也可能发生crash）
5. To avoid this problem, the file system issues the transactional write in two steps. First, it writes all blocks except the TxE block to the journal, issuing these writes all at once.
6. Thus, our current protocol to update the file system, with each of its three phases labeled:
    1. Journal write: Write the contents of the transaction (including TxB, metadata, and data) to the log; wait for these writes to complete.
    2. Journal commit: Write the transaction commit block (containing TxE) to the log; wait for write to complete; transaction is said to be committed.
    3. Checkpoint: Write the contents of the update (metadata and data)
to their final on-disk locations.


### Recovery
以 Stap 2 Journal commit 为分解点：之前的不恢复，之后的进行恢复

### Batching Log Updates
Problem: 
    With journaling, we logically commit all of this information to the journal for each of our two file creations; because the files are in the same directory, and let’s assume even have inodes within the same inode block, this means that if we’re not careful, we’ll end up writing these same blocks over and over.

To remedy this problem, some file systems do not commit each update to disk one at a time (e.g., Linux ext3); rather, one can buffer all updates into a global transaction.

Thus, by buffering updates, a file system can avoid excessive write traffic to disk in many cases.

### Making The Log Finite
1. Two problems arise when the log becomes full:
    * The first is simpler, but less critical: the larger the log, the longer recovery will take, as the recovery process must replay all the transactions within the log (in order) to recover.
    * The second is more of an issue: when the log is full (or nearly full), no further transactions can be committed to the disk, thus making the file system “less than useful” (i.e., useless).

2. To address these problems, journaling file systems treat the log as a circular data structure, re-using it over and over; this is why the journal is sometimes referred to as a circular log.

3. the file system should free the space it was occupying within the journal, allowing the log space to be reused

4. And thus we add another step to our basic protocol:
    1. Journal write: Write the contents of the transaction (containing TxB and the contents of the update) to the log; wait for these writes to complete.
    2. Journal commit: Write the transaction commit block (containing TxE) to the log; wait for the write to complete; the transaction is now committed.
    3. Checkpoint:Writethecontentsoftheupdatetotheirfinallocations within the file system.
    4. Free: Some time later, mark the transaction free in the journal by updating the journal superblock.


### Metadata Journaling
1. Because of the high cost of writing every data block to disk twice, peo- ple have tried a few different things in order to speed up performance.
2. the mode of journaling we described above is often called data journaling (as in Linux ext3), as it journals all user data (in addition to the metadata of the file system)
3. A simpler (and more common) form of journaling is sometimes called ordered journaling (or just metadata journaling), and it is nearly the same, except that user data is not writ- ten to the journal.

Journaling 不写入 data block
4. The data block Db, previously written to the log, would instead be written to the file system proper, avoiding the extra write; given that most I/O traffic to the disk is data, not writing data twice substantially reduces the I/O load of journaling.

5. write data blocks (of regular files) to the disk first, before related metadata is written to disk. Specifically, the protocol is as follows:
    1. Data write: Write data to final location; wait for completion (the wait is optional; see below for details).
    2. Journal metadata write: Write the begin block and metadata to the log; wait for writes to complete.
    3. Journal commit: Write the transaction commit block (containing TxE) to the log; wait for the write to complete; the transaction (in- cluding data) is now committed.
    4. Checkpoint metadata: Write the contents of the metadata update to their final locations within the file system.
    5. Free: Later, mark the transaction free in journal superblock.

6. By forcing the data write first, a file system can guarantee that a pointer will never point to garbage. Indeed, this rule of “write the pointed to ob- ject before the object with the pointer to it” is at the core of crash consis- tency, and is exploited even further by other crash consistency schemes

7. Linux ext3 gives you the option of choosing either data, ordered, or unordered modes (in unordered mode, data can be written at any time). All of these modes keep metadata consistent; they vary in their semantics for data.

**顺序问题的关键是 step 3 Journal commit，因为它才是决定 recovery 阶段是否恢复block的分水岭！！！**
8. Finally, note that forcing the data write to complete (Step 1) before issuing writes to the journal (Step 2) is not required for correctness, as indicated in the protocol above. Specifically, it would be fine to issue data writes as well as the transaction-begin block and metadata to the journal; the only real requirement is that Steps 1 and 2 complete before the issuing of the journal commit block (Step 3).

