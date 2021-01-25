Overcome first problem: large time consumption caused by wasted fetches

Hardware aspect: TLB

#Crux P183
HOW TO SPEED UP ADDRESS TRANSLATION


__translation-lookaside buffer__(TLB): part of the chip’s __memory-management unit__ (MMU), and is simply a hardware __cache__ of popular virtual-to-physical address translations; thus, a better name would be an __address-translation cache__.


# 19.1 TLB Basic Algorithm
read code in Figure 19.1 control flow algorithm

miss the knowledge cache in CSAPP(chapter 6)
TLB hit
TLB miss


# 19.2 Example: Accessing An Array
10 integers in memory <--> 40 bytes <--> starting at virtual address 100 <--> 8-bit virtual address space(256 bytes) <--> 16-byte page <--> 4-bit VPN and 4-bit offset

Analysis:
some similar concepts in CSAPP(charpter 6)
hit rate
spatial locality
temporal locality


# 19.3 Who Handles The TLB Miss?
1. Two answers are possible: the hardware, or the software (OS).
2. old time when CISC is used, the hardware take account of the TLB miss
3. Modern architectures (RISC) make use of OS to handle the TLB miss
4. hardware send exception when TLB miss, and the OS pause the current process to jump to trap handler (OS).

some details to note:
1. return-from-trap instruction __(this is the concept in CSAPP chapter 8)__. some return-from-trap jump to next instruction after handling exception, but others need to rerun the current instruction after that.

2. (prevent TLB miss infinitely loop) Second, when running the TLB miss-handling code, the OS needs to be extra careful not to cause an infinite chain of TLB misses to occur. 
    * you could keep TLB miss handlers in physi- cal memory (where they are unmapped and not subject to address trans- lation)
    * reserve some entries in the TLB for permanently-valid transla- tions and use some of those permanent translation slots for the handler code itself; these wired translations always hit in the TLB.

3. Advantage of software-managed approach
    * flexibility: OS can use any data structure it wants to implement the page table, without necessitating hardware change
    * simplicity: hardware doesn’t have to do much on a miss; it raises an exception, and the OS TLB miss handler does the rest.


# 19.4 TLB Contents: What’s In There?
1. A typical TLB might have 32, 64, or 128 entries and be what is called fully associative. Basically, this just means that any given translation can be anywhere in the TLB, and that the hardware will search the entire TLB in parallel to find the desired translation.
2. TLB entry:
    VPN | PFN | other bits
3. other bits:
    * valid bit: says whether the entry has a valid translation or not
    * protection bits: determine how a page can be accessed (as in the page table)

## ASIDE: TLB VALID BIT ̸= PAGE TABLE VALID BIT
A common mistake is to confuse the valid bits found in a TLB with those found in a page table.

Page Table Valid Bit
1. In a page table, when a page-table entry (PTE) is marked invalid, it means that the page has not been allocated by the process, and should not be accessed by a correctly-working program. The usual response when an invalid page is accessed is to trap to the OS, which will respond by killing the process.

TLB Valid Bit
2. A TLB valid bit, in contrast, simply refers to whether a TLB entry has a valid translation within it. When a system boots, for example, a common initial state for each TLB entry is to be set to invalid, because no address translations are yet cached there. Once virtual memory is enabled, and once programs start running and accessing their virtual address spaces, the TLB is slowly populated, and thus valid entries soon fill the TLB.

TLB Valid Bit for context switch
3. The TLB valid bit is quite useful when performing a context switch too, as we’ll discuss further below. By setting all TLB entries to invalid, the system can ensure that the about-to-be-run process does not accidentally use a virtual-to-physical translation from a previous process.



# 19.5 TLB Issue: Context Switches
1. the TLB contains virtual-to-physical translations that are only valid for the currently running process; these translations are not meaningful for other processes

2. hardware or OS (or both) must be careful to ensure that the about-to-be-run process does not accidentally use translations from some previously run process.

# Crux P191
HOW TO MANAGE TLB CONTENTS ON A CONTEXT SWITCH

3. There are a number of possible solutions to this problem.

flush:
    4. One approach is to simply flush the TLB on context switches, thus emptying it before running the next process.
        * solution in software-based system and hardware-based system
        * cost: each time a process runs, it must incur TLB misses as it touches its data and code pages. If the OS switches between processes frequently, this cost may be high.

ASID
    5. To reduce this overhead, some systems add hardware support to en- able sharing of the TLB across context switches.
    __address space identifier (ASID)__ field in the TLB: You can think of the ASID as a process identifier (PID), but usu- ally it has fewer bits (e.g., 8 bits for the ASID versus 32 bits for a PID).

    6. Of course, the hardware also needs to know which process is currently run- ning in order to perform translations, and thus the OS must, on a context switch, set some privileged register to the ASID of the current process.


# 19.6 Issue: Replacement Policy
miss the replacement policy for cache in CSAPP(chapter 6)

    least-recently-used (LRU)
    random policy








