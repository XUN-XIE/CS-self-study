# Crux P141
HOW TO SUPPORT A LARGE ADDRESS SPACE
How do we support a large address space with (potentially) a lot of free space between the stack and the heap?
Imagine, however, a 32-bit address space (4 GB in size); a typical program will only use megabytes of memory, but still would demand that the entire address space be resident in memory.

待解决的问题：一般 virtual memory 是很大的，根据 位数 计算(32 bits 和 64 bits)。因此，如果整个 virtual memory 都放入 physical memory 中，无疑是一种浪费！所以如何更加合理的利用空间？


# 16.1 Segmentation: Generalized Base/Bounds
segmentation: a base and bounds pair per logical segment of the address space

# 16.2 segment 工作原理
1. explicit approach
    二进制方法：头两位决定 三个不同的segment 选取哪一个。后面的位表示 offset，和对应segment 的base 相加，即可得到该 virtual space 的 physical space！
2. implicit approach
    硬件获取信息：如果是 program counter 产生的地址，就是 code segment；如果是 stack or base pointer，就是 stack segment；其他的就是 heap segment


# 16.3 解决 stack 向低地址增长的问题
问题：stack 增长和 heap 还有 code 两个 segment 地址增长的方向不同，因此也需要信息来区分！

为了 获取正确的 stack segment 的 negative offset
方法是： To obtain the correct negative offset, we must subtract the maximum segment size from 3KB

延续 16.2 的计算方式！前两位为选取 segment。之后后面的位数表示 offset，如果是 stack segment，那么就用 该 offset 减去 offset 所能表示的最大值！即可得到 正确的 negative offset！


# 16.4 Support for Sharing
share certain memory segments between address spaces(different processes)
共享代码块！

To support sharing, we need a little extra support from the hardware, in the form of protection bits

通过增加一些特殊位，表达不同的意义，可以让 virtual address 表达更多的功能


# 16.6
其他问题出现了
1. external fragmentation: The general problem that arises is that physical memory quickly be- comes full of little holes of free space, making it difficult to allocate new segments, or to grow existing ones.


**TIP: IF 1000 SOLUTIONS EXIST, NO GREAT ONE DOES**
思想，如果一个问题有1000种解决途径，那么就不可能有好的解决方法。而应该从根本上解决问题或者改变问题！
