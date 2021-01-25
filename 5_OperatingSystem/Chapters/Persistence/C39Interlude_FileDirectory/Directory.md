# 39.10 Making Directories
1. Note you can never write to a directory directly;  because the format of the directory is considered file system meta- data, you can only update a directory indirectly by creating files, directories, or other object types within it.

2. an empty directory has two entries: one entry that refers to itself, and one entry that refers to its parent.

# 39.11 Reading Directories
1. command __ls__ 实现：
    opendir(), readdir(), and closedir()
    struct __DIR__ to store information

# 39.13 Hard Links
1. We now come back to the mystery of why removing a file is performed via unlink(), by understanding a new way to make an entry in the file system tree, through a system call known as link().

2. The link() system call takes two arguments, an old pathname and a new one; when you “link” a new file name to an old one, you essentially create another way to refer to the same file.

3. The way link works is that it simply creates another name in the di- rectory you are creating the link to, and refers it to the same inode number (i.e., low-level name) of the original file.

4. 创建一个文件，其实有两个步骤，第一步是 新建了 inode 结构（数据的真正储存位置）。第二步 是 link 一个filename给这个 inode！
By now you might be starting to see why unlink() is called unlink(). When you create a file, you are really doing two things. First, you are making a structure (the inode) that will track virtually all relevant infor- mation about the file, including its size, where its blocks are on disk, and so forth. Second, you are linking a human-readable name to that file, and putting that link into a directory.

5. Thus, to remove a file from the file system, we call unlink(). The reason this works is because when the file system unlinks file, it checks a __reference count__ within the inode number. This reference count (sometimes called the link count) allows the file system to track how many different file names have been linked to this particular inode. When unlink() is called, it removes the “link” between the human-readable name (the file that is being deleted) to the given inode number, and decre- ments the reference count; only when the reference count reaches zero does the file system also free the inode and related data blocks, and thus truly “delete” the file.



# 39.14 Symbolic Links
1. There is one other type of link that is really useful, and it is called a symbolic link or sometimes a soft link.

2. As it turns out, hard links are somewhat limited:
    * you can’t create one to a directory (for fear that you will create a cycle in the directory tree);
    * you can’t hard link to files in other disk partitions (because inode numbers are only unique within a particular file system, not across file systems); 

3. However, beyond this surface similarity, symbolic links are actually quite different from hard links:
    * The first difference is that a symbolic link is actually a file itself, of a different type. We’ve already talked about regular files and directories; symbolic links are a third type the file system knows about.
    * the way a symbolic link is formed is by holding the pathname of the linked-to file as the data of the link file. If we link to a longer pathname, our link file would be bigger:
    * Finally, because of the way symbolic links are created, they leave the possibility for what is known as a dangling reference:
        removing the original file named file causes the link to point to a pathname that no longer exists.


# 39.15 Making and Mounting a File System
how to assemble a full directory tree from many underlying file systems.
This task is accomplished via first making file systems, and then mounting them to make their contents accessible.

1. To make a file system, most file systems provide a tool, usually re- ferred to as mkfs (pronounced “make fs”), that performs exactly this task.
2. The idea is as follows: give the tool, as input, a device (such as a disk partition, e.g., /dev/sda1) a file system type (e.g., ext3), and it simply writes an empty file system, starting with a root directory, onto that disk partition. And mkfs said, let there be a file system!

3. However, once such a file system is created, it needs to be made ac- cessible within the uniform file-system tree. This task is achieved via the mount program (which makes the underlying system call mount() to do the real work).
4. What mount does, quite simply is take an existing direc- tory as a target mount point and essentially paste a new file system onto the directory tree at that point.








