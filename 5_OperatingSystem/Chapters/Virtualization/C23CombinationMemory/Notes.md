# Crux P245
HOW TO AVOID THE CURSE OF GENERALITY
    Operating systems often have a problem known as “the curse of gen- erality”, where they are tasked with general support for a broad class of applications and systems.



1. __( issue 1: generality)__ VMS had the general prob- lem that it would be run on a broad range of machines, including very inexpensive VAXen (yes, that is the proper plural) to extremely high-end and powerful machines in the same architecture family.
2. __( issue 2: inherent flaws )__ VMS is an excellent example of software inno- vations used to hide some of the inherent flaws of the architecture.


# 23.2 Memory Management Hardware
1. technique for virtualizing memory: hybrid of paging and segmentation

2. one of the first goals of the VMS designers was to make sure that VMS would not overwhelm memory with page tables. The system reduced the pressure page tables place on memory in two ways:
    * First, by segmenting the user address space into two, the VAX-11 provides a page table for each of these regions (P0 and P1) per process; thus, no page-table space is needed for the unused portion of the address space between the stack and the heap
    * Second, the OS reduces memory pressure even further by placing user page tables (for P0 and P1, thus two per process) in kernel virtual mem- ory. Thus, when allocating or growing a page table, the kernel allocates space out of its own virtual memory, in segment S. If memory comes un- der severe pressure, the kernel can swap pages of these page tables out to disk, thus making physical memory available for other uses.

3. Putting page tables in kernel virtual memory means that address trans- lation is even further complicated.


# 23.3 A Real Address Space
1. One neat aspect of studying VMS is that we can see how a real address space is constructed

### ASIDE: WHY NULL POINTER ACCESSES CAUSE SEG FAULTS
The page table is consulted, and the entry for VPN 0 is found to be marked invalid.
Thus, we have an invalid access, which transfers control to the OS, which likely terminates the process





