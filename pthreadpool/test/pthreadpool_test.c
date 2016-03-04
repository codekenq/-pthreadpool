#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "pthreadpool.h"

#define MAX_TASK_NUM 100

//利用该线程池，猛然间加到100个任务，每个任务执行1s，可以做到。
//利用该线程池，猛然增加到10000个任务，每个任务执行1s，可以做到。

void* handler(void *args)
{
	sleep(1);
	printf("%d\n", *(int *)args);
}

int main()
{
	int i;
	int *args = malloc(sizeof(*args) * MAX_TASK_NUM);
	pthreadpool_init();
	for(i = 0; i < MAX_TASK_NUM; i++)
	{
		*(args + i) = i;
		pthreadpool_add(handler, args + i);
	}
	sleep(60);
	pthreadpool_dump();
	free(args);
}
