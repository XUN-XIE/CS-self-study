## 1.1 Information Is Bits + Context
1. The source program is a sequence of bits, each with a value of 0 or 1, organized in 8-bit chunks called bytes. Each byte represents some text character in the program.
2. The hello.c program is stored in a file as a sequence of bytes. Each byte has an integer value that corresponds to some character.
3. Files such as hello.c that consist exclusively of ASCII characters are known as text files. All other files are known as binary files.
4. **The representation of hello.c illustrates a fundamental idea: All information in a system—including disk files, programs stored in memory, user data stored in memory, and data transferred across a network—is represented as a bunch of bits.**
5. The only thing that distinguishes different data objects is the context in which we view them. For example, in different contexts, the same sequence of bytes might represent an integer, floating-point number, character string, or machine instruction.
6. As programmers, we need to understand machine representations of numbers because they are not the same as integers and real numbers. They are finite approximations that can behave in unexpected ways.

**Why does C success?**
	1. C was closely tied with the Unix operating system. C was developed from the beginning as the system programming language for Unix. Most of the Unix kernel (the core part of the operating system), and all of its supporting tools and libraries, were written in C. it could be easily ported to new machines, which created an even wider audience for both C and Unix.
	2. C is a small, simple language. The design was controlled by a single person, rather than a committee, and the result was a clean, consistent design with little baggage. The simplicity of C made it relatively easy to learn and to port to different computers.
	3. C was designed for a practical purpose. C was designed to implement the Unix operating system.
C is the language of choice for system-level programming, and there is a huge installed base of application-level programs as well. However, it is not perfect for all programmers and all situations. C pointers are a common source of confusion and programming errors. C also lacks explicit support for useful abstractions such as classes, objects, and exceptions.


## 1.2 Programs Are Translated by Other Programs into Different Forms
1. in order to run hello.c on the system, the individual C statements must be translated by other programs into a sequence of low-level machine-language instructions.
2. These instructions are then packaged in a form called an executable object program and stored as a binary disk file. Object programs are also referred to as executable object files.
3. **On a Unix system, the translation from source file to object file is performed by a compiler driver: Figure 1.3 值得重点学习!**!
4. Here, the gcc compiler driver reads the source file hello.c and translates it into an executable object file hello. The translation is performed in the sequence of four phases shown in Figure 1.3. The programs that perform the four phases (preprocessor, compiler, assembler, and linker) are known collectively as the compilation system.
	1. (处理宏定义) Preprocessing phase. The preprocessor (cpp) modifies the original C program according to directives that begin with the ‘#’ character. For example, the #include <stdio.h> command in line 1 of hello.c tells the preprocessor to **read the contents of the system header file stdio.h and insert it directly into the program text**. The result is another C program, typically with the .i suffix.
	2. (产生汇编码(交给后续的汇编器)) Compilation phase. The compiler (cc1) translates the text file hello.i into the text file hello.s, which contains an assembly-language program.**Assembly language is useful because it provides a common output language for different compilers for different high-level languages.** 
	3. (汇编码转换为机器码)Assembly phase. the assembler (as) translates hello.s into machine- language instructions, packages them in a form known as a relocatable object program, and stores the result in the object file hello.o. This file is a binary file containing 17 bytes to encode the instructions for function main.
	4. (链接所有相关的机器码生成可执行文件) Linking phase. Notice that our hello program calls the printf function, which is part of the standard C library provided by every C compiler. The printf function resides in a separate precompiled object file called printf.o, which must somehow be merged with our hello.o program. The linker (ld) handles this merging. The result is the hello file, which is an executable object file (or simply executable) that is ready to be loaded into memory and executed by the system.


## 1.3 It Pays to Understand How Compilation Systems Work(由上一节的四个阶段，扩展出本书的全局流程细节)
1. (我们需要理解上一节中描述的汇编系统四个阶段的原因！) For simple programs such as hello.c, we can rely on the compilation system to produce correct and efficient machine code. However, there are some important reasons why programmers need to understand how compilation systems work:
	1. Optimizing program performance. Modern compilers are sophisticated tools that usually produce good code. As programmers, we do not need to know the inner workings of the compiler in order to write efficient code. **However, in order to make good coding decisions in our C programs, we do need a basic understanding of machine-level code and how the compiler translates different C statements into machine code.** 
	2. Understanding link-time errors. In our experience, some of the most perplex- ing programming errors are related to the operation of the linker, especially when you are trying to build large software systems.
	3. Avoiding security holes. For many years, buffer overflow vulnerabilities have accounted for many of the security holes in network and Internet servers. These vulnerabilities exist because too few programmers understand the need to carefully restrict the quantity and forms of data they accept from untrusted sources. A first step in learning secure programming is to understand the con- sequences of the way data and control information are stored on the program stack.


