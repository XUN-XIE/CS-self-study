# 6.2 Localoty
1. 时间局部性(temporal locality): 同一内存位置，多次引用
2. 空间局部性(spatial locality): 如果某一内存位置被引用，之后引用其附近的位置
**这个内存并不局限，可以是 register, cache, main memory, 按照内存结构依次顺排**
3. stride-1 reference pattern 是程序空间局部性的常见和重要来源(最高效的使用了相邻位置)
4. C 的二维数组以行为优先， row-major matrix

# 6.2.2 instruction(program)-level locality
1. 循环体具有良好的空间局部性
2. 程序和数据有一个重要区别！程序(指令)只会从内存读出，很少会被CPU写入或修改

# 6.2.3 summary of locality
* Programs that repeatedly reference the same variables enjoy good temporal locality.
* For programs with stride-k reference patterns, the smaller the stride, the better the spatial locality. Programs with stride-1 reference patterns have good spatial locality. Programs that hop around memory with large strides have poor spatial locality.
* Loops have good temporal and spatial locality with respect to instruction fetches. The smaller the loop body and the greater the number of loop it- erations, the better the locality.


# 6.3 The Memory Hierarchy
1. fundamental and enduring properties of storage technology and computer software:
    * Storage technology. Different storage technologies have widely different access times. Faster technologies cost more per byte than slower ones and have less capacity. The gap between CPU and main memory speed is widening.
    * Computer software. Well-written programs tend to exhibit good locality.
2. 第一节中提到的， SRAM一般存在于 CPU 芯片上或者内部(L1 and L2 cache in CPU, L3 cache on chip); DRAM 一般对应于主存(main memory). 之后才是电脑的本地硬盘(回忆SRAM和DRAM的工作机制，不通电时，两者内部不具有存储的功能！)
3. 拓展出本地电脑，在本地硬盘之后的存储结构，可以是网络文件系统或其他外部更大的文件系统！
**上下层内存结构中数据的传输形式**
4. the general concept of caching in a memory hierarchy. The storage at level k + 1 is partitioned into contiguous chunks of data objects called blocks. Each block has a unique address or name that distinguishes it from other blocks. Blocks can be either fixed size (the usual case) or variable size
5. Data are always copied back and forth between level k and level k + 1 in block-size transfer units. It is important to realize that while the block size is fixed between any particular pair of adjacent levels in the hierarchy, other pairs of levels can have different block sizes.
6. cache hits and cache misses
7. if cache misses and there are not empty space to store the new request, then cache replace
**different kinds of cache misses**
8. cold cache --> compulsory miss or cold miss. This happens when you firstly run the program on computer
    conflict miss --> 某些对象因为同时映射到上层存储中的同一位置，在交替引用这些对象时，导致的每次miss
    capacity miss --> 数组太大，导致工作集超过缓存大小

# 6.3.2 summary of memory hierarchy
1. To summarize, memory hierarchies based on caching work because slower storage is cheaper than faster storage and because programs tend to exhibit locality:
    Exploitingtemporallocality. Becauseoftemporallocality,thesamedataobjects are likely to be reused multiple times. Once a data object has been copied into the cache on the first miss, we can expect a number of subsequent hits on that object. Since the cache is faster than the storage at the next lower level, these subsequent hits can be served much faster than the original miss.
    Exploitingspatiallocality. Blocksusuallycontainmultipledataobjects.Because of spatial locality, we can expect that the cost of copying a block after a miss will be amortized by subsequent references to other objects within that block.


# 6.4 Cache Memories
### 6.4.1 Generic Cache Memory Organization
1. terminology
    M: address set
    m = s + t + b
    S: cache set
    s
    E: cache line
    B: block
    b
    t: tag bit
    valid bit
    C: capacity = S * E * B
2. 高速缓存的查找机制参考 哈希表 的应用！separate chaining (hash with linked list) to hanld with collision

### 6.4.2 Direct-Mapped Caches
1. E = 1 --> direct-mapped cache
2. request in cache need three steps:
    (1) set selection,      (s)
    (2) line matching,      (t)
    (3) word extraction.    (b)
3. **可以理解为没有任何冲突的情况(因为不需要在每个哈希函数计算出的位置进行遍历链表)**
4. 阅读 Figure 6.30 理解地址如何转化为 valid bit -- tag bits(t) -- index bits(s) -- block bits(b)
5. **一个块(block) 可以储存多个数据！利用 b 在块中的偏移量即可实现定位**

**Conflict Misses in Direct-Mapped Caches Example**
使用填充(padding)解决 两个连续数组的每个对应元素，恰好映射到同一 set 上(因此每次交替索引都是 conflict miss)

