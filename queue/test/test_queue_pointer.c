#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

/*
 * This program is to test queue work with data type void *.
 * We must change the data type in file item.h
 * */

typedef struct Node
{
	int a;
	int b;
} Node;

typedef struct Task
{
	float a;
	float b;
} Task;

int main()
{
	int i;
	Node *Node_temp;
	Node *Node_p = malloc(sizeof(Node) * 10);
	Task *Task_temp;
	Task *Task_p = malloc(sizeof(Task) * 10);

	QUEUE Node_q = queue_init();
	QUEUE Task_q = queue_init();

	for(i = 0; i < 10; i++)
	{
		(Node_p + i)->a = i;
		(Node_p + i)->b = i + 10;
		(Task_p + i)->a = i * 50.0;
		(Task_p + i)->b = i * 100.0;
	}
	for(i = 0; i < 10; i++)
	{
		queue_put(Node_q, Node_p + i);
		queue_put(Task_q, Task_p + i);
	}
	for(i = 0; i < 10; i++)
	{
		Node_temp = queue_get(Node_q);
		printf("Node:	a is :%d\nNode:	  b is :%d\n", Node_temp->a, Node_temp->b);
		Task_temp = queue_get(Task_q);
		printf("Task:   a is :%f\nTask:	  b is :%f\n", Task_temp->a, Task_temp->b);
	}
	queue_dump(Node_q);
	queue_dump(Task_q);
	free(Node_p);
	free(Task_p);
}
