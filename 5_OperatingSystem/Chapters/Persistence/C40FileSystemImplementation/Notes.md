1. The file system is pure software
2. we will not be adding hardware features to make some aspect of the file system work better
3. Because of the great flexibility we have in building a file system, many different ones have been built
4. All of these file systems have different data structures and do some things better or worse than their peers.

# THE CRUX: HOW TO IMPLEMENT A SIMPLE FILE SYSTEM
How can we build a simple file system? What structures are needed
on the disk? What do they need to track? How are they accessed?


# 40.1 The Way To Think
1. To think about file systems, we usually suggest thinking about two different aspects of them
    * The first is the data structures of the file system. 
    * The second aspect of a file system is its access methods.


# 40.2 Overall Organization
1. The first thing we’ll need to do is divide the disk into blocks; simple file systems use just one block size

2. Thus, our view of the disk partition where we’re building our file sys- tem is simple: a series of blocks, each of size 4 KB. The blocks are ad- dressed from 0 to N − 1, in a partition of size N 4-KB blocks.

3. Let’s call the region of the disk we use for user data the data region. reserve a fixed portion of the disk for these blocks, say the last 56 of 64 blocks on the disk:

4. the file system has to track information about each file. This information is a key piece of metadata, and tracks things like which data blocks (in the data region) comprise a file, the size of the file, its owner and access rights, access and mod- ify times, and other similar kinds of information.

5. To store this informa- tion, file system usually have a structure called an inode

6. To accommodate inodes, we’ll need to reserve some space on the disk for them as well. Let’s call this portion of the disk the inode table, which simply holds an array of on-disk inodes.

7. One primary component that is still needed, as you might have guessed, is some way to track whether inodes or data blocks are free or allocated. Such allocation structures are thus a requisite element in any file system.

8. Many allocation-tracking methods are possible, of course. For exam- ple, we could use a free list that points to the first free block, which then points to the next free block, and so forth. We instead choose a simple and popular structure known as a bitmap, one for the data region (the data bitmap), and one for the inode table (the inode bitmap).

9. A bitmap is a simple structure: each bit is used to indicate whether the corresponding object/block is free (0) or in-use (1)

10. We reserve this for the superblock, denoted by an S in the diagram below. The superblock contains information about this particular file system, including, for example, how many inodes and data blocks are in the file system where the inode table begins (block 3), and so forth. It will likely also include a magic number of some kind to identify the file system type (in this case, vsfs).

**组成（按顺序）**：
    1. superblock
    2. allocation structures
    3. Inodes
    4. data

11. 
Thus, when mounting a file system, the operating system will read the superblock first, to initialize various parameters, and then attach the volume to the file-system tree. When files within the volume are accessed, the system will thus know exactly where to look for the needed on-disk structures.


# 40.3 File Organization: The Inode
1. The name inode is short for __index node__
2. Each inode is implicitly referred to by a number (called the inumber), which we’ve earlier called the low-level name of the file
3. given an i-number, you should directly be able to calculate where on the disk the corresponding inode is located

4. the sector 512 address iaddr of the inode block can be calculated(see in the book)
5. (refer to Table 40.1 to see details) Inside each inode is virtually all of the information you need about a file. We refer to all such information about a file as __metadata__; in fact, any information inside the file system that isn’t pure user data is often referred to as such

6. __One of the most important decisions in the design of the inode is how it refers to where data blocks are__

### The Multi-Level Index
1. __indirect pointer__: points to a block that contains more pointers, each of which point to user data
2. Thus, an inode may have some fixed number of direct pointers (e.g., 12), and a single indirect pointer.
3. double indirect pointer and triple indirect pointer to support bigger files
4. Overall, this imbalanced tree is referred to as the multi-level index ap- proach to pointing to file blocks.

5. Linux and Unix file system apply Multi-Level Index approach


