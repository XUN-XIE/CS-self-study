#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
 #include "cachelab.h"
// 逻辑任务
// 1. 读取命令行
// 2. 跟踪指令

// 跟踪，可以考虑用宏 #if 掉其中 v 的选项
#define NUMC 5
const char * command[NUMC] = {
    "-v", "-s", "-E", "-b", "-t"
};

typedef struct {
    int v;
    int s;
    int E;
    int b;
    char filename[FILENAME_MAX];
} CommandInfo;

CommandInfo *
readPar( register char * argv[] )
{
    // 忽略第一个参数，文件名
    argv++;
    // 保存结果的结构指针
    CommandInfo * res = (CommandInfo *) malloc(sizeof(CommandInfo));    // 记住要 free 这个结构指针
    res->v = 0;
    // 如果argv读到末尾 为NULL 自动退出
    while (*argv)
    {
        int target = -1;
        // 选择对应 command
        for (int i = 0; i < NUMC; i++)
        {
            /*
            // debug 用
            printf("now command is          |%s|. command[%d] = |%s|\n", *argv, i, command[i]);
            printf("%lu %lu\n", strlen(*argv), strlen(command[i]));
            */
            if ( !strcmp( *argv, command[i]) )
                target = i;
        }
        // 用于 debug
        if (target == -1)
        {
            printf("\033[41mno command read in!\n\033[0m");
            exit(1);
        }

        switch (target) {
            case 0: // -v
                res->v = 1;
                break;
            case 1: // -s
                res->s = atoi( *++argv );    // ++argv 实现argv后移，不让 target 搜寻结果为 -1
                break;
            case 2: // -E
                res->E = atoi( *++argv );
                break;
            case 3: // -b
                res->b = atoi( *++argv );
                break;
            case 4: // -t
                 strcpy( res->filename, *++argv );
                break;
        }
        argv++;
    }
    return res;
}

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
LRU_update( unsigned * record, unsigned target, int size )
{
    // 如果 target 就在最后，直接返回
    if (record[size - 1] == target)
        return;
    int index;
    int start_exchange = 0;
    for (int i = 0; i < size; i++)
    {
        if (start_exchange)
        {
            record[i - 1] = record[ i ];
        }
        if ( !start_exchange && record[i] == target)
            index = i;
    }
    record[size - 1] = target;
}

HMEres *
HitMissEvi(unsigned set, unsigned tag, register SetInfo * cache, unsigned EE)
{
    HMEres * res = (HMEres *)malloc(sizeof(HMEres));
    res->hit = res->miss = res->eviction = 0;
    
    // 查找 set
    // 如果 对应 set 还没有激活 直接返回 miss
    if (!cache[set].warm)
    {
        // debug
        // printf("%u %u\n", set, tag);

        cache[set].warm = 1;

        res->miss = 1;
        // 修改 cache 的值
        cache[set].tags[0] = tag;
        LRU_update(cache->record_E_used, 0, EE);
        return res;
    }

    // 现在表明 set 已经激活，进入第二步，检查 tag
    // 遍历所有的 tags，如果找到对应的，直接返回 hit
    int index;
    // 记录最后一个空位
    int record_last_valid = -1;
    for (index = 0; index < EE; index++)
    {
        unsigned tag_value = cache[set].tags[index];
        // 如果 tag_value 仍然是 0，说明有空余！
        if ( tag_value == UINT_MAX )
            record_last_valid = index;
        // 判断是否有 tag 和 tags中 命中
        if ( tag == tag_value )
        {
            res->hit = 1;
            LRU_update(cache->record_E_used, index, EE);
            return res;
        }
    }
    
    // 如果没有找到，说明出现了 miss
    res->miss = 1;
    
    // 这时还要判断是否 eviction！

    // 如果仍然有空位！
    if ( record_last_valid != -1 )
    {
        cache[set].tags[record_last_valid] = tag;
        LRU_update(cache->record_E_used, record_last_valid, EE);
        return res;
    }
    else    // 没有空位，需要 eviction
    {
        res->eviction = 1;
        // LRU 策略替换行
        // 每次使用一个行号，就把该行号放在数组最后，这样第一个元素，就是 LRU 替换的目标
        unsigned target_evict = cache[set].record_E_used[0];
        cache[set].tags[target_evict] = tag;
        return res;
    }

    printf("\033[41mSomething wrong happened in HitMissEvi Function.\033[0m\n");
    exit(1);
    return res;
}

void
print_res(register const HMEres * res)
{
    if ( res->hit )
        printf("hit ");
    if ( res->miss )
        printf("miss ");
    if ( res->eviction )
        printf("eviction ");

    if ( !(res->hit || res->miss || res->eviction ) )
        printf("\033[41mSomething wrong happend in print_res, because all three hit miss evic is 0\033[0m\n");
}

