#include <iostream>
#include "threadpool.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int mytask(void *arg)
{
    printf("thread %ld is working on task %d\n", (long)pthread_self(), *(int*)arg);
    sleep(1);
    free(arg);
    return 1;
}

int main() {
    threadpool_t pool;
    //初始化线程池，最多三个线程
    threadpool_init(&pool, 3);
    int i;
    //创建十个任务
    for(i=0; i < 10; i++)
    {
        int *arg = (int*)malloc(sizeof(int));
        *arg = i;
        //函数名作为参数时会自动转化为函数指针，只要参数列表和返回形式和形参中定义的函数指针
        //指向的函数类型一致即可
        threadpool_add_task(&pool, mytask, arg);

    }
    threadpool_destroy(&pool);
    return 0;
}