# 40.4 Directory Organization
1. a directory basically just contains a list of (entry name, inode num- ber) pairs
2. For each file or directory in a given directory, there is a string and a number in the data block(s) of the directory.

3. Deleting a file (e.g., calling unlink()) can leave an empty space in the middle of the directory, and hence there should be some way to mark that as well (e.g., with a reserved inode number such as zero). Such a delete is one reason the record length is used: a new entry may reuse an old, bigger entry and thus have extra space within.

4. file systems treat directories as a special type of file.


# 40.5 Free Space Management
1. A file system must track which inodes and data blocks are free, and which are not, so that when a new file or directory is allocated, it can find space for it.

2. Thus free space management is important for all file systems.

3. The file system will thus search through the bitmap for an in- ode that is free, and allocate it to the file; the file system will have to mark the inode as used (with a 1) and eventually update the on-disk bitmap with the correct information.

4. Some other considerations might also come into play when allocating data blocks for a new file.


# 40.6 Access Paths: Reading and Writing
Understanding what happens on this access path is thus the second key in developing an understanding of how a file system works; pay attention!

### Reading A File From Disk
文件夹级：递归遍历树直到查找到对应的 i-number
文件内数据

### ASIDE: READS DON’T ACCESS ALLOCATION STRUCTURES
Allocation structures, such as bitmaps, are only accessed when allocation is needed. The inodes, directories, and indirect blocks have all the information they need to complete a read re- quest; there is no need to make sure a block is allocated when the inode
already points to it.

### Writing to Disk
1. Thus, each write to a file logically generates three I/Os: 
    one to read the data bitmap, which is then updated to mark the newly-allocated block as used, 
    one to write the bitmap (to reflect its new state to disk), and 
    one to write the actual block itself.
2. The amount of write traffic is even worse when one considers a sim- ple and common operation such as file creation. 
The total amount of I/O traffic to do so is quite high:
    * one read to the inode bitmap (to find a free inode)
    * one write to the inode bitmap (to mark it allocated),
    * one write to the new inode itself (to initialize it)
    * one to the data of the directory (to link the high-level name of the file to its inode number),
    * one read and write to the directory inode to update it
If the directory needs to grow to ac- commodate the new entry, additional I/Os (i.e., to the data bitmap, and the new directory block) will be needed too

**Read the Table 40.4**

# THE CRUX: HOW TO REDUCE FILE SYSTEM I/O COSTS
Even the simplest of operations like opening, reading, or writing a file incurs a huge number of I/O operations, scattered over the disk. What can a file system do to reduce the high costs of doing so many I/Os?


# 40.7 Caching and Buffering
1. most file systems aggressively use system memory (DRAM) to cache important blocks.
2. Early file systems thus introduced a fix-sized cache to hold popular blocks.
3. Modern systems integrate virtual memory pages and file system pages into a unified page cache
4. In this way, memory can be allocated more flexibly across virtual memory and file system, depending on which needs more memory at a given time.
5. write buffering (as it is sometimes called) certainly has a number of per- formance benefits:
    * First, by delaying writes, the file system can batch some updates into a smaller set of I/Os
    * Second, by buffering a number of writes in memory, the system can then schedule the subsequent I/Os and thus increase per- formance.
    * Finally, some writes are avoided altogether by delaying them. for example, if an application creates a file and then deletes it, delaying the writes to reflect the file creation to disk avoids them entirely

6. __For the reasons above, most modern file systems buffer writes in mem- ory for anywhere between five and thirty seconds, representing yet an- other trade-off__:
    * if the system crashes before the updates have been prop- agated to disk, the updates are lost
    * however, by keeping writes in mem- ory longer, performance can be improved by batching, scheduling, and even avoiding writes.

7. Thus, to avoid unexpected data loss due to write buffering, they simply force writes to disk, by calling fsync(), by using direct I/O interfaces that work around the cache, or by using the raw disk interface and avoiding the file system altogether


