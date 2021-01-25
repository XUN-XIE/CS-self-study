* fork
* exec
* wait

# CRUX P35 
HOW TO CREATE AND CONTROL PROCESSES

### fork    (Mac man page "fork")
1. PID
2. non-determinism

### wait    (Mac man page "waitpid")
to be deterministic

### exec    (Mac man page "execvp")
1. This system call is useful when you want to run a program that is different from the calling program
2. calling fork() in p2.c is only useful if you want to keep running copies of the same program

__it loads code (and static data) from that executable and over- writes its current code segment (and current static data) with it; the heap and stack and other parts of the memory space of the program are re- initialized.__

__it transforms the currently running program (formerly p3) into a different running program (wc). After the exec() in the child, it is almost as if p3.c never ran; a successful call to exec() never returns.__


### 5.4 Why? Motivating the API
1. **(shell 的实现)** separation of fork() and exec() is essential in building a UNIX shell, because it lets the shell run code after the call to fork() but before the call to exec()
2. **(redirect 实现)** when the child is created, before calling exec(), the shell closes standard output and opens the file newfile.txt.
3. **(file descriptor 协助实现 redirect)** UNIX systems start looking for free file descriptors at zero. In this case, STDOUT FILENO will be the first available one and thus get assigned when open() is called. Subsequent writes by the child process to the standard output file descriptor, for ex- ample by routines such as printf(), will then be routed transparently to the newly-opened file instead of the screen.

4. **(pipe 实现)** UNIX pipes are implemented in a similar way, but with the pipe() system call. the output of one process is connected to an in- kernel pipe (i.e., queue), and the input of another process is connected to that same pipe; thus, the output of one process seamlessly is used as input to the next, and long and useful chains of commands can be strung together.

**the fork()/exec() combination is a powerful way to create and manipulate processes.**

**Spending some time reading man pages is a key step in the growth of a systems programmer**



