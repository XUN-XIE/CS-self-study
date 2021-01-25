**start to learn about operating system**

* Understanding ECF will help you understand important systems concepts.
* Understanding ECF will help you understand how applications interact with the operating system.
* Understanding ECF will help you write interesting new application programs.
* Understanding ECF will help you understand concurrency.
* Understanding ECF will help you understand how software exceptions work.



# 8.1 Exceptions
1. Exceptions are a form of exceptional control flow that are implemented partly by the hardware and partly by the operating system.
2. Because they are partly implemented in hardware, the details vary from system to system. However, the basic ideas are the same for every system
3. An __exception__ is an abrupt change in the control flow in response to some change in the processor’s state.
4. Figure 8.1 异常处理流程图
5. the processor is executing some current instruction Icurr when a significant change in the processor’s state occurs. The state is encoded in various bits and signals inside the processor. The change in state is known as an event.
6. The event might be directly related to the execution of the current instruction. For example, a virtual memory page fault occurs, an arithmetic overflow occurs, or an instruction attempts a divide by zero.
7. On the other hand, the event might be unrelated to the execution of the current instruction. For example, a system timer goes off or an I/O request completes.
8. In any case, when the processor detects that the event has occurred, it makes an indirect procedure call (the exception), through a jump table called an exception table, to an operating system subroutine (the exception handler) that is specifically designed to process this particular kind of event.
9. (三种exception处理方法) When the exception handler finishes processing, one of three things happens, depending on the type of event that caused the exception:
    1. The handler returns control to the current instruction Icurr, the instruction that was executing when the event occurred.
    2. ThehandlerreturnscontroltoInext,theinstructionthatwouldhaveexecuted next had the exception not occurred.
    3. The handler aborts the interrupted program.


### 8.1.1 Exception Handling
1. Exceptions can be difficult to understand because handling them involves close cooperation between hardware and software. It is easy to get confused about which component performs which task.
2. Each type of possible exception in a system is assigned a unique nonnegative integer __exception number__.
3. Some of these numbers are assigned by the designers of the processor. Other numbers are assigned by the designers of the operating system kernel (the memory-resident part of the operating system)
4. Examples of the former include divide by zero, page faults, memory access violations, break- points, and arithmetic overflows. Examples of the latter include system calls and signals from external I/O devices.
5. At system boot time (when the computer is reset or powered on), the operat- ing system allocates and initializes a jump table called an exception table, so that entry k contains the address of the handler for exception k. Figure 8.2 shows the format of an exception table.
6. At run time (when the system is executing some program), the processor detects that an event has occurred and determines the corresponding exception number k. The processor then triggers the exception by making an indirect pro- cedure call, through entry k of the exception table, to the corresponding handler.
7. The exception number is an index into the ex- ception table, whose starting address is contained in a special CPU register called the exception table base register.
8. **exception handler 的地址产生的方式： exception numner * 8 (+特殊处理的加法) Exception table base register = address corresponding to exception table**
9. (异常类似于过程调用，但是有一些区别) An exception is akin to a procedure call, but with some important differences:
    * (过程调用 call 的返回地址是下一条指令；而异常，可能返回下一条指令，也可能返回到本指令) As with a procedure call, the processor pushes a return address on the stack before branching to the handler. However, depending on the class of excep- tion, the return address is either the current instruction or the next instruction
    * (调用异常时， 也会向 stack push 一些处理器的状态) The processor also pushes some additional processor state onto the stack that will be necessary to restart the interrupted program when the handler returns.
    * (过程调用 压入 user stack；异常调用 压入 kernel stack ) When control is being transferred from a user program to the kernel, all of these items are pushed onto the kernel’s stack rather than onto the user’s stack.
    * (过程调用只有 用户级访问权限；异常调用进入内核模式，拥有全部的系统访问权限) Exception handlers run in kernel mode (Section 8.2.4), which means they have complete access to all system resources.

10. Once the hardware triggers the exception, the rest of the work is done in software by the exception handler. After the handler has processed the event, it optionally returns to the interrupted program by executing a special “return from interrupt” instruction, which pops the appropriate state back into the processor’s control and data registers, restores the state to user mode (Section 8.2.4) if the exception interrupted a user program, and then returns control to the interrupted program.


### 8.1.2 Classes of Exceptions
1. **Exceptions can be divided into four classes: interrupts, traps, faults, and aborts.**
2. Figure 8.4 Classes of exceptions. Asynchronous exceptions occur as a result of events in I/O devices that are external to the processor. Synchronous exceptions occur as a direct result of executing an instruction.