## 1.4 Processors Read and Interpret Instructions Stored in Memory
1. (shell就只能执行可执行文件，只不过优先对应内置命令(命令也是可执行文件))If the first word of the command line does not correspond to a built-in shell command, then the shell assumes that it is the name of an executable file that it should load and run. So in this case, the shell loads and runs the hello program and then waits for it to terminate.

###1.4.1 Hardware Organization of a System(看图1.4进行学习)
#### Buses
1. Running throughout the system is a collection of electrical conduits called buses that carry bytes of information back and forth between the components.
2. Buses are typically designed to transfer fixed-size chunks of bytes known as words.
3. (32位和64位的区别，就是bus内不words字节数的不同)The number of bytes in a word (the word size) is a fundamental system parameter that varies across systems. Most machines today have word sizes of either 4 bytes (32 bits) or 8 bytes (64 bits).
4. we will specify what we mean by a “word” in any context that requires this to be defined.

#### I/O Devices
1. Input/output (I/O) devices are the system’s connection to the external world.
2. Initially, the executable hello program resides on the disk.
3. Each I/O device is connected to the I/O bus by either a controller or an adapter. The distinction between the two is mainly one of packaging.
4. Controllers are chip sets in the device itself or on the system’s main printed circuit board (often called the motherboard).
5. An adapter is a card that plugs into a slot on the motherboard.
6. Regardless, the purpose of each is to transfer information back and forth between the I/O bus and an I/O device.
7. (网络是一个 I/O device!? ) We focus on the especially interesting class of devices known as networks, but the techniques generalize to other kinds of devices as well.

#### Main Memory
1. The main memory is a temporary storage device that holds both a program and the data it manipulates while the processor is executing the program.
2. Physically, main memory consists of a collection of dynamic random access memory (DRAM) chips.
3. Logically, memory is organized as a linear array of bytes, each with its own unique address (array index) starting at zero.
4. In general, each of the machine instructions that constitute a program can consist of a variable number of bytes.

#### Processor
1. The central processing unit (CPU), or simply processor, is the engine that inter- prets (or executes) instructions stored in main memory.
2. (解释了CPU一次处理 word-size 长度的数据，因为内部寄存器只能读取这么长的 word) At its core is a word-size storage device (or register) called the program counter (PC).
3. (PC用来指向的是机器指令!) At any point in time, the PC points at (contains the address of) some machine-language instruction in main memory.
4. **(processor读取PC里存储的指令) From the time that power is applied to the system until the time that the power is shut off, a processor repeatedly executes the instruction pointed at by the program counter and updates the program counter to point to the next instruction.**
5. A processor appears to operate according to a very simple instruction execution model, defined by its instruction set architecture. 
6. (processor和memory协同工作的过程。机器指令存放在内存中，PC用来指向内存中的地址，决定取出哪个指令，processor负责根据PC指向的地址去内存中取出对应的机器指令，然后执行，最后PC会改变为指向内存中的其他指令)In this model, instructions execute in strict sequence, and executing a single instruction involves performing a series of steps. **The processor reads the instruction from memory pointed at by the program counter (PC), interprets the bits in the instruction, performs some simple operation dictated by the instruction, and then updates the PC to point to the next instruction, which may or may not be contiguous in memory to the instruction that was just executed.**
7. There are only a few of these simple operations, and they revolve around main memory, the register file, and the arithmetic/logic unit (ALU).
8. (有一个寄存器“文件”包含很多个不同的寄存器) The register file is a small storage device that consists of a collection of word-size registers, each with its own unique name.
9. The ALU computes new data and address values.
10. **(对加深理解很有帮助) Here are some examples of the simple operations that the CPU might carry out at the request of an instruction:**
	* (寄存器是用来存放给processor处理用的临时数据的 一个存储装置，我觉得甚至可以理解为 I/O device？)Load: Copy a byte or a word from main memory into a register, overwriting the previous contents of the register.
	* (寄存器把处理完的数据再写入到内存中)Store: Copy a byte or a word from a register to a location in main memory, overwriting the previous contents of that location.
	* (执行计算的是ALU，因为寄存器集中有多个寄存器，所以可以用两个寄存器存储operands，然后ALU读取进行计算，结果再放回一个寄存器里)Operate: Copy the contents of two registers to the ALU, perform an arithmetic operation on the two words, and store the result in a register, overwriting the previous contents of that register.
	* (PC重指向内存中指令的位置)Jump: Extract a word from the instruction itself and copy that word into the program counter (PC), overwriting the previous value of the PC.


