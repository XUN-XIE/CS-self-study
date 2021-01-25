Header files generally contain definitions of data types, function prototypes and C preprocessor commands.

# utility project

wcat 已完成
wgrep 需要用到字符串查找算法：见算法Robert 第五章，第三节和第四节！
wzip, wunzip 需要用到压缩算法：见算法Robert 第五章，第五节



# reverse project
开始使用 字符串数组 动态管理获取的行

```
char ** linearr = (char **)malloc(sizeof(char));
```
但是失败了，最后debug出问题是
linearr 通过整数加上后，分别以 8 字节， 2 字节间隔增长！不知道原因

最后通过 struct 当作动态管理的元素
```
struct line
{
    char * text;
    unsigned len; // 这行不要也行
};
```
还是不成功，出现了问题，使用reverse.c 本身当作输入，会出现 segmentation fault。以后再做吧

最后使用了链表结构，避免了指针莫名其妙的增长，成功解决


# shell
1. execvp 接口
    * argv 第一个参数必须为程序名
    * 最后一个元素必须为NULL
2. 文件流和字符进程。复杂，采用了最保险的方式，在父进程处理完行后，只调用 子进程执行 exec


做项目的小感悟：
需求是总体的！不能一个一个挨着看，会导致自己的设计架构不对
比如这次shell项目，现实一步一步的看 README 要求一个一个顺着实现。结果到最后才发现，有些逻辑是反过来的
题外话：体会到 产品额外加需求，摧残开发的感觉了，哈哈哈

test7,11 不够稳定，有时会出现错误 139，但是有时候又能通过测试。需要改进程序最后发现问题其实就是 segmentation fault！！！

内存管理：
如果是管理 字符串数组，不妨用用笨主意，牺牲掉复制的效率！每次需要 复制 字符串时，不复制指针，而是整个把 字符串 strcpy 过去，然后删除掉旧的，这样保证了内存管理的安全性！