**Interrupts**
1. Interrupts occur asynchronously as a result of signals from I/O devices that are external to the processor.
2. Hardware interrupts are asynchronous in the sense that they are not caused by the execution of any particular instruction. Exception handlers for hardware interrupts are often called interrupt handlers.
3. Figure 8.5 summarizes the processing for an interrupt.
4. (中断总览) I/O devices such as network adapters, disk controllers, and timer chips trigger interrupts by signaling a pin on the processor chip and placing onto the system bus the exception number that identifies the device that caused the interrupt.
5. 中断细节：
    * After the current instruction finishes executing, the processor notices that the interrupt pin has gone high, reads the exception number from the system bus, and then calls the appropriate interrupt handler
    * When the handler returns, it returns control to the next instruction (i.e., the instruction that would have followed the current instruction in the control flow had the interrupt not occurred)
**The effect is that the program continues executing as though the interrupt had never happened.**


**The remaining classes of exceptions (traps, faults, and aborts) occur syn- chronously as a result of executing the current instruction. We refer to this in- struction as the faulting instruction.**

**Traps and System Calls**
1. Traps are intentional exceptions that occur as a result of executing an instruction.
2. Like interrupt handlers, trap handlers return control to the next instruction.
3. (traps 的用途) The most important use of traps is to provide a procedure-like interface between user programs and the kernel, known as a system call.
4. User programs often need to request services from the kernel such as reading a file (read), creating a new process (fork), loading a new program (execve), and terminating the current process (exit).
5. To allow controlled access to such kernel services, processors provide a special syscall n instruction that user programs can execute when they want to request service n. Executing the syscall instruction causes a trap to an exception handler that decodes the argument and calls the appropriate kernel routine. 
6. Figure 8.6 summarizes the processing for a system call.
7. **traps对比函数调用**： From a programmer’s perspective, a system call is identical to a regular func- tion call. However, their implementations are quite different.
    * Regular functions run in user mode, which restricts the types of instructions they can execute, and they access the same stack as the calling function.
    * A system call runs in kernel mode, which allows it to execute privileged instructions and access a stack defined in the kernel.


**Faults**
1. Faults result from error conditions that a handler might be able to correct.
2. When a fault occurs, the processor transfers control to the fault handler. If the handler is able to correct the error condition, it returns control to the faulting instruction, thereby re-executing it.
3. Otherwise, the handler returns to an __abort__ routine in the kernel that terminates the application program that caused the fault.
4.  Figure 8.7 summarizes the processing for a fault.
5. **例子**： A classic example of a fault is the page fault exception, which occurs when an instruction references a virtual address whose corresponding page is not res- ident in memory and must therefore be retrieved from disk.


**Aborts**
1. Aborts result from unrecoverable fatal errors, typically hardware errors such as parity errors that occur when DRAM or SRAM bits are corrupted.
2. Abort handlers never return control to the application program.


### 8.1.3 Exceptions in Linux/x86-64 Systems
1. There are up to 256 different exception types
2. Numbers in the range from 0 to 31 correspond to exceptions that are defined by the Intel architects and thus are identical for any x86-64 system.
3. Numbers in the range from 32 to 255 correspond to interrupts and traps that are defined by the operating system.
4. Figure 8.9 shows a few examples.

**Linux/x86-64 Faults and Aborts**
1. Divide error : Unix does not attempt to recover from divide errors, opting instead to abort the program. Linux shells typically report divide errors as __"Floating exceptions"__.
2. General protection fault : The infamous general protection fault (exception 13) occurs for many reasons, usually because a program references an unde- fined area of virtual memory or because the program attempts to write to a read-only text segment. Linux does not attempt to recover from this fault. Linux shells typically report general protection faults as **"Segmentation faults"**.
3. Page fault : The handler maps the appropriate page of virtual memory on disk into a page of physical memory and then restarts the faulting instruction.
4. Machine check : occurs as a result of a fatal hardware error that is detected during the execution of the faulting in- struction. Machine check handlers never return control to the application program.


**Linux/x86-64 System Calls**
1. Linux provides hundreds of system calls that application programs use when they want to request services from the kernel, such as reading a file, writing a file, and creating a new process.
2. (system call 也有一个跳转表！) Figure 8.10 lists some popular Linux system calls. Each system call has a unique integer number that corresponds to an offset in a jump table in the kernel. (Notice that this jump table is not the same as the exception table.)
3. C programs can invoke any system call directly by using the __system__ function.
4. The C standard library provides a set of convenient wrapper functions for most system calls. The wrapper functions package up the arguments, trap to the kernel with the appropriate system call instruction, and then pass the return status of the system call back to the calling program.
5. Throughout this text, we will refer to system calls and their associated wrapper functions interchangeably as __system-level functions__.

