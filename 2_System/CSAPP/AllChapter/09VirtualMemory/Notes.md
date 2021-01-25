# 9.3.6 多级页表
计算书中叙述的字节大小，一一对应其概念

32 bits space,  4KB = 2^12 pages.   4-byte PTE
32 bits space && 4KB pages --> 20 bits 个 PTE
2^20 个 PTE && 4-byte PTE --> 2^24 = 4MB page table

一个PTE == 一个 page ？

第一级 1024 个 PTE，
第一级一个PTE 对应 第二级1024个PTE
第二级一个PTE对应虚拟内存一个 page

一个一级PTE = 1024 * 4KB = 4 MB
所有一级PTE = 1024 * 4MB = 4GB


# 9.9.3
free 后的指针要自己显示的 设置为 NULL
因为 free 后，调用那个指针，那个对应的内存位置的数据还是原来的
所以 只有自己 显示的 设置指针为NULL，才能防止，自己不小心调用 free 后的指针，索引到不应该存在的数据！
**回忆，自己做第六章，矩阵乘法，写的代码，为什么第二次会累加在原来的数据上！**


# 9.9 Dynamic Memory Allocation
1. For each process, the kernel maintains a variable __brk__ (pronounced “break”) that points to the top of the heap.
2. Allocators come in two basic styles. Both styles require the application to explicitly allocate blocks. They differ about which entity is responsible for freeing allocated blocks.
    * . Explicit allocators require the application to explicitly free any allocated blocks.
    * . Implicit allocators, on the other hand, require the allocator to detect when an allocated block is no longer being used by the program and then free the block. Implicit allocators are also known as garbage collectors, and the process of automatically freeing unused allocated blocks is known as garbage collection.

### 9.9.3 Allocator Requirements and Goals
Explicit allocators must operate within some rather stringent constraints:
    1. Handling arbitrary request sequences.
    2. Making immediate responses to requests.
    3. Using only the heap. In order for the allocator to be scalable, any nonscalar data structures used by the allocator must be stored in the heap itself.
    4. Allocators can only manipulate or change free blocks. In particular, __they are not allowed to modify or move blocks once they are allocated__. Thus, techniques such as compaction of allocated blocks are not permitted.

Goal one: Maximizing throughput.
Goal two: Maximizing memory utilization.
there is a tension between maximizing throughput and utilization.


### 9.9.4 Fragmentation
1. __Internal fragmentation__ occurs when an allocated block is larger than the pay-load
    cause one: alignment constraints
    cause two: minimum allocated size is larger than requested size
2. the amount of internal fragmentation depends only on the pattern of previous requests and the allocator implementation.

3. __External fragmentation__ occurs when there is enough aggregate free memory to satisfy an allocate request, but no single free block is large enough to handle the request.
4. External fragmentation is much more difficult to quantify than internal frag- mentation because it depends not only on the pattern of previous requests and the allocator implementation but also on the pattern of future requests.


### 9.9.5 Implementation Issues
A practical allocator that strikes a better balance between throughput and utilization must consider the following issues:
    * Free block organization. How do we keep track of free blocks?
    * Placement. How do we choose an appropriate free block in which to place a newly allocated block?
    * Splitting. After we place a newly allocated block in some free block, what do we do with the remainder of the free block?
    * Coalescing. What do we do with a block that has just been freed?


### 9.9.6 Implicit Free Lists
    **不同于 操作系统导论 中的 显示 free list，这里的 __隐式__ free list 是用 一个 四字节 的小块！(32 bits) 表示该 块 的大小，已经分配与否的信息！
1. Any practical allocator needs some data structure that allows it to distinguish block boundaries and to distinguish between allocated and free blocks
2. In this case, a block consists of a one-word header, the payload, and possibly some additional padding.


### 9.9.10 Coalescing Free Blocks
Immediate coalescing is straightforward and can be performed in constant time, but with some request patterns it can introduce a form of thrashing where a block is repeatedly coalesced and then split soon thereafter.

**you should be aware that fast allocators often opt for some form of deferred coalescing.**


# 9.9.12 Putting It Together: Implementing a Simple Allocator


# 9.10 Garbage Collection ( Graph algorithm )
1. A garbage collector is a dynamic storage allocator that automatically frees al- located blocks that are no longer needed by the program
2. The process of automatically reclaiming heap storage is known as garbage collection.
3. It is an important part of modern language systems such as Java, ML, Perl, and Mathematica, and it remains an active and important area of research.
4. **(可以实现 C/C++ 中的malloc变为 自动管理heap！)We will limit our discussion to McCarthy’s original Mark&Sweep al- gorithm, which is interesting because it can be built on top of an existing malloc package to provide garbage collection for C and C++ programs.**


### 9.10.1 Garbage Collector Basics
1. The role of a garbage collector is to maintain some representation of the reachability graph and periodically reclaim the unreachable nodes by freeing them and returning them to the free list.



# 9.11 Common Memory-Related Bugs in C Programs


