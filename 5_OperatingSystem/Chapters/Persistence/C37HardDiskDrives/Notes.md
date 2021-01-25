# Crux HOW TO STORE AND ACCESS DATA ON DISK
How do modern hard-disk drives store data? 
What is the interface? 
How is the data actually laid out and accessed? 
How does disk scheduling improve performance?


# 37.3 A Simple Disk Drive

### Single-track Latency: The Rotational Delay
__rotational delay__:
it must just wait for the desired sector to rotate under the disk head. This wait happens often enough in modern drives, and is an important enough component of I/O service time

### Multiple Tracks: Seek Time
__seek__: 
To service this read, the drive has to first move the disk arm to the correct track

**Seeks, along with rotations, are one of the most costly disk operations.**

seek process:
    1. acceleration
    2. coasting
    3. deceleration
    4. __settling time__: often quite significant, e.g., 0.5 to 2 ms, as the drive must be certain to find the right track


process to read data from hard disk:
    1. seek (to get correct track)
    2. rotate (to get the correct block)
    3. transfer (to get data from the block)

### Some Other Details
1. __track skew__ to make sure that sequential reads can be properly serviced even when crossing track boundaries
个人理解：就是整个扇区是 倾斜的，保证从一个 track 的最后一个 block 结束时，切换到下一个 track 的 start block！！！因此可以 顺序的读取！

2. 外圈的 track 比内圈 track 有更多的 sectors. 更多的空间

3. track buffer. 对读取和写入作一个缓存

4. write back 和 write through。选择何时把缓存中的数据写入到磁盘中


# 37.4 I/O Time: Doing The Math

### TIP: USE DISKS SEQUENTIALLY
1. When at all possible, transfer data to and from disks in a sequential man- ner.
2. If sequential is not possible, at least think about transferring data in large chunks: the bigger, the better.


# 37.5 Disk Scheduling
By estimating the seek and possible the rotational delay of a request, the disk scheduler can know how long each request will take

### SSTF: Shortest Seek Time First
idea: 
    SSTF orders the queue of I/O requests by track, picking requests on the nearest track to complete first.

Disadvantage:
    1. First, the drive geometry is not available to the host OS; rather, it sees an array of blocks. Fortunately, this problem is rather easily fixed. Instead of SSTF, an OS can simply implement nearest-block-first (NBF), which schedules the request with the nearest block address next.
    (没搞懂这个问题什么意思)2. The second problem is more fundamental: starvation. ??? 内圈track。忽略请求？

# CRUX: HOW TO HANDLE DISK STARVATION

### Elevator (a.k.a. SCAN or C-SCAN) 没弄懂
idead: 先整体扫描一便 disk ？
     simply moves across the disk servicing requests in order across the tracks. 
      if a request comes for a block on a track that has already been serviced on this sweep of the disk, it is not handled immediately, but rather queued until the next sweep.


### SPTF: Shortest Positioning Time First
Idea: 
    比较 seek 和 ratate 时间，决定选取 track 近但是 rotate 远 还是 track 近 但是 rotate 近 的block

However, it is even more difficult to implement in an OS, which generally does not have a good idea where track boundaries are or where the disk head currently is (in a rotational sense). Thus, SPTF is usually performed inside a drive, described below.

