Overcome first problem: large memory wasted

Software: Multi-level Paging

#Crux P201
CRUX: HOW TO MAKE PAGE TABLES SMALLER?

## ASIDE: MULTIPLE PAGE SIZES
As an aside, do note that many architectures (e.g., MIPS, SPARC, x86-64) now support multiple page sizes. Usually, a small (4KB or 8KB) page size is used.

Database system
This type of large page usage is common in database management systems and other high-end commercial applications. The main reason for multiple page sizes is not to save page table space, however; it is to reduce pressure on the TLB, enabling a program to access more of its ad- dress space without suffering from too many TLB misses.

# 20.2 Hybrid Approach: Paging and Segments
1. three page tables, one for the code, heap, and stack parts of the address space.

2. remember with segmentation, we had a base register that told us where each segment lived in physical memory, and a bound or limit register that told us the size of said segment
3. we use the base not to point to the segment itself but rather to hold the physical address of the page table of that segment. The bounds register is used to indicate the end of the page table (i.e., how many valid pages it has).

4. The critical difference in our hybrid scheme is the presence of a bounds register per segment; each bounds register holds the value of the maxi- mum valid page in the segment


Problems:
    * not flexiblity: First, it still requires us to use segmentation; as we discussed before, seg- mentation is not quite as flexible as we would like, as it assumes a certain usage pattern of the address space; if we have a large but sparsely-used heap, for example, we can still end up with a lot of page table waste.
    * Second, this hybrid causes external fragmentation to arise again


# 20.3 Multi-level Page Tables
1. __multi-level page table__, as it turns the linear page table into something like a tree.

2. The basic idea behind a multi-level page table is simple:
    * First, chop up the page table into page-sized units;
    *  then, if an entire page of page-table entries (PTEs) is invalid, don’t allocate that page of the page table at all.
   
3. To track whether a page of the page table is valid (and if valid, where it is in memory), use a new structure, called the __page directory__.

4. The page directory, in a simple two-level table, contains one entry per page of the page table. It consists of a number of __page directory entries (PDE)__.

5. A PDE (minimally) has a valid bit and a page frame number (PFN), similar to a PTE.

6. ( valid bit 代表了这个 page table directory 指向的下一级 page 里是否有 valid pages )the meaning of this valid bit is slightly different: if the PDE entry is valid, it means that at least one of the pages of the page table that the entry points to (via the PFN) is valid, i.e., in at least one PTE on that page pointed to by this PDE, the valid bit in that PTE is set to one. If the PDE entry is not valid (i.e., equal to zero), the rest of the PDE is not defined.


7. Advantages:
    * First, and perhaps most obviously, the multi-level ta- ble only allocates page-table space in proportion to the amount of address space you are using; thus it is generally compact and supports sparse ad- dress spaces.
    * (可以方便的开辟新的内存，因为线性 page table 只能连续的映射到 physical space。但是多级 paging 可以改变) Second, if carefully constructed, each portion of the page table fits neatly within a page, making it easier to manage memory; the OS can simply grab the next free page when it needs to allocate or grow a page table. 


8. Disadvantages:
    * cost: TLB miss need more loads (time-space trade-off)
    * complexity: we make page-table lookups more complicated in order to save valuable memory.




###    Example
16KB address space (2^14 bytes) <--> 64-byte pages <--> 14-bit virtual space address space <--> 8-bit VPN and 6-bit offset

if linear page table, 2^8 entries

if two-level page table:
assume 4 bytes PTE --> 256 * 4 (2^10) bytes page table
1KB page table --> 16 * 64-byte pages --> 
total 256 个 pages  --> 16 * 1KB page table = 16 KB address space --> 16 page directory and each have 16 pages --> 16 * 16 * 64 bytes page = 2^14 bytes (16KB) address space! 

solve the index:
16 pages directories --> top 4 bits to index (Page Directory Index)
each directori have 16 entry --> middle 4 bits to index (Page Table Index)
64 bytes page --> low 6 bits to index (offset)


### More Than Two Levels
30-bit virtual address space <--> 512 bytes page <--> 21-bit VPN and 9-bit offset

### The Translation Process: Remember the TLB
read code in Figure 20.4

it shows that, when the level increase, the nested condition code is also increasing because of TLB miss!




# 20.4 Inverted Page Tables
1. An even more extreme space savings in the world of page tables is found with inverted page tables.

2. Here, instead of having many page tables (one per process of the system), we keep a single page table that has an entry for each physical page of the system. The entry tells us which process is using this page, and which virtual page of that process maps to this physical page.

3. Finding the correct entry is now a matter of searching through this data structure.  a hash table is often built over the base structure to speed lookups

# All is data structure and algorithm!
4. More generally, inverted page tables illustrate what we’ve said from the beginning: page tables are just data structures. You can do lots of crazy things with data structures, making them smaller or bigger, making them slower or faster. Multi-level and inverted page tables are just two examples of the many things one could do.

# 20.5 Swapping the Page Tables to Disk
Even with our many tricks to reduce the size of page tables, it is still possible, however, that they may be too big to fit into memory all at once. Thus, some systems place such page tables in kernel virtual memory, thereby allowing the system to swap some of these page tables to disk when memory pressure gets a little tight.


# Summary
1. __(format is just data structure, and we can change it)__ We have now seen how real page tables are built; not necessarily just as linear arrays but as more complex data structures.

2. __(choice of design is just trade-off!)__ The trade-offs such tables present are in time and space – the bigger the table, the faster a TLB miss can be serviced, as well as the converse – and thus the right choice of structure depends strongly on the constraints of the given environment.

3. __(no best, just select the most appropriate choice)__ In a memory-constrained system (like many older systems), small struc- tures make sense; in a system with a reasonable amount of memory and with workloads that actively use a large number of pages, a bigger ta- ble that speeds up TLB misses might be the right choice.


