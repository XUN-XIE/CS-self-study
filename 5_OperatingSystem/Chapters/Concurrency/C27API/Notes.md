# Crux P279
HOW TO CREATE AND CONTROL THREADS
What interfaces should the OS present for thread creation and control? 
How should these interfaces be designed to enable ease of use as well as utility?

# pthread_join
used for thread completion

Note:
1. (second argument is pointer to pointer to void)The second argument is a pointer to the return value you expect to get back. because the pthread join() routine changes the value of the passed in argument, you need to pass in a pointer to that value, not just the value itself.

2. if we just create a thread with no arguments, we can pass NULL in as an argument when the thread is created. Similarly, we can pass NULL into pthread join() if we don’t care about the return value.

3. (thread_create need to return the pointer reference to value from heap of thread)Third, we should note that one has to be extremely careful with how values are returned from a thread. In particular, never return a pointer which refers to something allocated on the thread’s call stack.

4. We should note that not all code that is multi-threaded uses the join routine. 
     (多线程网络服务器不需要 结束线程)multi-threaded web server might create a number of worker threads, and then use the main thread to accept requests and pass them to the workers, indefinitely. Such long-lived programs thus may not need to join.
     (并行编程需要结束线程)However, a parallel program that creates threads to execute a particular task (in parallel) will likely use join to make sure all such work completes before exiting or moving onto the next stage of computation.


# 27.3 Locks
the next most useful set of functions provided by the POSIX threads library are those for providing mutual exclusion to a critical section via __locks__

1. When you have a region of code you realize is a critical section, and thus needs to be pro- tected by locks in order to operate as desired. You can probably imagine what the code looks like:
```
pthread_mutex_t lock;
pthread_mutex_lock(&lock);
x = x + 1; // or whatever your critical section is 
pthread_mutex_unlock(&lock);
```
The intent of the code is as follows: if no other thread holds the lock when pthread mutex lock() is called, the thread will acquire the lock and enter the critical section. If another thread does indeed hold the lock, the thread trying to grab the lock will not return from the call until it has acquired the lock (implying that the thread holding the lock has released it via the unlock call).
Of course, many threads may be stuck waiting inside the lock acquisition function at a given time; only the thread with the lock acquired, however, should call unlock.

2. Unfortunately, this code is broken, in two important ways:
    * The first problem is a lack of proper initialization. All locks must be properly initialized in order to guarantee that they have the correct values to begin with and thus work as desired when lock and unlock are called.
    * The second problem with the code above is that it fails to check errors code when calling lock and unlock. If your code doesn’t properly check error codes, the failure will happen silently, which in this case could allow multiple threads into a critical section

# 27.4 Condition Variables
1. Condition variables are useful when some kind of signaling must take place between threads, if one thread is waiting for another to do something be- fore it can continue.
2. To use a condition variable, one has to in addition have a lock that is associated with this condition. When calling either of the above routines, this lock should be held.

```
// one thread function
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 
pthread_cond_t init = PTHREAD_COND_INITIALIZER;

Pthread_mutex_lock(&lock); 
while (initialized == 0)
    Pthread_cond_wait(&init, &lock); 
Pthread_mutex_unlock(&lock);

// another thread function
Pthread_mutex_lock(&lock);
initialized = 1;
Pthread_cond_signal(&init);
Pthread_mutex_unlock(&lock);
```

Notes:
    * (exchange lock to another thread) the wait call takes a lock as its second parameter, whereas the signal call only takes a condition. The reason for this difference is that the wait call, in addition to putting the call- ing thread to sleep, releases the lock when putting said caller to sleep. Imagine if it did not: how could the other thread acquire the lock and signal it to wake up? However, before returning after being woken, the pthread cond wait() re-acquires the lock, thus ensuring that any time the waiting thread is running between the lock acquire at the beginning of the wait sequence, and the lock release at the end, it holds the lock.
    * (view waking up as might have changed rather than an absolute fact) Although it rechecks the condition (perhaps adding a little overhead), there are some pthread implementations that could spuriously wake up a waiting thread; in such a case, without rechecking, the waiting thread will continue thinking that the condition has changed even though it has not. It is safer thus to view waking up as a hint that something might have changed, rather than an absolute fact.


# 27.5 Compiling and Running
To compile them, you must include the header pthread.h in your code. On the link line, you must also explicitly link with the pthreads library, by adding the -pthread flag.
```
prompt> gcc -o main main.c -Wall -pthread
```


### ASIDE: THREAD API GUIDELINES
There are a number of small but important things to remember when
you use the POSIX thread library (or really, any thread library) to build a multi-threaded program. They are:
    • Keep it simple. Above all else, any code to lock or signal between threads should be as simple as possible. Tricky thread interactions lead to bugs.
    • Minimize thread interactions. Try to keep the number of ways in which threads interact to a minimum. Each interaction should be carefully thought out and constructed with tried and true ap- proaches (many of which we will learn about in the coming chap- ters).
    • Initialize locks and condition variables. Failure to do so will lead to code that sometimes works and sometimes fails in very strange ways.
    • Check your return codes. Of course, in any C and UNIX program- ming you do, you should be checking each and every return code, and it’s true here as well. Failure to do so will lead to bizarre and hard to understand behavior, making you likely to (a) scream, (b) pull some of your hair out, or (c) both.
    • Be careful with how you pass arguments to, and return values from, threads. In particular, any time you are passing a reference to a variable allocated on the stack, you are probably doing something wrong.
    • __Each thread has its own stack__. As related to the point above, please remember that each thread has its own stack. Thus, if you have a locally-allocated variable inside of some function a thread is exe- cuting, it is essentially private to that thread; no other thread can (easily) access it. To share data between threads, the values must be in the heap or otherwise some locale that is globally accessible.
    • Always use condition variables to signal between threads. While it is often tempting to use a simple flag, don’t do it.
    • Use the manual pages. On Linux, in particular, the pthread man pages are highly informative and discuss much of the nuances pre- sented here, often in even more detail. Read them carefully!
