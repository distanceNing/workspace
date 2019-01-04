#include "threadpool.h"
#define thread_num 5

void threadHandle(void *arg)
{
    /*回调处理函数，处理文件的接收或者上传*/
    int i = *(int *)arg;
    printf("threadHandle result == %d\n", i);
}

int main(int argc, char *argv[])
{
    thread_pool *pool = (thread_pool *)malloc(sizeof(thread_pool));
    threadpoolInit(pool, thread_num);
    int i;
    int tmp[thread_num];
    for (i = 0; i < thread_num; i++) {
        tmp[i] = i;
        threadpoolAddRunner(pool, threadHandle, &tmp[i]);
    }
    sleep(1);
    threadpoolDestroy(&pool);
    printf("main-> %p\n", pool);
    printf("main-> test over\n");
    return 0;
}