**why index with the midlle bits?**
If the high-order bits are used as an index, then some contiguous memory blocks will map to the same cache set. If a program has good spatial locality and scans the elements of an array sequentially, then the cache can only hold a block-size chunk of the array at any point in time. This is an inefficient use of the cache. Contrast this with middle-bit indexing, where adjacent blocks always map to different cache sets. In this case, the cache can hold an entire C-size chunk of the array, where C is the cache size.
**结合题6.11理解，如果前四个元素都映射到同一个set，那么每次遍历都会发生cache miss!**

### 6.4.3 Set Associative Caches
1. 1 < E < C/B
2. **理解为 哈希表 中每个 位置，都有一个separate chainning 的链表！**

### 6.4.4 Fully Associative Caches
1. S = 1, E = C/B
2. **理解为只有一个哈希位置的哈希表 --> 就是一个链表**
3. Because the cache circuitry must search for many matching tags in parallel, it is difficult and expensive to build an associative cache that is both large and fast. As a result, fully associative caches are only appropriate for small caches, such as the translation lookaside buffers (TLBs) in virtual memory systems that cache page table entries (Section 9.6.2).

### 6.4.5 Issues with Writes
1. **读取依次向下request，写入依次向下 修改？**
2. when write hits --> write-through or write-back
3. when write miss --> write-allocate or not write-allocate
4. just kepp in mind we apply the combination of write-back and write-allocate model when we write efficient code
5. As a rule, caches at lower levels of the memory hierarchy are more likely to use write- back instead of write-through because of the larger transfer times.
6. as logic densities increase, the increased complexity of write-back is becoming less of an impediment and we are seeing write-back caches at all levels of modern systems.
7.  Another reason for assuming a write-back, write-allocate approach is that it is symmetric to the way reads are handled, in that write-back write-allocate tries to exploit locality. Thus, we can develop our programs at a high level to exhibit good spatial and temporal locality rather than trying to optimize for a particular memory system.

### 6.4.6 Anatomy of a Real Cache Hierarchy
1. i-cache (only instruction)   for L1 cache
2. d-cache (only data)          for L2 cache
3. unified-cache (both of them) for L3 cache

### 6.4.7 Performance Impact of Cache Parameters
1. Cache performance is evaluated with a number of metrics:
    Miss rate
    hit rate
    hit time
    miss penalty
2. impact of size of cache: high hit rate; but high hit time
3. impact of size of block: high hit rate; for a given cache size, larger blocks imply a smaller number of cache lines, which can hurt the hit rate in programs with more temporal locality than spatial locality; high miss penalty
4. impact of size of E: big E --> low miss rate; high E --> high space cost and time cost; high E --> high hit time; high E --> high miss penalty
the selection of E si the trade-off between hit time and hit penalty.
5. write-back need less transfer. 当储存结构向下走， 传送时间增加，减少传送数量变得更重要，因此下层结构更应当使用 write-back


# 6.5 Writing Cache-Friendly Code
1. basic approach we use to try to ensure that our code is cache friendly.
    1. **(关注大量使用的核心函数中的重点循环！)** Make the common case go fast. Programs often spend most of their time in a few core functions. These functions often spend most of their time in a few loops. So focus on the inner loops of the core functions and ignore the rest.
    2. **(减少 hit misses 的发生)** Minimize the number of cache misses in each inner loop.All other things being equal, such as the total number of loads and stores, loops with better miss rates will run faster.
2. two important points about writing cache-friendly code:
    * Repeated references to local variables are good because the compiler can cache them in the register file (temporal locality).
    * Stride-1 reference patterns are good because caches at all levels of the memory hierarchy store data as contiguous blocks (spatial locality).


# 6.6 Combination
### 6.6.1 The Memory Mountain
1. 即使时间局部性很差，空间局部性也可以补救

### 6.6.2 reorder the loop structure to improve spatial locality
1. **matrix multiplication with best spatial locality**
```
// C = A B
for (k = 0; k < n; k++)
    for (i = 0; i < n; i++)
    {
        r = A[i][k];
        for (j = 0; j < n; j++)
            C[i][j] += r * B[k][j];
    }
```
内循环中，B和C每次都是同一行向右进行移动！因此具有空间局部性(前提是C的写入操作，占用的 set 和 line 不会重置 刚发生的 B 读取操作！)
算法理解，最内部是 **按行扫描** B和C. A中的i，j和B中的i，j对应的意义不一致，行列区分

# 水平暂时不够，还不能复现 C 中的矩阵(二维数组形式) 写出算法，进行对比！