### 1.4.2 Running the hello Program(根据1.4.1的模型，详细解释每个过程发生了什么)
1. Initially, the shell program is executing its instructions, waiting for us to type a command. As we type the characters ./hello at the keyboard, the shell program reads each one into a register and then stores it in memory, as shown in Figure 1.5.
2. When we hit the enter key on the keyboard, the shell knows that we have finished typing the command. The shell then loads the executable hello file by executing a sequence of instructions that copies the code and data in the hello object file from disk to main memory. The data includes the string of characters hello, world\n that will eventually be printed out.
3. Using a technique known as direct memory access (DMA, discussed in Chap- ter 6), the data travel directly from disk to main memory, without passing through the processor. This step is shown in Figure 1.6.
4. Once the code and data in the hello object file are loaded into memory, the processor begins executing the machine-language instructions in the hello program’s main routine. These instructions copy the bytes in the hello, world\n string from memory to the register file, and from there to the display device, where they are displayed on the screen. This step is shown in Figure 1.7.


## 1.5 Caches Matter
1. **An important lesson from this simple example is that a system spends a lot of time moving information from one place to another.**
2. (机器码的移动流程) The machine instructions in the hello program are originally stored on disk. When the program is loaded, they are copied to main memory. As the processor runs the program, instruc- tions are copied from main memory into the processor.
3. (数据的移动流程) Similarly, the data string hello,world\n, originally on disk, is copied to main memory and then copied from main memory to the display device.
4. **(引出系统设计者的目标) From a programmer’s perspective, much of this copying is overhead that slows down the “real work” of the program. Thus, a major goal for system designers is to make these copy operations run as fast as possible.**
5. Because of physical laws, larger storage devices are slower than smaller stor- age devices. And faster devices are more expensive to build than their slower counterparts. 硬盘比内存大，但是处理器处理内存快更多倍。寄存器比内存小，但是处理器处理寄存器更快。 Even more troublesome, as semiconductor technology progresses over the years, this processor–memory gap continues to increase. It is easier and cheaper to make processors run faster than it is to make main memory run faster.
6. **(上面的所有都是为了引出缓存) To deal with the processor–memory gap, system designers include smaller, faster storage devices called cache memories (or simply caches) that serve as temporary staging areas for information that the processor is likely to need in the near future.**
7. An L1 cache on the processor chip holds tens of thousands of bytes and can be accessed nearly as fast as the register file.
8. A larger L2 cache with hundreds of thousands to millions of bytes is connected to the processor by a special bus. It might take 5 times longer for the processor to access the L2 cache than the L1 cache, but this is still 5 to 10 times faster than accessing the main memory.
9. The L1 and L2 caches are implemented with a hardware technology known as static random access memory (SRAM).
10. **(缓存存在的思想，利用局部性!) The idea behind caching is that a system can get the effect of both a very large memory and a very fast one by exploiting locality, the tendency for programs to access data and code in localized regions.**
11. By setting up caches to hold data that are likely to be accessed often, we can perform most memory operations using the fast caches.
12. (应用) One of the most important lessons in this book is that application program- mers who are aware of cache memories can exploit them to improve the perfor- mance of their programs by an order of magnitude.