6. study how program can use this trapping instruction __syscall__ to invoke Linux system calls directly.
7. (system call 的 arguments 都是通过 通用寄存器传输的，不是 stack) All arguments to Linux system calls are passed through general-purpose registers rather than the stack.
8. register %rax contains the syscall number, with up to six arguments in %rdi, %rsi, %rdx, %r10, %r8, and %r9.
9. **(注意这个 errno 参考 C和指针 书籍！)** A negative return value between −4,095 and −1 indicates an error corresponding to negative __errno__.


# 8.2 Processes
**这个section只写一些点，主要还是看书**
1. **(exception 是 进程 技术的基础) Exceptions are the basic building blocks that allow the operating system kernel to provide the notion of a process, one of the most profound and successful ideas in computer science.**
2. (不解释进程的实现) A detailed discussion of how operating systems implement processes is be- yond our scope. Instead, we will focus on the key abstractions that a process provides to the application:
    * An independent logical control flow that provides the illusion that our pro- gram has exclusive use of the processor.
    * A private address space that provides the illusion that our program has exclu- sive use of the memory system.


### 8.2.1 Logical Control Flow
1. A process provides each program with the illusion that it has exclusive use of the processor, even though many other programs are typically running concurrently on the system.
2. This sequence of PC values is known as a logical control flow, or simply logical flow.

### 8.2.2 Concurrent Flows
4. (Parallel，主要区分它和 concurent ) If two flows are running concurrently on different processor cores or computers, then we say that they are parallel flows, that they are running in parallel, and have parallel execution.
5. concurrent 可以理解成，单核心，同时出现两个 processes
6. 并行可以理解成，多个核心，同时出现多个processes，分别进入不同的核心。实现了并行处理


### 8.2.3 Private Address Space

### 8.2.4 User and Kernel Modes

### 8.2.5 Context Switches

**Operating System: Three Easy Pieces 里没看懂的 context switches，在这里可以稍微理解一点了！！！**


# 8.3 System Call Error Handling
1. When Unix system-level functions encounter an error, they typically return −1 and set the global integer variable errno to indicate what went wrong.
2. Program- mers should always check for errors, but unfortunately, many skip error checking because it bloats the code and makes it harder to read.
3. 解决检查错误代码太长的方法： __wrapper function__
4. **See Appendix A for a discussion of Unix error handling and the error- handling wrappers used throughout this book.**
    


# 8.4 Process Control
Unix provides a number of system calls for manipulating processes from C pro- grams.

### 8.4.1 Obtaining Process IDs
1. Each process has a unique positive (nonzero) process ID (PID).
2. __getpid__ function returns the PID of the calling process.
3. The __getppid__ function returns the PID of its parent (i.e., the process that created the calling process).
```
#include <sys/types.h>
#include <unistd.h>

pid_t getpid(void);
pid_t getppid(void);
// Returns: PID of either the caller or the parent
```
4. The getpid and getppid routines return an integer value of type __pid_t__, which on Linux systems is defined in \<types.h\> as an int.

### 8.4.2 Creating and Terminating Processes
1. From a programmer’s perspective, we can think of a process as being in one of three states:
    * Running. The process is either executing on the CPU or waiting to be executed and will eventually be scheduled by the kernel.
    * Stopped. The execution of the process is suspended and will not be scheduled. A process stops as a result of receiving a SIGSTOP, SIGTSTP, SIGTTIN, or SIGTTOU signal, and it remains stopped until it receives a SIGCONT signal, at which point it becomes running again. (A signal is a form of software interrupt that we will describe in detail in Section 8.5.)
    * Terminated. The process is stopped permanently. A process becomes termi- nated for one of three reasons: 
        (1) receiving a signal whose default action is to terminate the process, 
        (2) returning from the main routine, or 
        (3) calling the exit function.
