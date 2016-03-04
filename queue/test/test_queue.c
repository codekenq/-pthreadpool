#include <stdio.h>
#include "queue.h"

/*
 * This program is to test queue work with data type int.
 * We must change the data type in file item.h
 * */

int main()
{
	QUEUE queue1 = queue_init();
	QUEUE queue2 = queue_init();

	int i;
 	for(i = 0; i < 10; i++)
	{
		queue_put(queue1, i);
	}

	for(i = 100; i< 110; i++)
	{
		queue_put(queue2, i);
	}
 	for(i = 0; i < 10; i++)
	{
		printf("%d\n", queue_get(queue1));
	}

	for(i = 0; i < 10; i++)
	{
		printf("%d\n", queue_get(queue2));
	}
	queue_dump(queue1);
	queue_dump(queue2);
}