**学习Figure 1.9中所有储存容器的层次关系，从大小和速度分级**
## 1.6 Storage Devices Form a Hierarchy
1. This notion of inserting a smaller, faster storage device (e.g., cache memory) between the processor and a larger, slower device (e.g., main memory) turns out to be a general idea.
2. (容器分级) In fact, the storage devices in every computer system are organized as a memory hierarchy similar to Figure 1.9. As we move from the top of the hierarchy to the bottom, the devices become slower, larger, and less costly per byte. The register file occupies the top level in the hierarchy, which is known as level 0 or L0. We show three levels of caching L1 to L3, occupying memory hierarchy levels 1 to 3. Main memory occupies level 4, and so on.
3. (思想，每一个上级存储器都是下一级存储器的 "cache"(这里是一个概念意义上的缓存，不是指缓存器(cache memory))) The main idea of a memory hierarchy is that storage at one level serves as a cache for storage at the next lower level. Thus, the register file is a cache for the L1 cache. Caches L1 and L2 are caches for L2 and L3, respectively. The L3 cache is a cache for the main memory, which is a cache for the disk. On some networked systems with distributed file systems, the local disk serves as a cache for data stored on the disks of other systems.
4. (应用) Just as programmers can exploit knowledge of the different caches to improve performance, programmers can exploit their understanding of the entire memory hierarchy.


## 1.7 The Operating System Manages the Hardware
1. (操作系统的作用) When the shell loaded and ran the hello program, and when the hello program printed its message, neither program accessed the keyboard, display, disk, or main memory directly. keyboard, display, disk, or main memory directly.
2. (操作系统就是硬软件之间的接口，正如那本书名一样，操作系统：软件硬件接口) We can think of the operating system as a layer of software interposed between the application program and the hardware, as shown in Figure 1.10. All attempts by an application program to manipulate the hardware must go through the operating system.
**PS：上两节内容讲的寄存器，缓存，内存，硬盘都是硬件! 软件是我们要执行的程序!**
3. **The operating system has two primary purposes:**
	1. (保护机制) to protect the hardware from misuse by runaway applications
	2. (合理控制协调硬件资源) to provide applications with simple and uniform mechanisms for manipulating complicated and often wildly different low-level hardware devices.
4. The operating system achieves both goals via the fundamental abstractions shown in Figure 1.11: processes, virtual memory, and files.
5. (操作系统中的 virtualization 机制，回忆 OS:Three Easy Pieces 里学的CPU和内存的虚拟机制，表示程序从软件层面上虚拟化出硬件对应的真实操作) As this figure suggests, files are abstractions for I/O devices, virtual memory is an abstraction for both the main memory and disk I/O devices, and processes are abstractions for the processor, main memory, and I/O devices.

### Aside: Unix, Posix, and the Standard Unix Specification
1. The result was a family of standards, known as the Posix standards, that cover such issues as the C language interface for Unix system calls, shell programs and utilities, threads, and network program- ming.
2. As a result of these standardization efforts, the differences between Unix versions have largely disappeared.


### 1.7.1 Processes(注意Figure 1.12 的学习)
1. (程序，处理器，数据都有一个虚拟化的使用硬件，仿佛被欺骗一样!) When a program such as hello runs on a modern system, the operating system provides the illusion that the program is the only one running on the system.
	* The program appears to have exclusive use of both the processor, main memory, and I/O devices.
	* The processor appears to execute the instructions in the program, one after the other, without interruption.
	* the code and data of the program appear to be the only objects in the system’s memory.
