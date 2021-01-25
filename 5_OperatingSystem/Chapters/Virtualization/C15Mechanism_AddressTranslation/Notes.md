# Crux P129
HOW TO EFFICIENTLY AND FLEXIBLY VIRTUALIZE MEMORY
How can we build an efficient virtualization of memory? 
How do we provide the flexibility needed by applications? 
How do we maintain control over which memory locations an application can access, and thus ensure that application memory accesses are properly restricted? 
How do we do all of this efficiently?


flexibility: we’d like for programs to be able to use their address spaces in whatever way they would like, thus making the system easier to program.


# 硬件层面（回忆CSAPP Chapter9 中的硬件部分介绍）
__hardware-based address translation__: the hardware transforms each memory access,  changing the vir- tual address provided by the instruction to a physical address where the desired information is actually located.

# OS软件层面
__manage memory__: keeping track of which locations are free and which are in use, and judiciously intervening to maintain control over how memory is used.



# Assumption
1. user ’s address space must be placed contiguously in physical memory
2. size of the address space is not too big; specifically, that it is less than the size of physical memory
3. each address space is exactly the same size



# 15.3 Dynamic (Hardware-based) Relocation
1. base-bound <--> Dynamic Relocation
2. two registers —— base, bound : to limit the physical address the program can access
3. physical address = base + virtual address
4. virtual address < bound
5. bound register 可以有两种形式：要么 check virtual address，要么 check physical address，毕竟意义是等价的


ASIDE: DATA STRUCTURE – THE FREE LIST
__free list__: which simply is a list of the ranges of the physical memory which are not currently in use.


# 15.4 OS Issues(base-bound 如何解决这三个问题！)
1. First, The OS must take action when a process is created, finding space for its address space in memory
    * OS; it can simply view physical memory as an array of slots, and track whether each one is free or in use.
    * When a new process is created, the OS will have to search a data structure (often called a free list) to find room for the new address space and then mark it used.

2. Second, the OS must take action when a process is terminated, reclaim- ing all of its memory for use in other processes or the OS
    * Upon termina- tion of a process, the OS thus puts its memory back on the free list, and cleans up any associated data structures as need be.
3. Third, the OS must also take action when a context switch occurs.
    * OS must save and restore the base-and-bounds pair when it switches between processes. in some per-process structure such as the process structure or process control block (PCB).


# Summary
__this simple technique of dynamic relocation does have its inefficiencies.__:
    * because the process stack and heap are not too big, all of the space between the two is simply wasted. 
    * __internal fragmentation__: as the space inside the allocated unit is not all used (i.e., is fragmented) and thus wasted

所以现在要解决的第一个问题是！internal fragmentation，解决空间的浪费！



