write performance
注意，LFS系统和前面的系统 format assumption 不一样！之前是 inode，imap，data 堆在一起顺序排放
但是 LFS 系统改变了 format 才能实现 wite performance
因此，前面考虑的其他内部问题，都要重新考虑，比如 crash consistency

1. An ideal file system would thus focus on write performance, and try to make use of the sequential bandwidth of the disk.
2. Further, it would perform well on common workloads that not only write out data but also update on-disk metadata structures frequently. Finally, it would work well on RAIDs as well as single disks.


3. The new type of file system Rosenblum and Ousterhout introduced was called LFS, short for the Log-structured File System. When writ- ing to disk, LFS first buffers all updates (including metadata!) in an in- memory segment; when the segment is full, it is written to disk in one long, sequential transfer to an unused part of the disk, i.e., LFS never overwrites existing data, but rather always writes segments to free loca- tions. Because segments are large, the disk is used efficiently, and perfor- mance of the file system approaches its zenith.

# THE CRUX:
HOW TO MAKE ALL WRITES SEQUENTIAL WRITES?
How can a file system turns all writes into sequential writes? For reads, this task is impossible, as the desired block to be read may be any- where on disk. For writes, however, the file system always has a choice, and it is exactly this choice we hope to exploit.


# TIP: DETAILS MATTER
All interesting systems are comprised of a few general ideas and a
number of details. Sometimes, when you are learning about these sys- tems, you think to yourself “Oh, I get the general idea; the rest is just de- tails,” and you use this to only half-learn how things really work. Don’t do this! Many times, the details are critical. As we’ll see with LFS, the general idea is easy to understand, but to really build a working system, you have to think through all of the tricky cases.


# 43.2 Writing Sequentially And Effectively
1. you must issue a large number of contiguous writes (or one large write) to the drive in order to achieve good write performance.

2. To achieve this end, LFS uses an ancient technique known as write buffering1. Before writing to the disk, LFS keeps track of updates in memory; when it has received a sufficient number of updates, it writes them to disk all at once, thus ensuring efficient use of the disk

3. The large chunk of updates LFS writes at one time is referred to by the name of a segment. Although this term is over-used in computer systems, here it just means a large-ish chunk which LFS uses to group writes. Thus, when writing to disk, LFS buffers updates in an in-memory segment, and then writes the segment all at once to the disk. As long as the segment is large enough, these writes will be efficient.


# 43.3 How Much To Buffer?
1. crucial factor: how high the positioning overhead is in comparison to the transfer rate
2. The way to think about this is that every time you write, you pay a fixed overhead of the positioning cost. Thus, how much do you have to write in order to amortize that cost? The more you write, the better (obviously), and the closer you get to achieving peak bandwidth.


# 43.4 Problem: Finding Inodes
1. Finding an inode given an inode number in FFS is only slightly more complicated, because FFS splits up the inode table into chunks and places a group of inodes within each cylinder group. Thus, one must know how big each chunk of inodes is and the start addresses of each. After that, the calculations are similar and also easy.

2. In LFS, life is more difficult. Why? Well, we’ve managed to scatter the inodes all throughout the disk! Worse, we never overwrite in place, and thus the latest version of an inode (i.e., the one we want) keeps moving.


# 43.5 Solution Through Indirection: The Inode Map
1. To remedy this, the designers of LFS introduced a level of indirection between inode numbers and the inodes through a data structure called the inode map (imap).
2.  The imap is a structure that takes an inode number as input and produces the disk address of the most recent version of the inode.

# Summary
1. LFS introduces a new approach to updating the disk. Instead of over- writing files in places, LFS always writes to an unused portion of the disk, and then later reclaims that old space through cleaning. This ap- proach, which in database systems is called shadow paging [L77] and in file-system-speak is sometimes called copy-on-write
2. enables highly effi- cient writing, as LFS can gather all updates into an in-memory segment and then write them out together sequentially.

3. The downside to this approach is that it generates garbage; old copies of the data are scattered throughout the disk, and if one wants to reclaim such space for subsequent usage, one must clean old segments periodi- cally. Cleaning became the focus of much controversy in LFS, and concerns over cleaning costs

# TIP: TURN FLAWS INTO VIRTUES
Whenever your system has a fundamental flaw, see if you can turn it around into a feature or something useful. NetApp’s WAFL does this with old file contents; by making old versions available, WAFL no longer has to worry about cleaning, and thus provides a cool feature and re- moves the LFS cleaning problem all in one wonderful twist.
