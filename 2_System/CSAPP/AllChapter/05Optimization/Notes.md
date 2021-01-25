# 5.1 Capabilities and Limitations of Optimizing Compilers
1. (memory aliasing) The case where two pointers may designate the same memory location
2. (问题出在 两个指针可能相等的情况)If a compiler cannot determine whether or not two pointers may be aliased, it must assume that either case is possible, limiting the set of possible optimizations.
3. (问题出在 函数本身 具有 side effect的情况)A second optimization blocker is due to function calls. Most compilers do not try to determine whether a function is free of side effects and hence is a candidate for optimizations such as those attempted in func2. Instead, the compiler assumes the worst case and leaves function calls intact.

As a consequence, programmers using gcc must put more effort into writing programs in a way that simplifies the compiler’s task of generating efficient code.

### Aside Optimizing function calls by inline substitution
1. Code involving function calls can be optimized by a process known as inline substitution (or simply “inlining”), where the function call is replaced by the code for the body of the function
2. This transformation both reduces the overhead of the function calls and allows further optimization of the expanded code.
3. (如何在 C 中使用 inlining) Recent versions of gcc attempt this form of optimization, either when directed to with the command-line option -finline or for optimization level -O1 and higher.
4. (缺陷！) Unfortunately, gcc only attempts inlining for functions defined within a single file. That means it will not be applied in the common case where a set of library functions is defined in one file but invoked by functions in other
files.
5. (不需要 inlining 的情况) 
    1. One is when the code will be evaluated using a symbolic debugger, such as gdb, as described in Section 3.10.2. If a function call has been optimized away via inline substitution, then any attempt to trace or set a breakpoint for that call will fail
    2. The second is when evaluating the performance of a program by profiling, as is discussed in Section 5.14.1. Calls to functions that have been eliminated by inline substitution will not be profiled correctly.


# 5.2 Expressing Program Performance
1. We introduce the metric cycles per element, abbreviated CPE, to express program performance in a way that can guide us in improving the code.
2. (CPE 测量循环用) CPE measure- ments help us understand the loop performance of an iterative program at a detailed level.
    举例：循环中对数组中每个元素处理所花费的 cycles 就是 CPE
3. The sequencing of activities by a processor is controlled by a clock providing a regular signal of some frequency, usually expressed in gigahertz (GHz), billions of cycles per second.


# 5.4 Eliminating Loop Inefficiencies
1. This optimization is an instance of a general class of optimizations known as code motion. They involve identifying a computation that is performed multiple times, (e.g., within a loop), but such that the result of the computation will not change. We can therefore move the computation to an earlier section of the code that does not get evaluated as often.
2. compilers typically very cautious about making transformations that change where or how many times a procedure is called. They cannot reliably detect whether or not a function will have side effects, and so they assume that it might.


# 5.5 Reducing Procedure Calls

# 5.6 Eliminating Unneeded Memory References
1. 就是避免不必要的 取指针值. ( * )
2. In fact, however, the two functions can have different behaviors due to memory aliasing.

# 5.7 Understanding Modern Processors
**two different lower bounds characterize the maximum performance of a program.**
1. The **latency bound** is encountered when a series of operations must be performed in strict sequence, because the result of one operation is required before the next one can begin. This bound can limit program performance when the data dependencies in the code limit the ability of the processor to exploit instruction-level parallelism.
2. The **throughput bound** characterizes the raw computing capacity of the processor’s functional units. This bound becomes the ultimate limit on program performance.

### 5.7.1 Overall Operation
1.  These processors are described in the industry as being superscalar, which means they can perform multiple operations on every clock cycle and out of order, meaning that the order in which instructions execute need not correspond to their ordering in the machine-level program.
2. The overall design has two main parts: the instruction control unit (ICU), which is responsible for reading a sequence of instructions from memory and generating from these a set of primitive operations to perform on program data, and the execution unit (EU), which then executes these operations.


# 5.8 Loop Unrolling
1. Loop unrolling is a program transformation that reduces the number of iterations for a loop by increasing the number of elements computed on each iteration.
2. Loop unrolling can improve performance in two ways.
    * First, it reduces the number of operations that do not contribute directly to the program result, such as loop indexing and conditional branching.
    * Second, it exposes ways in which we can further transform the code to reduce the number of operations in the critical paths of the overall computation.