总： These illusions are provided by the notion of a process, one of the most important and successful ideas in computer science.
2. A process is the operating system’s abstraction for a running program.
3. Multi- ple processes can run concurrently on the same system, and each process appears to have exclusive use of the hardware. By concurrently, we mean that the instruc- tions of one process are interleaved with the instructions of another process.
4. In most systems, there are more processes to run than there are CPUs to run them.
5. Traditional systems could only execute one program at a time, while newer multi- core processors can execute several programs simultaneously. In either case, a single CPU can appear to execute multiple processes concurrently by having the processor switch among them.
6. (引入 context switch ) The operating system performs this interleaving with a mechanism known as context switching.
例子
7. The operating system keeps track of all the state information that the process needs in order to run. This state, which is known as the context, includes informa- tion such as the current values of the PC, the register file, and the contents of main memory.
8. At any point in time, a uniprocessor system can only execute the code for a single process. When the operating system decides to transfer control from the current process to some new process, it performs a context switch by saving the context of the current process, restoring the context of the new process, and then passing control to the new process.
9. **(解释shell中执行hello的context switch的流程) There are two concurrent processes in our example scenario: the shell process and the hello process. Initially, the shell process is running alone, waiting for input on the command line. When we ask it to run the hello program, the shell carries out our request by invoking a special function known as a system call that passes control to the operating system. The operating system saves the shell’s context, creates a new hello process and its context, and then passes control to the new hello process. After hello terminates, the operating system restores the context of the shell process and passes control back to it, where it waits for the next command-line input.**
10. **(介绍kernel!) As Figure 1.12 indicates, the transition from one process to another is man- aged by the operating system kernel. The kernel is the portion of the operating system code that is always resident in memory.**
11. (kernel的使用流程) When an application program requires some action by the operating system, such as to read or write a file, it executes a special system call instruction, transferring control to the kernel. The kernel then performs the requested operation and returns back to the application program.
12. **(kernel的本质! 并不是一个process，只是一堆代码和管理所有processes的数据结构!) Note that the kernel is not a separate process. Instead, it is a collection of code and data structures that the system uses to manage all the processes.**
13. Implementing the process abstraction requires close cooperation between both the low-level hardware and the operating system software.

### 1.7.2 Threads
1. Although we normally think of a process as having a single control flow, in modern systems a process can actually consist of multiple execution units, called threads, each running in the context of the process and sharing the same code and global data.
2. **(threads的优点，相比于processes，支持并发，更容易分享数据，更高效) Threads are an increasingly important programming model because of the requirement for concurrency in network servers, because it is easier to share data between multiple threads than between multiple processes, and because threads are typically more efficient than processes.**
3. **Multi-threading is also one way to make programs run faster when multiple processors are available**


### 1.7.3 Virtual Memory
1. Virtual memory is an abstraction that provides each process with the illusion that it has exclusive use of the main memory.
2. (每一个进程对内存都有一样的状态! 虽然是假的) Each process has the same uniform view of memory, which is known as its virtual address space.
3. The virtual address space for Linux processes is shown in Figure 1.13. (Other Unix systems use a similar layout.)
4. In Linux, the topmost region of the address space is reserved for code and data in the operating system that is common to all processes. The lower region of the address space holds the code and data defined by the user’s process. Note that addresses in the figure increase from the bottom to the top.
5. **The virtual address space seen by each process consists of a number of well- defined areas, each with a specific purpose.**
	* Program code and data.Code begins at the same fixed address for all processes, followed by data locations that correspond to global C variables. The code and data areas are initialized directly from the contents of an executable object file—in our case, the hello executable.
	* Heap. The code and data areas are followed immediately by the run-time heap. Unlike the code and data areas, which are fixed in size once the process begins running, the heap expands and contracts dynamically at run time as a result of calls to C standard library routines such as malloc and free.
	* Shared libraries. Near the middle of the address space is an area that holds the code and data for shared libraries such as the C standard library and the math library. The notion of a shared library is a powerful but somewhat difficult concept.
	* Stack. At the top of the user’s virtual address space is the user stack that the compiler uses to implement function calls. Like the heap, the user stack expands and contracts dynamically during the execution of the program. In particular, each time we call a function, the stack grows. Each time we return from a function, it contracts.
	* Kernel virtual memory. The top region of the address space is reserved for the kernel. Application programs are not allowed to read or write the contents of this area or to directly call functions defined in the kernel code. Instead, they must invoke the kernel to perform these operations.
6. For virtual memory to work, a sophisticated interaction is required between the hardware and the operating system software, including a hardware translation of every address generated by the processor. The basic idea is to store the contents of a process’s virtual memory on disk and then use the main memory as a cache for the disk.


### 1.7.4 Files
1. **(除了内存及以上的存储器外，所有的都是file! 因为这是操作系统的观点，把他们当作file, 和 Linux 里所讲一样，一切皆文件) A file is a sequence of bytes, nothing more and nothing less. Every I/O device, including disks, keyboards, displays, and even networks, is modeled as a file.**
2. All input and output in the system is performed by reading and writing files, using a small set of system calls known as Unix I/O.
3. (可以提给程序员供一个共用的接口，而不需要关注每个 device 的具体细节，多亏了 POSIX 标准)This simple and elegant notion of a file is nonetheless very powerful because it provides applications with a uniform view of all the varied I/O devices that might be contained in the system.



