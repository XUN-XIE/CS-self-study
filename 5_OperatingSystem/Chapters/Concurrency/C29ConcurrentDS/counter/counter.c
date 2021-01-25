/*************************************************************************
 @Author: XieXun
 @Created Time : Thu 14 Jan 13:29:13 2021
 @File Name: counter.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUMCPUS 6

typedef struct __counter_t {
    int global; // global count
    pthread_mutex_t glock; // global lock
    int local[NUMCPUS]; // per-CPU count
    pthread_mutex_t llock[NUMCPUS]; // ... and locks
    int threshold; // update frequency
} counter_t;

// init: record threshold, init locks, init values
 // of all local counts and global count
void init(counter_t *c, int threshold) {
     c->threshold = threshold;
     c->global = 0;
     pthread_mutex_init(&c->glock, NULL);
     int i;
     for (i = 0; i < NUMCPUS; i++) {
         c->local[i] = 0;
         pthread_mutex_init(&c->llock[i], NULL);
     }
 }

 // update: usually, just grab local lock and update
 // local amount; once local count has risen ’threshold’,
 // grab global lock and transfer local values to it
void update(counter_t *c, int threadID, int amt) {
     int cpu = threadID % NUMCPUS;
     pthread_mutex_lock(&c->llock[cpu]);
     c->local[cpu] += amt;
     if (c->local[cpu] >= c->threshold) {
         // transfer to global (assumes amt>0)
         pthread_mutex_lock(&c->glock);
         c->global += c->local[cpu];
         pthread_mutex_unlock(&c->glock);
         c->local[cpu] = 0;
     }
     pthread_mutex_unlock(&c->llock[cpu]);
 }

 // get: just return global amount (approximate)
int get(counter_t *c) {
     pthread_mutex_lock(&c->glock);
     int val = c->global;
     pthread_mutex_unlock(&c->glock);
     return val; // only approximate!
}

typedef struct {
    counter_t * counter;
    int threadId;
} Arg;

void *
called(void * C)
{
    Arg * arg = (Arg *) C;
    counter_t * counter = (counter_t *) arg->counter;
    int threadId = arg->threadId;
    update( counter, threadId, 10);
    int * res = (int *)malloc(sizeof(int));
    *res = get(counter);
    return res;
}

int main()
{
    //for ( int S = 2; S <= 1024; S *= 2)
    //{
        counter_t test;
        init( &test, 1);

        pthread_t thread[NUMCPUS];
        for (int i = 0; i < NUMCPUS; i++)
        {
            Arg arg;
            arg.counter = &test;
            arg.threadId = i;
            pthread_create( &thread[i], NULL, &called, &arg);
        }
        
        int res[NUMCPUS];
        for (int i = 0; i < NUMCPUS; i++)
        {
            pthread_join( thread[i], (void *)&res[i]);
            printf("%d\n", res[i]);
        }   

    //}
}
