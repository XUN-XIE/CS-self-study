个人小想法：
cache 技术的利用层级
CPU 先利用 paging 技术，从 virtual memory 映射到 physical memory。而这里的 physical memory 指的就是 主存？

第一个解释是：
physical memory 是 L1 Cache/ L2 Cache / L3 Cache 更好。因为 L123 Cache 还需要利用 cache 技术 依次向下到 main memory 中！

第二个解释是：
或者？physical memory 指的就是 main memory？然后 利用 cache 技术，现在 L1 Cache 中查询，如果查询不到依次向下 cache miss.

按理看来，应该是 第二个解释的逻辑。只是指向的也不一定是 main memory 还可能是更大的 disk 呢？

#Crux P169
HOW TO VIRTUALIZE MEMORY WITHOUT SEGMENTS

Idea:
Instead of splitting up our address space into three logical segments (each of variable size):
    1. heap
    2. stack
    3. code

1. paging virtual address space:
we split up our address space into __fixed-sized units__ we call a __page__

2. paging in physical address space:
With paging, physical memory is also split into some number of pages as well; we sometimes will call each page of physical __memory a page frame__.

3. advantages of paging compared to segmentation:
    1. the most important improvement will be flexibility
    2. the simplicity of free-space management

4. __the free space management in paging is a little like the free space management learned in last Chapter!__

5. page table:
To record where each virtual page of the address space is placed in physical memory, the operating system keeps a **per-process** data structure known as a __page table__.
The major role of the page table is to store __address translations__ for each of the virtual pages of the address space, thus letting us know where in physical memory they live

6. address translation process:
split virtual address into two components: __virtual page number__(VPN) and offset



# 18.1 Where Are Page Tables Stored?
1. 32-bit address space <--> 4-KB pages <--> 20-bit VPN and 12-bit offset <--> 2^20 virtual pages each process <--> 4 bytes per __page table entry__(PTE) <--> 4MB each page table!
2. store the page table for each process in memory


# 18.2 What’s Actually In The Page Table?
1. page table is just data structure like map
    1. The page table is just a data structure that is used to map virtual addresses (or really, virtual page numbers) to physical addresses (physical page numbers)
    2. The simplest form is called a linear page table, which is just an array. The OS indexes the array by the VPN, and looks up the page-table entry (PTE) at that index in order to find the desired PFN.

2. contents in page table is just a 32-bit number
a number of different bits in there worth understanding at some level.
    1. __valid bit__: common to indicate whether the particular translation is valid. __the valid bit is crucial for supporting a sparse address space__, by simply marking all the unused pages in the address space invalid, we remove the need to allocate physical frames for those pages and thus save a great deal of memory.
    2. __protection bit__: indicating whether the page could be read from, written to, or executed from. 
    3. __present bit__: indicates whether this page is in phys- ical memory or on disk (swapped out)
    4. __dirty bit__: indicating whether the page has been modified since it was brought into memory.
    5. reference bit / accessed bit: used to track whether a page has been accessed, and is useful in determining which pages are popular and thus should be kept in memory. such knowledge is critical during page replacement
  
# 18.3 Paging: Also Too Slow
read code in Figure 18.6 to understand the translation process

reason for consuming large time:
two memory fetches:
    1. fetch proper page table entry from process' page table
    2. fetch the correct physical address (translated from above step)

summary:
1. two problems: large memory consumption and large time consumption
2. subsequent chapters are used to firstly overcome these two problems


# 18.4 A Memory Trace
assumption:
64KB address space size <--> 1KB page size

Analysis:
4000 bytes data --> (nearly equal to) 4KB --> 4 pages to store
64KB address space --> 2^16 bytes --> (nearly equal to) 64000 bytes

I think the translation provided by author is an assumption? follow it

each instruction fetch will generate two memory references:
    1. one to the page table to find the physical frame that the instruction resides within
    2. one to the instruction itself to fetch it to the CPU for processing

Meanwhile, one explicit memory reference in the form of the mov instruction(discussed in Section 18.3)



Three graphs:

1. instruction mempry reference
this shows that, the instruction itself (or namely code) in virtual memory is also need to be translated into physical mempry (see above two memory references in each instruction first point)

2. array accesses
this shows that, only mov instruction are manipulating the array access.
And as we see the x-axis, in each loop, array access happens after other memory access (namely translation between VA and PA)

3. page table memory accesses
this shows that, the code is in PageTable[1], we are nearly always fetch the memory in PageTable[1] because it is code. Otherwise, when we need to access data (array access), we need to access corresponding PageTable.

__10 memory accesses per loop__:
four instructions need eight fetches 
mov instruction need two more fetches



# 18.5 Summary
1. Paging has many advantages over previ- ous approaches (such as segmentation):
    1. First, it does not lead to external fragmentation, as paging (by design) divides memory into fixed-sized units.
    2. Second, it is quite flexible, enabling the sparse use of virtual ad- dress spaces.

2. but there are still two problems in implementing:
    1. time waste (extra memory accesses)
    2. memory waste