```
#include <stdlib.h>

void exit(int status);
// This function does not return
```
2. The __exit__ function terminates the process with an exit status of status. (The other way to set the exit status is to return an integer value from the main routine.)
3. A parent process creates a new running child process by calling the __fork__ function.
```
#include <sys/types.h>
#include <unistd.h>

pid_t fork(void);
// Returns: 0 to child, PID of child to parent, −1 on error
```
4. (子进程和父进程的对比，相同处) The newly created child process is almost, but not quite, identical to the parent. The child gets an identical (but separate) copy of the parent’s user-level virtual address space, including the code and data segments, heap, shared libraries, and user stack. The child also gets identical copies of any of the parent’s open file descriptors, which means the child can read and write any files that were open in the parent when it called fork
5. (不同处) The most significant difference between the parent and the newly created child is that they have different PIDs.
6. **The fork function is interesting (and often confusing) because it is called once but it returns twice: once in the calling process (the parent), and once in the newly created child process.**
7. **In the parent, fork returns the PID of the child. In the child, fork returns a value of 0.**
8. **Since the PID of the child is always nonzero, the return value provides an unambiguous way to tell whether the program is executing in the parent or the child.**
9. There are some subtle aspects to this simple example.
    * Call once, return twice. The fork function is called once by the parent, but it returns twice: once to the parent and once to the newly created child. This is fairly straightforward for programs that create a single child. But programs with multiple instances of fork can be confusing and need to be reasoned about carefully.
    * Concurrent execution. The parent and the child are separate processes that run concurrently. The instructions in their logical control flows can be interleaved by the kernel in an arbitrary way. When we run the program on our system, the parent process completes its printf statement first, followed by the child. However, on another system the reverse might be true. In general, as programmers **we can never make assumptions about the interleaving of the instructions in different processes**.
    * Duplicate but separate address spaces. If we could halt both the parent and the child immediately after the fork function returned in each process, we would see that the address space of each process is identical. However, since the parent and the child are separate processes, they each have their own private address spaces. Any subsequent changes that a parent or child makes to x are private and are not reflected in the memory of the other process.
    * Sharedfiles. Whenweruntheexampleprogram,wenoticethatbothparentand child print their output on the screen. The reason is that the child inherits all of the parent’s open files. When the parent calls fork, the stdout file is open and directed to the screen. The child inherits this file, and thus its output is also directed to the screen.

10. When you are first learning about the fork function, it is often helpful to sketch the process graph, which is a simple kind of precedence graph that captures the partial ordering of program statements.
11. **topological sort 对理解 fork 的 process graph 有帮助！！！**


# 8.4.3 Reaping Child Processes
**主要讲解 waitpid 函数，该函数非常复杂，直接看书学习**

1. When a process terminates for any reason, the kernel does not remove it from the system immediately. Instead, the process is kept around in a terminated state until it is reaped by its parent.
2. When the parent reaps the terminated child, the kernel passes the child’s exit status to the parent and then discards the terminated process, at which point it ceases to exist.
3. A terminated process that has not yet been reaped is called a zombie.

# 8.4.5 Loading and Running Programs
**main 函数其实可以写成以下形式，环境变量可以自动传入到main中**
```
int main(int argc, char *argv[], char *envp[]);
```

# 8.4.6 Using fork and execve to Run Programs
1. Programs such as Unix shells and Web servers make heavy use of the fork and execve functions.
2. A shell is an interactive application-level program that runs other programs on behalf of the user.
3. A shell performs a sequence of read/evaluate steps and then terminates. The read step reads a command line from the user. The evaluate step parses the command line and runs programs on behalf of the user.
4. Its first task is to call the parseline function (Figure 8.25), which parses the space-separated command-line arguments and builds the argv vector that will eventually be passed to execve.
5. The first argument is assumed to be either the name of a built-in shell command that is interpreted immediately, or an executable object file that will be loaded and run in the context of a new child process.
6. If the last argument is an ‘&’ character, then parseline returns 1, indicating that the program should be executed in the background (the shell does not wait for it to complete). Otherwise, it returns 0, indicating that the program should be run in the foreground (the shell waits for it to complete).
7. After parsing the command line, the eval function calls the builtin_command function, which checks whether the first command-line argument is a built-in shell command. If so, it interprets the command immediately and returns 1. Otherwise, it returns 0.
8. If builtin_command returns 0, then the shell creates a child process and executes the requested program inside the child. If the user has asked for the program to run in the background, then the shell returns to the top of the loop and waits for the next command line. Otherwise the shell uses the waitpid function to wait for the job to terminate. When the job terminates, the shell goes on to the next iteration.





# 8.5 Signals
**大部头，看书**
1. A signal is a small message that notifies a process that an event of some type has occurred in the system.
2. Each signal type corresponds to some kind of system event. Low-level hard- ware exceptions are processed by the kernel’s exception handlers and would not normally be visible to user processes. Signals provide a mechanism for exposing the occurrence of such exceptions to user processes.
3. 例子见P784 8.5.1上方

### 8.5.1 Signal Terminology
1. The transfer of a signal to a destination process occurs in two distinct steps:
    * Sending a signal.
    * Receiving a signal.

### 8.5.3 Receiving Signals
1. 可以实现接受 键盘 中止 CTRL+C
2. signal 函数，还不是很理解，它在程序中的顺序问题
    根据改变signal的顺序，signal 出现在前面 待处理逻辑前面，用来捕捉 传入的 SIGNALS
    如果在 sleep 或者 pause 后面，signal 甚至不会被 调用
3. 












