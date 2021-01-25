# Crux P119
HOW TO ALLOCATE AND MANAGE MEMORY

# free
free 只需要一个参数的原因：动态分配库本身会管理分配的大小！
The routine takes one argument, a pointer that was returned by malloc(). Thus, you might notice, the size of the allocated region is not passed in by the user, and must be tracked by the memory-allocation library itself.

**替代 strcpy 且保证内存管理安全的函数：strdup**

# system call memory management functions
1. brk / sbrk
2. mmap







