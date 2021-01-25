1. introduce a new abstraction for a single running process: that of a __thread__

2. a __multi-threaded__ program has more than one point of execution(i.e., multiple PCs, each of which is being fetched and executed from)

3. Perhaps another way to think of this is that each thread is very much like a separate process, except for one difference: they share the same address space and thus can access the same data.

4. when context switch. With processes, we saved state to a process control block (PCB); now, we’ll need one or more thread control blocks (TCBs) to store the state of each thread of a process.

5. There is one major difference, though, in the context switch we perform between threads as compared to processes: the address space remains the same (i.e., there is no need to switch which page table we are using).

6. One other major difference between threads and processes concerns the stack. 

However, in a multi-threaded process, each thread runs independently and of course may call into various routines to do whatever work it is do- ing. Instead of a single stack in the address space, there will be one per thread.

7. Thus, any stack-allocated variables, parameters, re- turn values, and other things that we put on the stack will be placed in what is sometimes called thread-local storage, i.e., the stack of the rele- vant thread.

8. Fortunately, this is usually OK, as stacks do not generally have to be very large (the exception being in pro- grams that make heavy use of recursion).


### TIP: KNOW AND USE YOUR TOOLS
1. You should always learn new tools that help you write, debug, and un- derstand computer systems. Here, we use a neat tool called a disassem- bler.

2. gdb

3. __the better you are at using your tools, the better systems you’ll be able to build.__

# 26.3 The Heart of the Problem: Uncontrolled Scheduling
1. when mov instruction is excecuting, something unfortunate happens: a __timer interrupt__ goes off; thus, the OS saves the state of the currently running thread (its PC, its registers including eax, etc.) to the thread’s TCB.
2. when context switch back to original thread, the counter now in this thread is the same value as another value, so two thread act as adding only once!!!


3. What we have demonstrated here is called a __race condition__: the results depend on the timing execution of the code.

4. Because multiple threads executing this code can result in a race con- dition, we call this code a __critical section__:
    A critical section is a piece of code that accesses a shared variable (or more generally, a shared resource) and must not be concurrently executed by more than one thread.

5. What we really want for this code is what we call __mutual exclusion__:
    This property guarantees that if one thread is executing within the critical section, the others will be prevented from doing so.


# 26.4 The Wish For Atomicity
1. __(solution: prevent untimely interrupt)__ One way to solve this problem would be to have more powerful in- structions that, in a single step, did exactly whatever we needed done and thus removed the possibility of an untimely interrupt.

2. Thus, what we will instead do is ask the hardware for a few useful instructions upon which we can build a general set of what we call __synchronization primitives__.


#### core problem
By using these hardware synchronization prim- itives, in combination with some help from the operating system, we will be able to build multi-threaded code that accesses critical sections in a synchronized and controlled manner, and thus reliably produces the cor- rect result despite the challenging nature of concurrent execution. Pretty awesome, right?


### ASIDE: KEY CONCURRENCY TERMS
CRITICAL SECTION, RACE CONDITION, INDETERMINATE, MUTUAL EXCLUSION
    • A critical section is a piece of code that accesses a shared resource, usually a variable or data structure.
    • A race condition arises if multiple threads of execution enter the critical section at roughly the same time; both attempt to update the shared data structure, leading to a surprising (and perhaps un- desirable) outcome.
    • Anindeterminateprogramconsistsofoneormoreraceconditions; the output of the program varies from run to run, depending on which threads ran when. The outcome is thus not deterministic, something we usually expect from computer systems.
    • To avoid these problems, threads should use some kind of mutual exclusion primitives; doing so guarantees that only a single thread ever enters a critical section, thus avoiding races, and resulting in deterministic program outputs.


# Crux P272
HOW TO PROVIDE SUPPORT FOR SYNCHRONIZATION
What support do we need from the hardware in order to build use- ful synchronization primitives? 
What support do we need from the OS? 
How can we build these primitives correctly and efficiently? 
How can programs use them to get the desired results?


# 26.5 One More Problem: Waiting For Another
there is another common interaction that arises, where one thread must wait for another to complete some action before it continues.


Two core problems in multi-thread programming:
shared data and sleep/wake interaction
we’ll be not only studying how to build support for synchronization primitives to support atomicity but also for mechanisms to support this type of sleeping/waking interaction that is common in multi-threaded programs


# 26.6 Summary: Why in OS Class?
OS designers, from the very beginning of the introduction of the interrupt, had to worry about how the OS updates internal structures. An untimely interrupt causes all of the problems described above. Not surprisingly, page tables, process lists, file system structures, and virtually every kernel data structure has to be carefully accessed, with the proper synchronization primitives, to work correctly.

### TIP: USE ATOMIC OPERATIONS
Atomic operations are one of the most powerful underlying techniques in building computer systems, from the computer architecture, to concur- rent code (what we are studying here), to file systems (which we’ll study soon enough), database management systems, and even distributed systems

