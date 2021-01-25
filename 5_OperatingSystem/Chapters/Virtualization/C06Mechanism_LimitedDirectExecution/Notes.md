__time sharing__: The basic idea is simple: run one process for a little while, then run another one, and so forth. By time sharing the CPU in this manner, virtualization is achieved.

challenges:
    * performance
    * control
Attaining performance while maintaining control is thus one of the central challenges in building an operating system.

# Crux P45
HOW TO EFFICIENTLY VIRTUALIZE THE CPU WITH CONTROL
To do so, both hardware and operating systems support will be required. The OS will often use a judicious bit of hardware support in order to accomplish its work effectively.


### 6.1 Basic Technique: Limited Direct Execution
**the process/procedure of pass a procecss into CPU**

OS:                            |     Program:
Create entry for process list  |     
Allocate memory for program    |     
Load program into memory       |     
Set up stack with argc/argv    |     
Clear registers                |     
Execute call main()            |     
                               |     Run main()
                               |     Execute return from main
Free memory of process         |     
Remove from process list       |     


### 6.2 Problem #1: Restricted Operations

# Crux P46 
HOW TO PERFORM RESTRICTED OPERATIONS
A process must be able to perform I/O and some other restricted oper- ations, but without giving the process complete control over the system

**TIP: USE PROTECTED CONTROL TRANSFER**
The hardware assists the OS by providing different modes of execution. In user mode, applications do not have full access to hardware resources. In kernel mode, the OS has access to the full resources of the machine. Special instructions to trap into the kernel and return-from-trap back to user-mode programs are also provided, as well instructions that allow the OS to tell the hardware where the trap table resides in memory.

__user mode --> system call(trap) --> kernel mode --> return-from-trap --> user mode__

kernel mode进出过程中，硬件都要 save 和 restore 信息，比如寄存器，stack等


**trap table**: 明确对应的 exceptional event 应该执行的对应代码！从而可以调用 硬件中 对应的 __trap handlers__

因此 硬件是通过 trap table 记录 对应的 trap handlers 


### 6.3 Problem #2: Switching Between Processes

# Crus P50
HOW TO REGAIN CONTROL OF THE CPU

##### A Cooperative Approach: Wait For System Calls
OS regain control from calling system call or illegal operations by process.
理解成这是 具有"合作"意识的进程，才能使用的方法！因为需要进程，自觉的"合作"

##### A Non-Cooperative Approach: The OS Takes Control
__The addition of a timer interrupt gives the OS the ability to run again on a CPU even if processes act in a non-cooperative fashion__

timer interrupt: 硬件支持，强制使得进程把控制权交回给OS

##### Saving and Restoring Context
__context switch__: all the OS has to do is save a few register values for the currently-executing process (onto its kernel stack, for example) and restore a few for the soon-to-be-executing process (from its kernel stack).

**Table 6.3 Limited Direction Execution Protocol (Timer Interrupt)**

**Figure 6.1 The xv6 Context Switch Code（汇编代码）**


### 6.4 Worried About Concurrency?
locking in second part of the book: to solve the problem if two exceptional events occur at the same time




