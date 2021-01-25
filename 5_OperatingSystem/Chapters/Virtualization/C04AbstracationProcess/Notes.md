Process is a running program

# Crux 1 P 25
HOW TO PROVIDE THE ILLUSION OF MANY CPUS?

1. __time sharing__(提供 CPU virtualization): This basic technique, known as time sharing of the CPU, allows users to run as many concurrent processes as they would like; the potential cost is performance, as each will run more slowly if the CPU(s) must be shared.

__CPU 虚拟化，由两部分组成 硬件层面的 mechanism 和 软件层面的 policies__
2. __context switch__(硬件层面): con- text switch, which gives the OS the ability to stop running one program and start running another on a given CPU
3. __policies__(软件层面): Policies are algorithms for making some kind of decision within the OS.
4. scheduling policy in the OS will make this decision, likely using 
    * historical information (which program has run more over the last minute?)
    * workload knowledge (what types of programs are run)
    * perfor- mance metrics (is the system optimizing for interactive performance, or throughput?)
to make decision


### 4.1 The Abstraction: A Process
1. process is the abstracation provided by the OS of a runing program

process have its specific __machine state__:
    * memory (address space)
    * register
    * program counter (PC)
    * instruction pointer (IP)
    * stack pointer
    * frame pointer
    * persistent storage devices

### 4.2 Process API
API that all OSes must be included

### 4.3 Process Creation: A Little More Detail
1. first step: load data from disk to memory or address space (program is also data in disk)!
2. modern OSes load lazily! by loading pieces of code or data only as they are needed during program execution.
3. allocate run-time stack for process (initial environment argument. argc and argv in main function)
4. allocate heap for process
5. intialize I/O devices

**By loading the code and static data into memory, by creating and ini- tializing a stack, and by doing other work as related to I/O setup, the OS has now (finally) set the stage for program execution.**

6. It thus has one last task: to start the program running at the entry point, namely main().
7. By jumping to the main() routine , the OS transfers control of the CPU to the newly-created process, and thus the program begins its execution.

### 4.4 Process States
In a simplified view, a process can be in one of three states:
    * Running
    * Ready: 
    * Blocked: have performed some operations, but not ready(I/O request) to run until other event happened(I/O completion)


### 4.5 Data Structures
1. key data structures that track various relevant pieces of information.
2. __process list__: data structure to track states of all processes (including all above three kinds of processes)
3. 








