# CRUX: HOW TO MAKE A LARGE, FAST, RELIABLE DISK

1. Externally, a RAID looks like a disk: a group of blocks one can read or write.
2. Internally, the RAID is a complex beast, consisting of multiple disks, memory (both volatile and non-), and one or more processors to manage the system.

3. RAIDs offer a number of advantages over a single disk:
    * One advan- tage is performance. Using multiple disks in parallel can greatly speed up I/O times.
    * Another benefit is capacity. Large data sets demand large disks.
    * Finally, RAIDs can improve reliability; spreading data across mul- tiple disks (without RAID techniques) makes the data vulnerable to the loss of a single disk; with some form of redundancy, RAIDs can tolerate the loss of a disk and keep operating as if nothing were wrong.

### TIP: TRANSPARENCY ENABLES DEPLOYMENT
    新技术应该保证（个人理解）接口不变，这样可以使得系统的其他部分不需要为新技术的加入，而改变原有的 code，因此可以提高新技术的普及性


# 38.1 Interface And RAID Internals
1. When a file system issues a logical I/O request to the RAID, the RAID internally must calculate which disk (or disks) to access in order to com- plete the request, and then issue one or more physical I/Os to do so


**RAID 就是一个小型的计算机系统！**
**At a high level, a RAID is very much a special- ized computer system: it has a processor, memory, and disks; however, instead of running applications, it runs specialized software designed to operate the RAID.**


# 38.2 Fault Model
1. RAIDs are designed to detect and recover from certain kinds of disk faults; thus, knowing exactly which faults to expect is critical in arriving upon a working design.

2. The first fault model we will assume is quite simple, and has been called the fail-stop fault model [S84]. In this model, a disk can be in exactly one of two states: working or failed. With a working disk, all blocks can be read or written. In contrast, when a disk has failed, we assume it is permanently lost.

3. One critical aspect of the fail-stop model is what it assumes about fault detection. Specifically, when a disk has failed, we assume that this is easily detected.

4. Thus, for now, we do not have to worry about more complex “silent” failures such as disk corruption. We also do not have to worry about a sin- gle block becoming inaccessible upon an otherwise working disk (some- times called a latent sector error).


# 38.3 How To Evaluate A RAID
1. there are a number of different approaches to building a RAID

2. Specifically, we will evaluate each RAID design along three axes:
    1. The first axis is capacity.
    2. The second axis of evaluation is reliability.
    3. Finally, the third axis is performance.