## 1.8 Systems Communicate with Other Systems Using Networks
1. Up to this point in our tour of systems, we have treated a system as an isolated collection of hardware and software. In practice, modern systems are often linked to other systems by networks.
2. From the point of view of an individual system, the network can be viewed as just another I/O device, as shown in Figure 1.14.
3. When the system copies a sequence of bytes from main memory to the network adapter, the data flow across the network to another machine, instead of, say, to a local disk drive. Similarly, the system can read data sent from other machines and copy these data to its main memory.
4. (网络系统不分家？？？迷惑)With the advent of global networks such as the Internet, copying information from one machine to another has become one of the most important uses of computer systems. 
**注意Figure 15的学习**
5. **From this point, running the hello program remotely involves the five basic steps shown in Figure 1.15.**



## 1.9 Important Themes
1. **This concludes our initial whirlwind tour of systems. An important idea to take away from this discussion is that a system is more than just hardware. It is a collection of intertwined hardware and systems software that must cooperate in order to achieve the ultimate goal of running application programs.**
2. To close out this chapter, we highlight several important concepts that cut across all aspects of computer systems. We will discuss the importance of these concepts at multiple places within the book.

### 1.9.1 Amdahl’s Law
1. The main idea is that when we speed up one part of a system, the effect on the overall sys- tem performance depends on both how significant this part was and how much it sped up.
2. **Even though we made a substantial improvement to a major part of the system, our net speedup was significantly less than the speedup for the one part.**
3. This is the major insight of Amdahl’s law— to significantly speed up the entire system, we must improve the speed of a very large fraction of the overall system.
4. One interesting special case of Amdahl’s law is to consider the effect of setting k to ∞. That is, we are able to take some part of the system and speed it up to the point at which it takes a negligible amount of time.
5. Amdahl’s law describes a general principle for improving any process. In addition to its application to speeding up computer systems, it can guide a company trying to reduce the cost of manufacturing razor blades, or a student trying to improve his or her grade point average. Perhaps it is most meaningful in the world of computers, where we routinely improve performance by factors of 2 or more. Such high factors can only be achieved by optimizing large parts of a system.



### 1.9.2 Concurrency and Parallelism
1. Throughout the history of digital computers, two demands have been constant forces in driving improvements: we want them to do more, and we want them to run faster. Both of these factors improve when the processor does more things at once.
2. **(并发和并行的概念区别) We use the term concurrency to refer to the general concept of a system with multiple, simultaneous activities, and the term parallelism to refer to the use of concurrency to make a system run faster.**
3. (并行的三个层级) Parallelism can be exploited at multiple levels of abstraction in a computer system. We highlight three levels here, working from the highest to the lowest level in the system hierarchy.

#### Thread-Level Concurrency
1. Building on the process abstraction, we are able to devise systems where multiple programs execute at the same time, leading to concurrency. With threads, we can even have multiple control flows executing within a single process.
2. (传统的概念上) Traditionally, this concurrent execution was only simulated, by having a single computer rapidly switch among its executing processes, much as a juggler keeps multiple balls flying through the air. This form of concurrency allows multiple users to interact with a system at the same time, such as when many people want to get pages from a single Web server. It also allows a single user to engage in multiple tasks concurrently, such as having a Web browser in one window, a word processor in another, and streaming music playing at the same time.
3. Until recently, most actual computing was done by a single processor, even if that processor had to switch among multiple tasks. This configuration is known as a uniprocessor system.
4. When we construct a system consisting of multiple processors all under the control of a single operating system kernel, we have a multiprocessor system.
5. Multi-core processors have several CPUs (referred to as “cores”) integrated onto a single integrated-circuit chip. Figure 1.17 illustrates the organization of a typical multi-core processor, where the chip has four CPU cores, each with its own L1 and L2 caches, and with each L1 cache split into two parts—one to hold recently fetched instructions and one to hold data.  The cores share higher levels of cache as well as the interface to main memory.
6. Hyperthreading, sometimes called simultaneous multi-threading, is a tech- nique that allows a single CPU to execute multiple flows of control. It involves having multiple copies of some of the CPU hardware, such as program counters and register files, while having only single copies of other parts of the hardware, such as the units that perform floating-point arithmetic.
7. It enables the CPU to take better advantage of its processing resources.
8. As an example, the In- tel Core i7 processor can have each core executing two threads, and so a four-core system can actually execute eight threads in parallel.
9. **The use of multiprocessing can improve system performance in two ways.**
	1. First, it reduces the need to simulate concurrency when performing multiple tasks. even a personal computer being used by a single person is expected to perform many activities concurrently
	2. Second, it can run a single application program faster, but only if that program is expressed in terms of multiple threads that can effectively execute in parallel


