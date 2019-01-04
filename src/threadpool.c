// threadpool.c
#include "threadpool.h"

/**********************************************************
* 初始化线程
* 参数：
* pool：指向线程池结构有效地址的动态指针
* max_thread_size：最大的线程数
**********************************************************/
void threadpoolInit(thread_pool *pool, int max_thread_size)
{
    int iLoop = 0;

    /*线程池初始化操作*/
    if (pthread_mutex_init(&(pool->mutex), NULL)) {
        //初始化互斥量
        perror("pthread_mutex_init");
        exit(1);
    }
    if (pthread_cond_init(&(pool->cond), NULL)) {
        //初始化条件变量
        perror("pthread_cond_init");
        exit(1);
    }
    pool->destroy = 0;             //线程池默认没有注销
    pool->threads = (pthread_t *)malloc(max_thread_size * sizeof(pthread_t)); //创建所有分离线程
    if (pool->threads == NULL) {
        perror("malloc");
        exit(1);
    }

    pool->runner_head = NULL;
    pool->runner_tail = NULL;
    pool->max_thread_size = max_thread_size;

    /*创建线程操作*/
    for (iLoop; iLoop < max_thread_size; iLoop++) {
    //for (pool->thread_num = 0; pool->thread_num < max_thread_size; ++pool->thread_num) {
        pthread_attr_t attr;                //定义线程对象
        pthread_attr_init(&attr);             //初始化线程的属性
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);    //设置脱离状态的属性(决定这个线程在终止时是否可以被结合)
        //pthread_mutex_lock(&(pool->mutex));
        pthread_create(&(pool->threads[pool->thread_num]), &attr, (void *)run, (void *)pool);
        /*threads[i] 动态创建线程；第一个参数为指向线程标识符的指针。第二个参数用来设置线程属性。
         * 第三个参数是线程运行函数的起始地址。最后一个参数是运行函数的参数。*/
        //usleep(100);
    }
    printf("threadpoolInit-> create %d detached threads\n", max_thread_size);
}

/**********************************************************
* 线程体,创建线程后调用的函数
* 参数：
* arg：接收创建线程后传递的参数
**********************************************************/
void run(void *arg)
{

    thread_pool *pool = (thread_pool *)arg;
    //printf("The %d run-> locked!\n", pool->thread_num);
    //pthread_mutex_unlock(&(pool->mutex));
    while (1) {
        pthread_mutex_lock(&(pool->mutex));               //加锁
        printf("The %d run-> locked!\n", pool->thread_num);

        /*如果等待队列为0并且线程池未销毁,则处于阻塞状态 */
        while (pool->runner_head == NULL && !pool->destroy) {
            pthread_cond_wait(&(pool->cond), &(pool->mutex));
        }

        /*如果线程已经销毁*/
        if (pool->destroy) {
            pthread_mutex_unlock(&(pool->mutex));          //解锁
            printf("The %d run-> unlock and thread exit!\n", pool->thread_num);
            pthread_exit(NULL);
        }
        thread_runner *runner = pool->runner_head;         //取链表的头元素
        pool->runner_head = runner->next;
        printf("The run-> unlocked!\n");
        pthread_mutex_unlock(&(pool->mutex));              //解锁
        //printf("The run-> unlocked!\n");

        (runner->callBack)(runner->arg);                   //调用回调函数，执行任务
        free(runner);                                      //释放线程操作
        runner = NULL;
        printf("run-> runned and free runner!\n");
    }
    pthread_exit(NULL);
}

/**********************************************************
* 向线程池加入任务
* 参数：
* pool：指向线程池结构有效地址的动态指针
* callback：线程回调函数
* arg：回调函数参数
**********************************************************/
void threadpoolAddRunner(thread_pool *pool, void(*callback)(void *arg), void *arg)
{
    thread_runner *newrunner = (thread_runner *)malloc(sizeof(thread_runner));//构建一个新任务
    if (newrunner == NULL) {
        perror("malloc");
        exit(1);
    }
    newrunner->callBack = callback;
    newrunner->arg = arg;
    newrunner->next = NULL;

    pthread_mutex_lock(&(pool->mutex));                    //加锁
    printf("threadpoolAddRunner-> locked\n");

    /*将新任务加入到等待队列中,如果等待队列为空，直接运行当前的线程 */
    if (pool->runner_head != NULL) {
        pool->runner_tail->next = newrunner;
        pool->runner_tail = newrunner;
    } else {
        pool->runner_head = newrunner;
        pool->runner_tail = newrunner;
    }
    printf("threadpoolAddRunner-> unlocked\n");
    pthread_mutex_unlock(&(pool->mutex));                  //解锁
    //printf("threadpoolAddRunner-> unlocked\n");

    pthread_cond_signal(&(pool->cond));                    //唤醒一个等待线程
    printf("threadpoolAddRunner-> add a runner and wakeup a waiting thread\n");
}

/**********************************************************
* 销毁线程池
* 参数：
* ppool：指向线程池结构有效地址的动态指针地址(二级指针)
**********************************************************/
void threadpoolDestroy(thread_pool **ppool)
{
    thread_pool *pool = *ppool;

    /*判断线程池是否注销,防止二次销毁*/
    if (!pool->destroy) {
        pool->destroy = 1;
        pthread_cond_broadcast(&(pool->cond));    //唤醒所有的等待线程，线程池要销毁了
        sleep(1);                              //等待所有的线程终止
        printf("threadpoolDestroy-> wakeup all waitting threads\n");
        free(pool->threads);                    //回收空间

        /*销毁等待队列*/
        thread_runner *head = NULL;
        while (pool->runner_head != NULL) {
            head = pool->runner_head;
            pool->runner_head = pool->runner_head->next;
            free(head);
        }
        printf("thread_destroy-> all runners freed\n");

        pthread_mutex_destroy(&(pool->mutex));    //销毁条件变量
        pthread_cond_destroy(&(pool->cond));      //销毁互斥量
        printf("thread_destroy-> mutex and cond destroyed\n");
        free(pool);
        pool = NULL;
        (*ppool) = NULL;
        printf("threadpoolDestroy-> pool freed\n");
    }
}
//======================= end threadpool.c