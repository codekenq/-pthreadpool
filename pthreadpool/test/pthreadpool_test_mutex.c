#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "pthreadpool.h"

#define MAX_TASK_NUM 100

pthread_mutex_t mutex;
char buf[100];

//这个测试程序证明了，在线程池的基础上，可以加其他的锁，来完成更高一层的锁的应用。
//并且，这个程序的并发性也不错

void*  handler(void *args)
{
	pthread_mutex_lock(&mutex);
	sprintf(buf, "I`m thread 0x%x\nMy args is %d\n", pthread_self(), *(int *)args);
	printf("%s", buf);
	sleep(1);
	pthread_mutex_unlock(&mutex);
}

int main()
{
	int i;
	int *args = malloc(sizeof(*args) * MAX_TASK_NUM);
	pthread_mutex_init(&mutex, NULL);
	pthreadpool_init();
	for(i = 0; i < MAX_TASK_NUM; i++)
	{
		*(args + i) = i;
		pthreadpool_add(handler, args + i);
	}
	sleep(110);
	pthreadpool_dump();
	pthread_mutex_destroy(&mutex);
	free(args);
}
