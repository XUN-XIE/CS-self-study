solve the problem about allocation policy

# 41.1 The Problem: Poor Performance
1. The main issue was that the old UNIX file system treated the disk like it was a random-access memory; data was spread all over the place without regard to the fact that the medium holding the data was a disk, and thus had real and expensive positioning costs.

2. Worse, the file system would end up getting quite fragmented, as the free space was not carefully managed. The free list would end up point- ing to a bunch of blocks spread across the disk, and as files got allocated, they would simply take the next free block. The result was that a logi- cally contiguous file would be accessed by going back and forth across the disk, thus reducing performance dramatically.

3. One other problem: the original block size was too small (512 bytes). Thus, transferring data from the disk was inherently inefficient. Smaller blocks were good because they minimized internal fragmentation (waste within the block), but bad for transfer as each block might require a posi- tioning overhead to reach it.

# THE CRUX: HOW TO ORGANIZE ON-DISK DATA TO IMPROVE PERFORMANCE
How can we organize file system data structures so as to improve per- formance? What types of allocation policies do we need on top of those data structures? How do we make the file system “disk aware”?


# 41.2 FFS: Disk Awareness Is The Solution
1.  The idea was to design the file system structures and allocation policies to be “disk aware” and thus improve performance

Virtually all modern file systems adhere to the ex- isting interface (and thus preserve compatibility with applications) while changing their internals for performance, reliability, or other reasons.


# 41.3 Organizing Structure: The Cylinder Group
1. The first step was to change the on-disk structures.
2. FFS divides the disk into a bunch of groups known as cylinder groups (some modern file systems like Linux ext2 and ext3 just call them block groups)

3. (解决局部性问题) by placing two files within the same group, FFS can ensure that accessing one after the other will not result in long seeks across the disk.

4. components of a cylinder group：
    * A copy of the super block (S) is found in each group for reliability reasons (e.g., if one gets corrupted or scratched, you can still mount and access the file system by using one of the others).
    * (bitmap 解决 fragmentation 问题) The inode bitmap (ib) and data bitmap (db) track whether each inode or data block is free, respectively. Bitmaps are an excellent way to manage free space in a file system because it is easy to find a large chunk of free space and allocate it to a file, perhaps avoiding some of the fragmentation problems of the free list in the old file system.
    * Finally, the inode and data block regions are just like in the previous very simple file system.


# 41.4 Policies: How To Allocate Files and Directories
1. The basic mantra is simple: keep related stuff together (and its corol- lary, keep unrelated stuff far apart).

2. The first is the placement of directories. FFS employs a simple ap- proach: find the cylinder group with a low number of allocated directo- ries (because we want to balance directories across groups) and a high number of free inodes (because we want to subsequently be able to allo- cate a bunch of files), and put the directory data and inode in that group.

3. For files, FFS does two things：
    * First, it makes sure (in the general case) to allocate the data blocks of a file in the same group as its inode, thus preventing long seeks between inode and data
    * Second, it places all files that are in the same directory in the cylin- der group of the directory they are in.


