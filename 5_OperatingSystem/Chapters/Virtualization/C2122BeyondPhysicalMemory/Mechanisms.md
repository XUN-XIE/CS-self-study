# Crus P217
THE CRUX: HOW TO GO BEYOND PHYSICAL MEMORY
How can the OS make use of a larger, slower device to transparently pro- vide the illusion of a large virtual address space?

multiprogramming need swap out pages and demand all pages stored at once
 The invention of multiprogramming (running multi- ple programs “at once”, to better utilize the machine) almost demanded the ability to swap out some pages, as early machines clearly could not hold all the pages needed by all processes at once.


# 21.1 Swap Space
 1. __swap space__: reserve some space on the disk for moving pages back and forth. 
 2. Thus, we will simply assume that the OS can read from and write to the swap space, in page-sized units. To do so, the OS will need to remember the disk address of a given page.

 3. The size of the swap space is important, as ultimately it determines the maximum number of memory pages that can be in use by a system at a given time.

 4. when process need page, it will request it from swap space to swap into memory!

 5. We should note that swap space is not the only on-disk location for swapping traffic. For example, assume you are running a program binary (e.g., ls, or your own compiled main program). The code pages from this binary are initially found on disk, and when the program runs, they are loaded into memory

# 21.2 The Present Bit
 1. Specifically, when the hardware looks in the PTE, it may find that the page is not present in physical memory. 

 2. The way the hardware (or the OS, in a software-managed TLB approach) deter- mines this is through a new piece of information in each page-table entry, known as the __present bit__.

3. If the present bit is set to one, it means the page is present in physical memory and everything proceeds as above; if it is set to zero, the page is not in memory but rather on disk somewhere.

4. __page fault__: The act of accessing a page that is not in physical memory

5. Upon a page fault, the OS is invoked to service the page fault. A partic- ular piece of code, known as a page-fault handler, runs, and must service the page fault


# 21.3 The Page Fault
1. If a page is not present and has been swapped to disk, the OS will need to swap the page into memory in order to service the page fault.
2. the OS could use the bits in the PTE normally used for data such as the PFN of the page for a disk address
3. When the disk I/O completes, the OS will then update the page table to mark the page as present, update the PFN field of the page-table entry (PTE) to record the in-memory location of the newly-fetched page, and retry the instruction.
    This next attempt may generate a TLB miss, which would then be serviced and update the TLB with the translation (one could alternately update the TLB upon when servicing the page fault,
            Finally, a last restart would find the translation in the TLB and thus proceed to fetch the desired data or instruction from memory at the translated physical address.

4. (concepts in virtualizing CPU) Note that while the I/O is in flight, the process will be in the blocked state. Thus, the OS will be free to run other ready processes while the page fault is being serviced. Because I/O is expensive, this overlap of the I/O (page fault) of one process and the execution of another is yet another way a multiprogrammed system can make the most effective use of its hardware.


# 21.4 What If Memory Is Full?
1. The process of picking a page to kick out, or replace is known as the __page-replacement policy__.


# 21.5 Page Fault Control Flow
1. hardware control flow: three important cases to understand when a TLB miss occurs.
    * First, that the page was both present and valid; the TLB miss handler can simply grab the PFN from the PTE, retry the instruction (this time resulting in a TLB hit), and thus continue as described (many times) before.
    * In the second case, the page fault handler must be run; although this was a legitimate page for the process to access (it is valid, after all), it is not present in physical memory.
    * Third (and finally), the access could be to an invalid page, due for example to a bug in the program (Lines 13–14). In this case, no other bits in the PTE really matter; the hardware traps this invalid access, and the OS trap handler runs, likely terminating the offending process.

2. software control flow: 
    * First, the OS must find a physical frame for the soon-to-be-faulted-in page to reside within; 
    * if there is no such page, we’ll have to wait for the replacement algorithm to run and kick some pages out of memory, thus freeing them for use here.
    * With a physical frame in hand, the handler then issues the I/O request to read in the page from swap space.
    * Finally, when that slow operation completes, the OS updates the page table and retries the instruction. The retry will result in a TLB miss, and then, upon another retry, a TLB hit, at which point the hardware will be able to access the desired item.


# 21.6 When Replacements Really Occur
some points to speed up

keep some pages in memory free
1. To keep a small amount of memory free, most operating systems thus have some kind of high watermark (H W ) and low watermark (LW ) to help decide when to start evicting pages from memory. 
How this works is as follows: when the OS notices that there are fewer than LW pages avail- able, a background thread that is responsible for freeing memory runs. The thread evicts pages until there are HW pages available. The back- ground thread, sometimes called the swap daemon or page daemon1, then goes to sleep, happy that is has freed some memory for running pro- cesses and the OS to use.


cluster/group process I/O
1. By performing a number of replacements at once, new performance optimizations become possible.
2. many systems will cluster or group a number of pages and write them out at once to the swap parti- tion, thus increasing the efficiency of the disk [LL82]

background paging thread
To work with the background paging thread, the control flow in Figure 21.3 should be modified slightly; instead of performing a replacement directly, the algorithm would instead simply check if there are any free pages available. If not, it would signal that the background paging thread that free pages are needed; when the thread frees up some pages, it would re-awaken the original thread, which could then page in the desired page and go about its work.

# TIP: DO WORK IN THE BACKGROUND
1. __When you have some work to do, it is often a good idea to do it in the background to increase efficiency and to allow for grouping of opera- tions.__
2. Operating systems often do work in the background


