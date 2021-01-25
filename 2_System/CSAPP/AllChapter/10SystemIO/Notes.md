本章内容能实现很多常用的 命令行 程序，比如:cd, ls, etc.

Most of the time, the higher-level I/O functions work quite well and there is no need to use Unix I/O directly. So why bother learning about Unix I/O?
    * Understanding Unix I/O will help you understand other systems concepts. we often encounter circular dependencies between I/O and other systems ideas. For example, I/O plays a key role in process creation and execution. Conversely, process creation plays a key role in how files are shared by different processes.
    * Sometimes you have no choice but to use Unix I/O. the standard I/O library provides no way to access file metadata such as file size or file creation time. Further, there are problems with the standard I/O library that make it risky to use for network program- ming.

# 10.1 Unix I/O
1. All I/O devices, such as networks, disks, and terminals, are modeled as files, and all input and output is performed by reading and writing the appropriate files.
2. enables all input and output to be performed in a uniform and consistent way:
    1. Opening files: The kernel keeps track of all information about the open file. The application only keeps track of the descriptor.
    2. Changing the current file position: The file position is a byte offset from the beginning of a file.
    3. (explain EOF) Reading and writing files: A read operation copies n > 0 bytes from a file to memory, starting at the current file position k and then incrementing k by n. Given a file with a size of m bytes, performing a read operation when k ≥ m triggers a condition known as end-of-file (EOF), which can be detected by the application. There is no explicit “EOF character” at the end of a file.
    4. Closing files: The kernel responds by freeing the data structures it created when the file was opened and restoring the descriptor to a pool of available descriptors. When a process terminates for any reason, the kernel closes all open files and frees their memory resources.


# 10.2 Files
1. Each Linux file has a type that indicates its role in the system:
    * A regular file contains arbitrary data. 
        1. Application programs often distinguish between text files, which are regular files that contain only ASCII or Unicode characters, and binary files, which are everything else.
        2. To the kernel there is no difference between text and binary files.
    * A directory is a file consisting of an array of links, where each link maps a filename to a file, which may be another directory. 
    * A socket is a file that is used to communicate with another process across a network

2. Other file types include named pipes, symbolic links, and character and block devices, which are beyond our scope.

3. As part of its context, each process has a current working directory that identifies its current location in the directory hierarchy

4. Locations in the directory hierarchy are specified by pathnames.


# 10.3 Opening and Closing Files
```
int open(char *filename, int flags, mode_t mode);
```
1. The flags argument indicates how the process intends to access the file
2. (实现了每个文件的九个权限！rwxrwxrwx) The mode argument specifies the access permission bits of new files


# 10.4 Reading and Writing Files
1. In some situations, read and write transfer fewer bytes than the application requests. Such short counts do not indicate an error. They occur for a number of reasons:
    * Encountering EOF on reads
    * Reading text lines from a terminal(i.e., a keyboard and display)
    * Reading and writing network sockets: internal buffering constraints and long net- work delays can cause read and write to return short counts. Short counts can also occur when you call read and write on a Linux pipe, an inter- process communication mechanism that is beyond our scope.

2. __On x86-64 systems, a size_t is defined as an unsigned long, and an ssize_t (signed size) is defined as a long.__

3. In practice, you will never encounter short counts when you read from disk files except on EOF, and you will never encounter short counts when you write to disk files

4. However, if you want to build robust (reliable) network applications such as Web servers, then you must deal with short counts by repeatedly calling read and write until all requested bytes have been transferred.


# 10.5 Robust Reading and Writing with the Rio Package
1. Rio (Robust I/O) package, that handles these short counts for you automatically. The Rio package provides convenient, robust, and efficient I/O in applications such as network programs that are subject to short counts.
2. Rio provides two different kinds of functions:
    * Unbuffered input and output functions.
    * Buffered input functions.

3. We are presenting the Rio routines for two reasons. 
    First, we will be using them in the network applications we develop in the next two chapters. 
    Second, by studying the code for these routines, you will gain a deeper understanding of Unix I/O in general.


个人理解重点在于，新设计的 rio_read 实现了 buffer Input，把输入存储在 buffer 中，这样可以避免 每次只读取一个字符 都要发生 trap 的巨大开销


# 10.8 Sharing Files
1. The kernel represents open files using three related data structures:
    * Descriptor table
    * File table
    * v-node table

2. Multiple descriptors can also reference the same file through different file table entries, as shown in Figure 10.13. This might happen, for example, if you were to call the open function twice with the same filename. The key idea is that each descriptor has its own distinct file position, so different reads on different descriptors can fetch data from different locations in the file.

3. We can also understand how parent and child processes share files. An important consequence is that the parent and child must both close their descriptors before the kernel will delete the corresponding file table entry.


# 10.11 Putting It Together: Which I/O Functions Should I Use?
1. So which of these functions should you use in your programs? Here are some basic guidelines:
    G1: Use the standard I/O functions whenever possible. 
    G2: Don’t use scanf or rio_readlineb to read binary files.
    G3: Use the Rio functions for I/O on network sockets.

2. Standard I/O streams are full duplex in the sense that programs can perform input and output on the same stream. However, there are poorly documented restrictions on streams that interact badly with restrictions on sockets:
    Restriction 1: Input functions following output functions. An input function cannot follow an output function without an intervening call to fflush, fseek, fsetpos, or rewind. The fflush function empties the buffer as- sociated with a stream. The latter three functions use the Unix I/O lseek function to reset the current file position.
    Restriction 2: Output functions following input functions. An output function cannot follow an input function without an intervening call to fseek, fsetpos, or rewind, unless the input function encounters an end-of-file.

