**类似CSAPP Chapter9 后半部分，讲解 malloc 和 free 的实现，怎么管理 heap 的空间**

明确一点：malloc出来的空间，尽管会存在 internal fragmentation，但是其问题不是很大（个人考虑，程序员自己控制 malloc 出来的空间利用率！）。所以只关注 external fragmentation！

# Crux P154
HOW TO MANAGE FREE SPACE
How should free space be managed, when satisfying variable-sized re- quests? 
What strategies can be used to minimize fragmentation? 
What are the time and space overheads of alternate approaches?

# 17.1 Assumptions
1. Note the implication of the interface: the user, when freeing the space, does not inform the library of its size; thus, the library must be able to figure out how big a chunk of memory is when handed just a pointer to it.

2. The space that this library manages is known historically as the heap, and the generic data structure used to manage free space in the heap is some kind of __free list__.

3. __free list__: This structure contains references to all of the free chunks of space in the managed region of memory.

4. We’ll also assume that once memory is handed out to a client, it cannot be relocated to another location in memory. __no compaction of free space is possible, which would be useful to combat fragmentation__

5. assume that the allocator manages a contiguous region of bytes.
    Although a user-level memory-allocation library might call into the kernel to grow the heap (via a system call such as sbrk) when it runs out of space. 
__Assume that the region is a single fixed size throughout its life__.


# 17.2 Low-level Mechanisms

### Splitting and Coalescing
1. A free list contains a set of elements that describe the free space still re- maining in the heap

2. __splitting__: Assume we have a request for just a single byte of memory. In this case, the allocator will perform an action known as __splitting__: it will find a free chunk of memory that can satisfy the request and split it into two.

3. __coalescing__: when returning a free chunk in memory, look carefully at the addresses of the chunk you are returning as well as the nearby chunks of free space; if the newly- freed space sits right next to one (or two, as in this example) existing free chunks, merge them into a single larger free chunk.

### Tracking The Size Of Allocated Regions
1. 为了辅助 free 记录被释放区域的size的结构
    __header__ block: which is kept in memory, usually just before the handed-out chunk of memory.

2. 工作原理！
header 结构本身存储了 malloc 的区域字节大小。
free 时，先利用 传入指针的值（当然表示这一块malloc区域的起始位置） 减去 header 结构的大小（偏移），就能够获取到 header 所在的地址！
然后利用 header 指针获取到 malloc 时放入的 字节大小！
最后调用 system call 释放内存

3. 通过工作原理可以知道一个 implication：malloc 时，在 heap 里寻找的空间并不是 传入的 size。而是 size 加上 header size！！！
**Note the small but critical detail in the last sentence: the size of the free region is the size of the header plus the size of the space allocated to the user. Thus, when a user requests N bytes of memory, the library does not search for a free chunk of size N; rather, it searches for a free chunk of size N plus the size of the header.**

### Embedding A Free List (需要看书中的图理解，很复杂)
问题：free list 本身在 heap 里。但是 free list 又是为 动态内存管理库服务的。这个冲突是如何解决的？


### Growing The Heap
1. Most traditional allocators start with a small-sized heap and then re- quest more memory from the OS when they run out.


# 17.3 Basic Strategies

最后有一个高级的 allocator stategy: slab 
和一个 合并的算法