void
updateCount( const HMEres * res, CountAll * count )
{
    if ( res->hit )
        count->H++;
    if ( res->miss )
        count->M++;
    if ( res->eviction )
        count->E++;
}


CountAll *
MainLogic( CommandInfo * Info )
{
    int v = Info->v;
    // 计算 Set Block EE 的大小
    unsigned Set = pow(2, Info->s);
    unsigned Block = pow(2, Info->b);
    unsigned EE = Info->E;
    
    // 打开文件
    register FILE * input;
    input = fopen( Info->filename, "r" );
    if ( input == NULL )
    {
        perror( Info->filename );
        exit( EXIT_FAILURE );
    }
   
    /*
    // 声明保存 cache 的二维数组
    unsigned ** arr = (unsigned **)malloc(Set * sizeof(unsigned *));
    for (int i = 0; i < Set; i++)
        arr[i] = (unsigned *)calloc(EE, sizeof(unsigned));
    */

    // 声明和初始化 保存 cache 的数组
    register SetInfo * AllSets = (SetInfo *)malloc(Set * sizeof(SetInfo));
    for (int i = 0; i < Set; i++)
    {
        AllSets[i].warm = 0;
        AllSets[i].tags = (unsigned *)calloc(EE, sizeof(unsigned));
        // 不能用 0 作为 tag 的默认值，因为 0 是有效的tag 中的一个
        for (int j = 0; j < EE; j++)
            AllSets[j].tags[j] = UINT_MAX;
        AllSets[i].record_E_used = (unsigned *)calloc(EE, sizeof(unsigned));
        // LRU 策略，每个元素储存 line 行号
        for (int j = 0; j < EE; j++)
            AllSets[i].record_E_used[j] = j;
    }

    // 记录返回值
    unsigned countH = 0;
    unsigned countM = 0;
    unsigned countE = 0;
    CountAll * returned = (CountAll *)malloc(sizeof(CountAll *));
    returned->H = returned->M = returned->E = 0;


    // 转换每一行的信息
    char instruction;
    long address;
    unsigned size;
    while ( fscanf( input, " %c %lx,%u", &instruction, &address, &size ) != EOF )
    {
        // printf("%c  %lx,%u\n", instruction, address, size);
        if (instruction == 'I')
            continue;
        // 访问的目标 set 和 目标 block
        unsigned toBlock = address & ( Block - 1 );
        unsigned toSet = (address >> Info->b) & ( Set - 1 );
        unsigned toTag = ( address >> (Info->b + Info->s) ) & ( (unsigned)pow(2,Info->b+Info->s) - 1 );
        // printf("toSet = %u, toBlock = %u, toTag = %u\n\n", toSet, toBlock, toTag); 
        
        // 打印 原始的指令信息
        if (v)
            printf("%c  %lx,%d  ", instruction, address, size);
        switch(instruction) {
            // 这两个指令 相同
            case 'L':
            case 'S':
                {
                    HMEres * res1 = HitMissEvi(toSet, toTag, AllSets, EE);
                    if (v)
                        print_res( res1 );
                    updateCount( res1, returned );
                    free(res1);
                    break;
                }
            // M 指令特殊，相当于 先 L 再 S
            case 'M':
                {
                    HMEres * res2 = HitMissEvi(toSet, toTag, AllSets, EE);
                    if (v)
                        print_res( res2 );
                    updateCount( res2, returned );
                    free(res2);
                    
                    HMEres * res3 = HitMissEvi(toSet, toTag, AllSets, EE);
                    if (v)
                        print_res( res3 );
                    updateCount( res3, returned );
                    free(res3);
                    
                    break;
                }
            default:
                {
                    printf("\033[41mYou met some error in handle with Instruction\033[0m\n");
                    printf("the Instruction is %c\n", instruction);
                    exit(1);
                } 
        }
        if (v)
            printf("\n");
    }
    
    // 释放内存
    for (int i = 0; i < Set; i++)
    {
        free(AllSets[i].tags);
        free(AllSets[i].record_E_used);
    }
    free(AllSets);

    // 关闭文件
    if ( fclose( input ) != 0 )
    {
        perror( "fclose" );
        exit( EXIT_FAILURE );
    }
    return returned;
}

int main( int argc, char *argv[] )
{
    CommandInfo * Info = readPar( argv );
    // printf("-s = %d, -E = %d, -b = %d, -t = %s\n", Info->s, Info->E, Info->b, Info->filename);
    CountAll * count = MainLogic( Info );
    free(Info);    
    printSummary(count->H, count->M, count->E);
    free(count);
    return 0;
}
