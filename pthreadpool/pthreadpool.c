#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "pthreadpool.h"

static pthreadpool *manager;

/*
 * Function	  : pthreadpool_init
 * Paratemer  : void
 * Return     : void
 * Discription: 这个函数用来创建一个线程池
 *				This function is used to create a pthread pool
 * */

void pthreadpool_init()
{
	int i;
	manager = malloc(sizeof(*manager));

	pthread_mutex_init(&(manager->mutex), NULL);
	pthread_cond_init(&(manager->cond), NULL);

	manager->assignment = queue_init();
	manager->assignment_size = 0;

	manager->worker_size = MAX_PTHREAD_SIZE;
	manager->worker = malloc(sizeof(*(manager->worker)) * manager->worker_size);
	for(i = 0; i < manager->worker_size; i++)
		pthread_create(manager->worker + i, NULL, pthreadpool_run, NULL);
	manager->shutdown = FLASE;
}

/*
 * Function	  : pthreadpool_add
 * Paratemer  : handler是工作函数，args是工作函数的参数
 *				handler is the work function，args is the args of work function
 * Return     : void
 * Discription: 这个函数用来创建一个线程池
 *				This function is used to add task to pthread pool
 * */

void pthreadpool_add(void *(*handler)(void *), void *args)
{
	worker *temp_work = malloc(sizeof(*temp_work));
	temp_work->handler = handler; 
	temp_work->args = args;

	pthread_mutex_lock(&(manager->mutex));
//	printf("inter add task\n");
	queue_put(manager->assignment, temp_work);
	manager->assignment_size++;
	pthread_mutex_unlock(&(manager->mutex));

	pthread_cond_signal(&(manager->cond));
}

/*
 * Function	  : pthreadpool_run
 * Paratemer  : 传递给工作函数的参数args
 *				the args post to work function
 * Return     : void
 * Discription: 这个函数被用来传递给pthread_create
 *				This function is post to pthread_create
 * */

void* pthreadpool_run(void *args)
{
	while(1)
	{
		pthread_mutex_lock(&(manager->mutex));
//		printf ("starting thread 0x%x\n\n", pthread_self ());
		while(0 == manager->assignment_size && FLASE == manager->shutdown)
		{
//			printf ("thread 0x%x is waiting\n\n", pthread_self ());
			pthread_cond_wait(&(manager->cond), &(manager->mutex));
		}
		if(manager->shutdown == TRUE)
		{
//			printf ("thread 0x%x will exit\n\n", pthread_self ());
			pthread_mutex_unlock(&(manager->mutex));
//			printf("I release the mutex, 0x%x\n", pthread_self());
			pthread_exit(NULL);
		}

		printf ("thread 0x%x is starting to work\n\n", pthread_self ());
//		assert(0 != manager->assignment_size);

		manager->assignment_size--;
		worker *temp_work = queue_get(manager->assignment);

		pthread_mutex_unlock(&(manager->mutex));

		temp_work->handler(temp_work->args);
		free(temp_work);
		temp_work = NULL;
	}
//	printf("exiting\n");
}

/*
 * Function	  : pthreadpool_dump
 * Paratemer  : void
 * Return     : void
 * Discription: 这个函数用来销毁一个线程池
 *				This function is used to destroy a pthread pool
 * */

void pthreadpool_dump()
{
	int i;
	if(TRUE == manager->shutdown)
		return;
	manager->shutdown = TRUE;
	
	pthread_cond_broadcast(&(manager->cond));
	for(i = 0; i < manager->worker_size; i++)
	{
		pthread_join(*(manager->worker + i), NULL);
	}
	free(manager->worker);
	manager->worker = NULL;

	while(!queue_empty(manager->assignment))
	{
		worker *temp_work = queue_get(manager->assignment);
		free(temp_work);
		temp_work = NULL;
	}
	queue_dump(manager->assignment);

	pthread_cond_destroy(&(manager->cond));
	pthread_mutex_destroy(&(manager->mutex));
	free(manager);
	manager = NULL;
	printf("pthreadpool dump finished\n");
}
