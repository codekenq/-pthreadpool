#ifndef __PTHREADPOOL_H__
#define __PTHREADPOOL_H__

#include <pthread.h>
#include "../queue/queue.h"
#include "../queue/item.h"
#include "../stack/stack.h"

#define MAX_PTHREAD_SIZE 8
#define TRUE			 1
#define FLASE			 0

/*
 * 这是工作线程函数的封装
 * This is encapsulation of the work thread function
 * */

typedef struct worker
{
	void *(*handler)(void *);
	void *args;
}worker;

/*
 * 这是线程池的控制头
 * This is the control table of pthread pool
 * */

typedef struct pthreadpool
{
	pthread_mutex_t mutex;
	pthread_cond_t cond;

	QUEUE assignment;
	int assignment_size;

	pthread_t *worker;
	int worker_size;

	int shutdown;
}pthreadpool;

/*
 * 初始化线程池
 * initialize pthread pool
 * */

void pthreadpool_init();

/*
 * 向线程池添加任务
 * add task to pthread pool
 * */

void pthreadpool_add(void *(*handler)(void *), void *args);

/*
 * 销毁线程池
 * destroy the pthread pool
 * */

void pthreadpool_dump();

#endif /* __PTHREADPOOL_H__*/