# 5.9 Enhancing Parallelism
1. As we have noted, however, the functional units performing ad- dition and multiplication are all fully pipelined, meaning that they can start new operations every clock cycle, and some of the operations can be performed by multiple functional units.
2. The hardware has the potential to perform multiplica- tions and additions at a much higher rate, but our code cannot take advantage of this capability, even with loop unrolling, since we are accumulating the value as a single variable acc.
3. The processor no longer needs to delay the start of one sum or product operation until the previous one has completed.
4. **On the other hand, floating-point multiplication and addition are not as- sociative. Thus, combine5 and combine6 could produce different results due to rounding or overflow.**


### 5.9.2 Reassociation Transformation
1. different data dependencies
2. In summary, a reassociation transformation can reduce the number of opera- tions along the critical path in a computation, resulting in better performance by better utilizing the multiple functional units and their pipelining capabilities.
3. (对 integer 没什么用，但是floating 有用)

# 5.11 Some Limiting Factors
1. That is, if there is some chain of data dependencies in a program where the sum of all of the latencies along that chain equals T , then the program will require at least T cycles to execute.
2. We have also seen that the throughput bounds of the functional units also impose a lower bound on the execution time for a program. That is, assume that a program requires a total of N computations of some operation, that the microprocessor has C functional units capable of performing that operation, and that these units have an issue time of I. Then the program will require at least N . I/C cycles to execute.

### 5.11.1 Register Spilling
1. The benefits of loop parallelism are limited by the ability to express the compu- tation in assembly code. If a program has a degree of parallelism P that exceeds the number of available registers, then the compiler will resort to spilling, stor- ing some of the temporary values in memory, typically by allocating space on the run-time stack.
2. Once the number of loop variables exceeds the number of available registers, the program must allocate some on the stack.

### 5.11.2 Branch Prediction and Misprediction Penalties
1. **Do Not Be Overly Concerned about Predictable Branches**
2. **Write Code Suitable for Implementation with Conditional Moves**


# 5.12 Understanding Memory Performance
1. All modern processors contain one or more cache memories to provide fast access to such small amounts of memory
2. investigate the performance of programs that involve load (reading from memory into registers) and store (writing from registers to memory) operations, considering only the cases where all data are held in cache.

# 5.13 Life in the Real World: Performance Improvement Techniques
1. High-level design. Choose appropriate algorithms and data structures for the problem at hand. Be especially vigilant to avoid algorithms or coding techniques that yield asymptotically poor performance.
2. Basic coding principles. Avoid optimization blockers so that a compiler can generate efficient code.
    * Eliminate excessive function calls. Move computations out of loops when possible. Consider selective compromises of program modularity to gain greater efficiency.
    * Eliminate unnecessary memory references. Introduce temporary vari- ables to hold intermediate results. Store a result in an array or global variable only when the final value has been computed.
3. Low-level optimizations. Structure code to take advantage of the hardware capabilities.
    * Unroll loops to reduce overhead and to enable further optimizations.
    * Find ways to increase instruction-level parallelism by techniques such as multiple accumulators and reassociation.
    * Rewrite conditional operations in a functional style to enable compi- lation via conditional data transfers.

# 5.14 Identifying and Eliminating Performance Bottlenecks
1. In this section, we describe how to use code profilers, analysis tools that collect performance data about a program as it executes.

### 5.14.1 Program Profiling
1. Program profiling involves running a version of a program in which instrumenta- tion code has been incorporated to determine how much time the different parts of the program require. It can be very useful for identifying the parts of a program we should focus on in our optimization efforts. One strength of profiling is that it can be performed while running the actual program on realistic benchmark data.
2. Unix systems provide the profiling program gprof. This program generates two forms of information.
    * First, it determines how much CPU time was spent for each of the functions in the program.
    * Second, it computes a count of how many times each function gets called, categorized by which function performs the call.
3. Profiling with gprof requires three steps, as shown for a C program prog.c, which runs with command-line argument file.txt:
    * The program must be compiled and linked for profiling. With gcc (and other C compilers), this involves simply including the run-time flag -pg on the command line. It is important to ensure that the compiler does not attempt to perform any optimizations via inline substitution, or else the calls to functions may not be tabulated accurately. We use optimization flag -Og, guaranteeing that function calls will be tracked properly.
```
gcc -Og -pg prog.c -o prog
```
    * The program is then executed as usual:
```
./prog file.txt
```
It runs slightly (around a factor of 2) slower than normal, but otherwise the only difference is that it generates a file gmon.out.
    * gprof is invoked to analyze the data in gmon.out:
```
gprof prog
```
4. Some properties of gprof are worth noting:

### 5.14.2 Using a Profiler to Guide Optimization
























