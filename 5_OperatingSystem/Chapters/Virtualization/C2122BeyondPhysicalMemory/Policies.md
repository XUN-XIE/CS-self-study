# Crux P227
HOW TO DECIDE WHICH PAGE TO EVICT


# 22.1 Cache Management
1. __average memory access time (AMAT)__: a metric computer architects compute for hardware caches [HP06]
    $$AMAT = (Hit_\% · T_M ) + (Miss_\% · T_D)$$
where $T_M$ represents the cost of accessing memory, and represents $T_D$ the cost of accessing disk.

2. as you can see in this example, the cost of disk access is so high in modern systems that even a tiny miss rate will quickly dom- inate the overall AMAT of running programs.


# 22.2 The Optimal Replacement Policy
1. simple but, unfortunately, difficult to implement!
2. Idea: __replaces the page that will be accessed furthest in the future__

3. (不可实现，因为需要知道 future) Unfortunately, as we saw before in the development of scheduling policies, the future is not generally known; you can’t build the optimal policy for a general-purpose operating system

### TIP: COMPARING AGAINST OPTIMAL IS USEFUL
1. Although optimal is not very practical as a real policy, it is incredibly useful as a comparison point in simulation or other studies.
2. (适时的停止脚步) Thus, in any study you perform, knowing what the optimal is lets you perform a better comparison, showing how much improvement is still possible, and also when you can stop making your policy better, because it is close enough to the ideal [AD03].

### ASIDE: TYPES OF CACHE MISSES
architects sometimes find it useful to characterize misses by type, into one of three categories: compulsory, capacity, and conflict misses, sometimes called the Three C’s [H87].
    * compulsory miss (or cold-start miss [EF78]) occurs because the cache is empty to begin with and this is the first reference to the item
    * in con- trast, a capacity miss occurs because the cache ran out of space and had to evict an item to bring a new item into the cache.
    * The third type of miss (a conflict miss) arises in hardware because of limits on where an item can be placed in a hardware cache, due to something known as set- associativity; it does not arise in the OS page cache because such caches are always fully-associative


# 22.3 A Simple Policy: FIFO
1. idea:
pages were simply placed in a queue when they enter the system; when a re- placement occurs, the page on the tail of the queue (the “first-in” page) is evicted.

2. one great strength: it is quite simple to implement.

3. FIFO simply can’t deter- mine the importance of blocks: even though page 0 had been accessed a number of times, FIFO still kicks it out, simply because it was the first one brought into memory.

### ASIDE: BELADY’S ANOMALY
增加 cache size ，反而存在一些序列，导致某个算法，hit rate 减少的现象

1. Both of FIFO and Random Alogrithm suffer from this behaviour. 

2. But LRU do not suffer from this because of __stack property__ : For algorithms with this property, a cache of size N + 1 naturally includes the contents of a cache of size N. Thus, when increas- ing the cache size, hit rate will either stay the same or improve.


# 22.5 Using History: LRU
1. disadvantage of FIFO: FIFO kicks out the page that was first brought in; if this happens to be a page with important code or data structures upon it, it gets thrown out anyhow, even though it will soon be paged back in.

2. two metrics: 
    * frequency: if a page has been accessed many times, perhaps it should not be replaced as it clearly has some value
    * recency: the more recently a page has been accessed, perhaps the more likely it will be accessed again.

3. The Least-Frequently-Used (LFU) policy replaces the least-frequently- used page when an eviction must take place. Similarly, the Least-Recently- Used (LRU) policy replaces the least-recently-used page.

4. (相反的算法并非完全无用！) We should also note that the opposites of these algorithms exist: Most- Frequently-Used (MFU) and Most-Recently-Used (MRU). In most cases (not all!), these policies do not work well, as they ignore the locality most programs exhibit instead of embracing it.


# 22.6 Workload Examples
first experiment
100 unique pages
1. First, when there is no locality in the workload, it doesn’t matter much which realistic policy you are using; LRU, FIFO, and Random all perform the same, with the hit rate exactly determined by the size of the cache.
2. Second, when the cache is large enough to fit the entire workload, it also doesn’t matter which policy you use; all policies (even optimal) converge to a 100% hit rate when all the referenced blocks fit in cache.
3. Finally, you can see that optimal performs noticeably better than the realistic policies; peeking into the future, if it were possible, does a much better job of replacement


second experiment
80% of the references are made to 20% of the pages, the remaining 20% of the references are made to the re- maining 80% of the pages

If each miss is very costly (not uncommon), then even a small increase in hit rate (reduction in miss rate) can make a huge difference on performance. If misses are not so costly, then of course the benefits possible with LRU are not nearly as important.


third experiment
50 unique pages, and looply reference them 10000 times

__the worst case for LRU and FIFO__:
__common in many applications (including important commercial applications__ such as databases [CD85]), represents a worst- case for both LRU and FIFO. These algorithms, under a looping-sequential workload, kick out older pages; unfortunately, due to the looping nature of the workload, these older pages are going to be accessed sooner than the pages that the policies prefer to keep in cache.


