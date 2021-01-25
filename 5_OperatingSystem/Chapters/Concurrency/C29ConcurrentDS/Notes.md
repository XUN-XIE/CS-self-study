# Crux P311
HOW TO ADD LOCKS TO DATA STRUCTURES
When given a particular data structure, how should we add locks to it, in order to make it work correctly? 
Further, how do we add locks such that the data structure yields high performance, enabling many threads to access the structure at once, i.e., concurrently?


**we hope to provide a sufficient introduction to the type of think- ing required**

**refer you to some good sources of material for further inquiry on your own**


# 29.1 Concurrent Counters
1. This concurrent counter is simple and works correctly. In fact, it fol- lows a design pattern common to the simplest and most basic concurrent data structures:
    it simply adds a single lock, which is acquired when call- ing a routine that manipulates the data structure, and is released when returning from the call.

2. Ideally, you’d like to see the threads complete just as quickly on mul- tiple processors as the single thread does on one. Achieving this end is called perfect scaling; even though more work is done, it is done in par- allel, and hence the time taken to complete the task is not increased.








