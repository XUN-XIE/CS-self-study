失败了

写完后，第一个只测试 malloc 就失败了

原因：可编程的 mm.c 文件中，mm_malloc 就是最外层的接口
用于给 测试程序 mdriver 进行调用

测试文件，trace/short1-bal.rep


但是问题出现在 第二次调用 mm_malloc
第一次调用结束后，检查所有的 block 和指针位置，以及存储的值都是正确的

但是！！！第二次调用进入 mm_malloc 时，free block的 header 和 刚加入的 allocated block 的 footer 指针存放的值被篡改成 0 了。经过长时间的 debug 也没有找出原因。因为这是最外层的接口，所以找不到问题出在哪

留待下次解决
