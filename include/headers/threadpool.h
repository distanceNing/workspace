#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/* 线程体数据结构*/
typedef struct runner
{
    void (*callBack)(void *arg);    //回调函数指针
    void *arg;                      //回调函数参数
    struct runner *next;
}thread_runner;

/* 线程池数据结构*/
typedef struct pool
{
    pthread_mutex_t mutex;          //互斥量
    pthread_cond_t cond;            //条件变量
    thread_runner* runner_head;     //线程池中所有等待任务的头指针
    thread_runner* runner_tail;     //线程池中所有等待任务的尾指针
    int destroy;                    //线程池是否销毁,0没有注销，1注销
    pthread_t* threads;             //所有线程
    int max_thread_size;            //线程池中允许的活动线程数目
	int thread_num;                 //线程的编号
}thread_pool;


void run(void *arg);

void threadpoolInit(thread_pool *pool, int max_thread_size);

void threadpoolAddRunner(thread_pool *pool, void (*callback)(void *arg), void *arg);

void threadpoolDestroy(thread_pool **ppool);

#endif  //_THREADPOOL_H_