# 22.7 Implementing Historical Algorithms
1. (easily lead to large time cost) To keep track of which pages have been least- and most-recently used, the system has to do some accounting work on every memory reference. Clearly, without great care, such accounting could greatly reduce performance.

2. One method that could help speed this up is to add a little bit of hard- ware support:
    For example, a machine could update, on each page access, a **time field** in memory. 
    Thus, when a page is accessed, the time field would be set, by hardware, to the current time.
    Then, when replacing a page, the OS could simply scan all the time fields in the system to find the least-recently-used page.

3. problem: Unfortunately, as the number of pages in a system grows, scanning a huge array of times just to find the absolute least-recently-used page is prohibitively expensive.

# Crux P238
HOW TO IMPLEMENT AN LRU REPLACEMENT POLICY
Given that it will be expensive to implement perfect LRU, can we ap-
proximate it in some way, and still obtain the desired behavior?


# 22.8 Approximating LRU
1. The idea requires some hardware support, in the form of a use bit (sometimes called the reference bit)

2. manipulation:
    There is one use bit per page of the system, and the use bits live in memory somewhere
    Whenever a page is referenced (i.e., read or written), the use bit is set by hardware to 1
    The hardware never clears the bit, though (i.e., sets it to 0); that is the respon- sibility of the OS.

3. one approach utilizing __clock algorithm__:
    1. A clock hand points to some particular page to begin with (it doesn’t really matter which)
    2. When a replacement must occur, the OS checks if the currently-pointed to page P has a use bit of 1 or 0
    3. If 1, this implies that page P was recently used and thus is not a good candidate for replacement.
    4. Thus, the clock hand is incremented to the next page P + 1, and __the use bit for P set to 0 (cleared)__.
    5. The algorithm continues until it finds a use bit that is set to 0, implying this page has not been recently used(or, in the worst case, that all pages have been and that we have now searched through the entire set of pages, clearing all the bits)

4. (we can change algorithm according to the principle) Note that this approach is not the only way to employ a use bit to approximate LRU. Indeed, any approach which periodically clears the use bits and then differentiates between which pages have use bits of 1 versus 0 to decide which to replace would be fine.


# 22.9 Considering Dirty Pages
modification:
One small modification to the clock algorithm (also originally sug- gested by Corbato [C69]) that is commonly made is the additional con- sideration of whether a page has been modified or not while in memory.

1. __( cost of eviction is different for clean page and dirty page because of request of I/O )__ The reason for this: if a page has been modified and is thus dirty, it must be written back to disk to evict it, which is expensive. If it has not been modified (and is thus clean), the eviction is free; the physical frame can simply be reused for other purposes without additional I/O. Thus, some VM systems prefer to evict clean pages over dirty pages.

2. To support this behavior, the hardware should include a modified bit (a.k.a. dirty bit) 
    This bit is set any time a page is written, and thus can be incorporated into the page-replacement algorithm

3. The clock algorithm, for example, could be changed to scan for pages that are both unused and clean to evict first; failing to find those, then for unused pages that are dirty; etc.


# 22.10 Other VM Policies
1. Page replacement is not the only policy the VM subsystem employs (though it may be the most important).

2. the OS also has to decide when to bring a page into memory. This policy, sometimes called the __page selection policy__
3. For most pages, the OS simply uses demand paging, which means the OS brings the page into memory when it is accessed, “on demand” as it were. Of course, the OS could guess that a page is about to be used, and thus bring it in ahead of time; this behavior is known as prefetching and should only be done when there is reasonable chance of success.

4. Another policy determines how the OS writes pages out to disk.
    many systems instead collect a number of pending writes together in memory and write them to disk in one (more efficient) write. This behavior is usually called clustering or simply grouping of writes, and is effective because of the nature of disk drives, which perform a single large write more efficiently than many small ones.


# 22.11 Thrashing
    __last question__:
    what should the OS do when memory is simply oversubscribed, and the memory demands of the set of running processes simply exceeds the available physical memory?

In this case, the system will __constantly be paging__, a condition sometimes referred to as __thrashing__

1. one old approach:
    admission control: a system could decide not to run a sub- set of processes, with the hope that the reduced set of processes working sets (the pages that they are using actively) fit in memory and thus can make progress.
    states that it is sometimes better to do less work well than to try to do everything at once poorly, a situation we often encounter in real life as well as in modern computer systems (sadly).

2. some versions of Linux run an out-of-memory killer when memory is oversubscribed this daemon chooses a memory- intensive process and kills it, thus reducing memory in a none-too-subtle manner. 
    
    disadvantage: While successful at reducing memory pressure, this approach can have problems, if, for example, it kills the X server and thus renders any applications requiring the display unusable.


# Summary
However, in many cases the importance of said algorithms has de- creased, as the discrepancy between memory-access and disk-access times has increased. Because paging to disk is so expensive, the cost of frequent paging is prohibitive. Thus, the best solution to excessive paging is often a simple (if intellectually dissatisfying) one: buy more memory.
