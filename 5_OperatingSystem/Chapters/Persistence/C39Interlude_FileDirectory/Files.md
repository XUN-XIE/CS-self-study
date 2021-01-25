one more critical piece to the virtualization puz- zle: __persistent storage__

A persistent-storage device, such as a classic hard disk drive or a more modern solid-state storage device, stores informa- tion permanently (or at least, for a long time).

# CRUX: HOW TO MANAGE A PERSISTENT DEVICE
How should the OS manage a persistent device? What are the APIs? What are the important aspects of the implementation?


# 39.1 Files and Directories
1. Two key abstractions have developed over time in the virtualization of storage:
    * __file__:
        1. A file is simply a linear array of bytes, each of which you can read or write.
        2. Each file has some kind of low-level name, usually a number of some kind(__inode number__)
    * __directory__: 
        1. has a low-level name (i.e., an inode number)
        2. its contents are quite specific: it contains a list of (user-readable name, low-level name) pairs. 

2. The directory hierarchy starts at a root directory (in UNIX-based sys- tems, the root directory is simply referred to as /) and uses some kind of separator to name subsequent sub-directories until the desired file or directory is named.

3. Directories and files can have the same name as long as they are in dif- ferent locations in the file-system tree

4. However, this is usually just a convention: there is usually no enforcement that the data contained in a file named main.c is indeed C source code.

5. Thus, we can see one great thing provided by the file system: a conve- nient way to name all the files we are interested in.

6. Names are important in systems as the first step to accessing any resource is being able to name it. In UNIX systems, the file system thus provides a unified way to access files on disk, USB stick, CD-ROM, many other devices, and in fact many other things, all located under the single directory tree.


# 39.3 Creating Files
1. One important aspect of open() is what it returns: a __file descriptor__.

2. A file descriptor is just an integer, private per process, and is used in UNIX systems to access files; thus, once a file is opened, you use the file de- scriptor to read or write the file, assuming you have permission to do so.

3. In this way, a file descriptor is a capability [L84], i.e., an opaque handle that gives you the power to perform certain operations.

4. Another way to think of a file descriptor is as a pointer to an object of type file; once you have such an object, you can call other “methods” to access the file, like read() and write().


# 39.4 Reading and Writing Files
跟踪可执行文件中的 system call 命令 —— strace(in linux). ( dtruss in Mac OS X 但是用不了)

The strace tool provides an awesome way to see what programs are up to.
By running it, you can trace which system calls a program makes, see the arguments and return codes, and generally get a very good idea of what is going on.


# 39.5 Reading And Writing, But Not Sequentially
1. __lseek__: reposition read/write file offset

2. As you can tell from this description, for each file a process opens, the OS tracks a “current” offset, which determines where the next read or write will begin reading from or writing to within the file.

3. Thus, part of the abstraction of an open file is that it has a current offset, which is updated in one of two ways:
    * The first is when a read or write of N bytes takes place, N is added to the current offset; thus each read or write implicitly updates the offset.
    * The second is explicitly with lseek, which changes the offset as specified above.

4. Note that this call lseek() has nothing to do with the seek operation of a disk, which moves the disk arm. The call to lseek() simply changes the value of a variable within the kernel; when the I/O is performed, depending on where the disk head is, the disk may or may not perform an actual seek to fulfill the request.


### ASIDE: CALLING LSEEK() DOES NOT PERFORM A DISK SEEK
1. The lseek() call simply changes a variable in OS memory that tracks, for a particular process, at which offset to which its next read or write will start.

2. Thus, calling lseek() can certainly lead to a seek in an upcoming read or write, but absolutely does not cause any disk I/O to occur itself.


# 39.6 Writing Immediately with fsync()

# 39.7 Renaming Files with rename()
1. One interesting guarantee provided by the rename() call is that it is (usually) implemented as an atomic call with respect to system crashes;

2. if the system crashes during the renaming, the file will either be named the old name or the new name, and no odd in-between state can arise.

3. Thus, rename() is critical for supporting certain kinds of applications that require an atomic update to file state.


# 39.8 Getting Information About Files with stat()
1. Beyond file access, we expect the file system to keep a fair amount of information about each file it is storing. We generally call such data about __files metadata__.

2. To see the metadata for a certain file, we can use stat() or fstat() system call

3. You can see that there is a lot of information kept about each file, in- cluding:
    size
    low-level name (inode number)
    ownership 
    when the file was accessed or modified

4. As it turns out, each file system usually keeps this type of information in a structure called an __inode__

5. For now, you should just think of an inode as a persistent data structure kept by the file system that has information like we see above inside of it.


# 39.9 Removing Files with unlink()
1. unlink() just takes the name of the file to be removed, and returns zero upon success.


