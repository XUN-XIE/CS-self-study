/*************************************************************************
 @Author: XieXun
 @Created Time : Tue 22 Dec 14:56:14 2020
 @File Name: func.h
 @Description:
 ************************************************************************/
#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

// 逻辑任务
// 1. 读取命令行
// 2. 跟踪指令


typedef struct {
    int v;
    int s;
    int E;
    int b;
    char filename[FILENAME_MAX];
} CommandInfo;

CommandInfo *
readPar( register char * argv[] );

// 跟踪指令
// 1. 读取文件
// 2. 分割每一行为 operator address,size
// 3. 记录 三者
// 4. 进入 cache memory 的策略
//
// 读取文件，两个方法：
// 1. 静态读取，没读取一行，进入第四部处理一行
// 2. 动态内存，先把所有的行都读出来，保存起来，再逐一进行操作
//
// 个人感觉，第二个方法简单一些，方便 debug。但是耗费太多的内存
// 所以采用第一个方法，静态读取，读一行就处理一行！
//
//
// 思考主逻辑
//
// 仿照 cache 进行
// E = 1 比较简单
// address拆分成 三部分！
// 
// 根据书中的逻辑，三步走
// 1. 判断 set 
// 2. 行匹配，这里假设 E = 1 。直接选择 tag 判断
// 3. 字节偏移
// 但是，hit miss只需要判断前两个条件即可！！！！
//
// set数组，用于判断，当前set是否被填充到。如果对应为 1， 则下一步，如果为 0 ，miss，并且设置为1
// tag数组，动态保存，已经储存过的 tag。 进行线性搜索，如果找对对应的就 hit， 如果没有对应的，说明冲突，eviction
//
// 所以建立一个二维数组 arr[Sets][EE] 即可

// 表示 一个 set 的情况
typedef struct {
    int warm;
    unsigned * tags;
    unsigned * record_E_used;
} SetInfo;


typedef struct {
    int hit;
    int miss;
    int eviction;
} HMEres;

typedef struct {
    unsigned H;
    unsigned M;
    unsigned E;
} CountAll;


void
LRU_update( unsigned * record, unsigned target, int size );


HMEres *
HitMissEvi(unsigned set, unsigned tag, register SetInfo * cache, unsigned EE);


void
print_res(register const HMEres * res);


void
updateCount( const HMEres * res, CountAll * count );

CountAll *
MainLogic( CommandInfo * Info );


#endif
