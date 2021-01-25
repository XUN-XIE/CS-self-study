# Crux 1 P4
__HOW TO VIRTUALIZE RESOURCES?__
    what mechanisms and policies are implemented by the OS to attain virtualization?
    How does the OS do so efficiently? 
    What hardware support is needed?

### OS 扮演的三个角色
1. refer to the operating system as a __virtual machine__.
因为操作系统会虚拟化，抽象化物理资源
2. __system call__. OS provides these calls to run programs, access memory and devices, and other related actions, we also sometimes say that the OS provides a __standard library__ to applications.
3. OS is sometimes known as a __resource manager__.

提供虚拟抽象的虚拟机；提供系统调用的标准库(Persistence 可知，标准库就是抽象硬件设备，并提供调用的接口)；管理协调资源调度的资源管理器

### Virtualizing CPU
OS作为 resource manager 如何让多个进程同时工作，如何协调实际 CPU 为哪个进程工作

### Virtualizing memory
OS 作为 virtual machine 如何使得每个进程都拥有自己私有的 address space 而不互相干扰


### Concurrency
多线程程序，不会出现固定结果的原因：多指令，并不是逐一执行的（比如例子中的，load，increment，store 三个instruction）
atomically (原子级操作)，可以确保每个 instruction 逐一执行

# Crux 2 P10
__HOW TO BUILD CORRECT CONCURRENT PROGRAMS__
When there are many concurrently executing threads within the same memory space, 
     how can we build a correctly working program? 
     What primitives are needed from the OS? 
     What mechanisms should be provided by the hardware? 
     How can we use them to solve the problems of
concurrency?


### Persistence
1. 系统中，数据是容易丢失的（比如CSAPP中学到的，DROM，DRAM都是必须有电源的情况下，才能保存数据）
2. __Thus, we need hardware and software to be able to store data persistently__
   
3. 硬件级别 Persistence
    The hardware comes in the form of some kind of input/output or I/O device
    a hard drive is a common repository for long- lived information

4. 软件级别 persistence
    The software in the operating system that usually manages the disk is called the file system. it is thus responsible for storing any files the user creates in a reliable and efficient manner on the disks of the system.

5. OS 假设用户想要共享文件中的信息
Unlike the abstractions provided by the OS for the CPU and memory, the OS does not create a private, virtualized disk for each application. Rather, it is assumed that often times, users will want to share informa- tion that is in files.

__Persistence，OS扮演的是 提供 standard library 的角色。因为 程序员 不需要知道底层的 hard driver 怎么设计。只需要知道接口！ 所以 standard library 也相当于抽象，提供了接口的抽象！！！__


# Design Goals
1. abstraction : easy to use
2. performance : less overload
3. protection  : isolation
4. run non-stop: reliability
5. energy-efficiency
6. security
7. mobility


# Summary
本书不讲，但是OS里仍然具备的模块
1. networking
2. graphics devices
3. security



