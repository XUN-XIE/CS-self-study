本章主要内容：
讲解几个不同的 计算机架构指令，用来产生 lock 函数
通过不同的几个指标，对比不同的方法的优劣性

# 28.1 Locks: The Basic Idea
1. This lock variable (or just “lock” for short) holds the state of the lock at any instant in time

2. It is either __available (or unlocked or free)__ and thus no thread holds the lock, or __acquired (or locked or held)__, and thus exactly one thread holds the lock and presumably is in a critical section.


3. Locks provide some minimal amount of control over scheduling to programmers. In general, we view threads as entities created by the pro- grammer but scheduled by the OS, in any fashion that the OS chooses. Locks yield some of that control back to the programmer; by putting a lock around a section of code, the programmer can guarantee that no more than a single thread can ever be active within that code. Thus locks help transform the chaos that is traditional OS scheduling into a more controlled activity.

# 28.2 Pthread Locks
1. The name that the POSIX library uses for a lock is a mutex, as it is used to provide mutual exclusion between threads, i.e., if one thread is in the critical section, it excludes the others from entering until it has completed the section.

2. __( 多个 lock )__ You might also notice here that the POSIX version passes a variable to lock and unlock, as we may be using different locks to protect different variables. Doing so can increase concurrency: instead of one big lock that is used any time any critical section is accessed (a coarse-grained locking strategy), one will often protect different data and data structures with different locks, thus allowing more threads to be in locked code at once (a more fine-grained approach).


# 28.3 Building A Lock

# Crux P293
HOW TO BUILD A LOCK
How can we build an efficient lock? Efficient locks provided mutual
exclusion at low cost, and also might attain a few other properties we discuss below. 
What hardware support is needed? 
What OS support?


# 28.4 Evaluating Locks
1. To evaluate whether a lock works (and works well), we should first establish some basic criteria:
    * The first is whether the lock does its basic task, which is to provide mutual exclusion.
    * The second is fairness. Does each thread contending for the lock get a fair shot at acquiring it once it is free? Another way to look at this is by examining the more extreme case: does any thread contending for the lock starve while doing so, thus never obtaining it?
    * The final criterion is performance, specifically the time overheads added by using the lock. There are a few different cases that are worth con- sidering here:
        1. One is the case of no contention; when a single thread is running and grabs and releases the lock, what is the overhead of do- ing so?
        2. Another is the case where multiple threads are contending for the lock on a single CPU; in this case, are there performance concerns?
        3. Finally, how does the lock perform when there are multiple CPUs involved, and threads on each contending for the lock?


**提出基本模型和指标关注点**
# 28.5 Controlling Interrupts
1. (old time version) One of the earliest solutions used to provide mutual exclusion was
to disable interrupts for critical sections; this solution was invented for single-processor systems.
    Advantage: The main positive of this approach is its simplicity.
    Disadvantage: The negatives, unfortunately, are many:
        1. First, this approach requires us to allow any calling thread to perform a privileged operation (turning interrupts on and off), and thus trust that this facility is not abused. 
        2. Second, the approach does not work on multiprocessors.
        3. Third, and probably least important, this approach can be inefficient. Compared to normal instruction execution, code that masks or unmasks interrupts tends to be executed slowly by modern CPUs.

**解决方法思路1**
```
int TestAndSet(int *ptr, int new) {
    int old = *ptr; // fetch old value at ptr 
    *ptr = new; // store ’new’ into ptr 
    return old; // return the old value
}
```
# 28.6 Test And Set (Atomic Exchange)
1. The simplest bit of hardware support to understand is what is known as a __test-and-set instruction__, also known as __atomic exchange__.

Two problems still:
1. correctness:
    we can easily produce a case where both threads set their flags to 1 and both threads are thus able to enter the critical section.
2. performance:
    it endlessly checks the value of flag, a technique known as spin-waiting. Spin-waiting wastes time waiting for another thread to release a lock. The waste is exceptionally high on a uniprocessor, where the thread that the waiter is waiting for cannot even run (at least, until a context switch oc- curs)!


# 28.7 Building A Working Spin Lock
引入了一个 计算机架构 里才会学到的 instruction
test-and-set, 其中每个指令都是 atomic 的，至于如何实现的，不要管，那是计算机架构和硬件的事情。

这个 test-and-set 解决了 上一个section里的 correctness 的问题


# 28.8 Evaluating Spin Locks
1. correct
2. spin locks don’t provide any fairness guarantees. Indeed, a thread spinning may spin forever, under contention. Spin locks are not fair and may lead to starvation.
3. For spin locks, in the single CPU case, performance overheads can be quite painful
4. However, on multiple CPUs, spin locks work reasonably well (if the number of threads roughly equals the number of CPUs).


**解决思路2**
# 28.9 Compare-And-Swap
```
int CompareAndSwap(int *ptr, int expected, int new) { 
    int actual = *ptr;
    if (actual == expected)
        *ptr = new;
    return actual;
```
1. compare-and-swap is a more power- ful instruction than test-and-set.
2. We will make some use of this power in the future when we briefly delve into __wait-free synchronization__.
3. However, if we just build a simple spin lock with it, its behavior is iden- tical to the spin lock we analyzed above.


# TIP: LESS CODE IS BETTER CODE (LAUER’S LAW)
1. Short, concise code is always preferred; it is likely easier to understand and has fewer bugs.
2. If the same people had twice as much time, they could produce as good of a system in half the code 
                                            —— __Lauer’s Law__
3. So next time you’re bragging about how much code you wrote to finish the assignment, think again, or better yet, go back, rewrite, and make the code as clear and con- cise as possible.

**解决思路3**
# 28.10 Load-Linked and Store-Conditional

**解决思路4**
# 28.11 Fetch-And-Add
```
int FetchAndAdd(int *ptr) { 
    int old = *ptr;
    *ptr = old + 1;
    return old;
}
```
1. One final hardware primitive is the fetch-and-add instruction, which atomically increments a value while returning the old value at a partic- ular address.
2. __ticket lock__


# Summary: So Much Spinning
However, in some cases, these solutions can be quite inefficient. And thus, our next problem: 

# Crux P304 
HOW TO AVOID SPINNING
How can we develop a lock that doesn’t needlessly waste time spin-
ning on the CPU?

Hardware support alone cannot solve the problem. We’ll need OS sup- port too! Let’s now figure out just how that might work.