#### Instruction-Level Parallelism
1. At a much lower level of abstraction, modern processors can execute multiple instructions at one time, a property known as instruction-level parallelism.
2. In Chapter 4, we will explore the use of pipelining, where the actions required to execute an instruction are partitioned into different steps and the processor hardware is organized as a series of stages, each performing one of these steps. The stages can operate in parallel, working on different parts of different instructions. We will see that a fairly simple hardware design can sustain an execution rate close to 1 instruction per clock cycle.
3. Processors that can sustain execution rates faster than 1 instruction per cycle are known as superscalar processors.
4. We will see that application programmers can use this model to understand the performance of their programs. They can then write programs such that the gen- erated code achieves higher degrees of instruction-level parallelism and therefore runs faster.


#### Single-Instruction, Multiple-Data (SIMD) Parallelism
1. At the lowest level, many modern processors have special hardware that allows a single instruction to cause multiple operations to be performed in parallel, a mode known as single-instruction, multiple-data (SIMD) parallelism.
2. (应用) These SIMD instructions are provided mostly to speed up applications that process image, sound, and video data.
3. **(程序级使用) Although some compilers attempt to auto- matically extract SIMD parallelism from C programs, a more reliable method is to write programs using special vector data types supported in compilers such as gcc.**


### 1.9.3 The Importance of Abstractions in Computer Systems
1. **The use of abstractions is one of the most important concepts in computer science.**
2. We have already been introduced to several of the abstractions seen in com- puter systems, as indicated in Figure 1.18.

3.(处理器端) On the processor side, the instruction set architecture provides an abstraction of the actual processor hardware. With this abstraction, a machine-code program behaves as if it were executed on a proces- sor that performs just one instruction at a time. The underlying hardware is far more elaborate, executing multiple instructions in parallel, but always in a way that is consistent with the simple, sequential model. By keeping the same execu- tion model, different processor implementations can execute the same machine code while offering a range of cost and performance.

4. (操作系统端) On the operating system side, we have introduced three abstractions: files as an abstraction of I/O devices, virtual memory as an abstraction of program mem- ory, and processes as an abstraction of a running program. To these abstractions we add a new one: the virtual machine, providing an abstraction of the entire computer, including the operating system, the processor, and the programs.



## 1.10 Summary
1. A computer system consists of hardware and systems software that cooperate to run application programs.
2. Information inside the computer is represented as groups of bits that are interpreted in different ways, depending on the context. Programs are translated by other programs into different forms, beginning as ASCII text and then translated by compilers and linkers into binary executable files.
3. Processors read and interpret binary instructions that are stored in main mem- ory.
4. Since computers spend most of their time copying data between memory, I/O devices, and the CPU registers, the storage devices in a system are arranged in a hi- erarchy, with the CPU registers at the top, followed by multiple levels of hardware cache memories, DRAM main memory, and disk storage.
5. Storage devices that are higher in the hierarchy are faster and more costly per bit than those lower in the hierarchy.
6. Storage devices that are higher in the hierarchy serve as caches for de- vices that are lower in the hierarchy. Programmers can optimize the performance of their C programs by understanding and exploiting the memory hierarchy.
7. The operating system kernel serves as an intermediary between the applica- tion and the hardware. It provides three fundamental abstractions:
	1. Files are abstractions for I/O devices.
	2. Virtual memory is an abstraction for both main memory and disks.
	3. Processes are abstractions for the processor, main memory, and I/O devices.
8. Finally, networks provide ways for computer systems to communicate with one another. From the viewpoint of a particular system, the network is just another I/O device.

