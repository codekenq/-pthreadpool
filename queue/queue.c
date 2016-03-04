#include <stdlib.h>
#include "item.h"
#include "queue.h"

typedef struct queue_node *link;

/* 
 * 链表中每个节点的类型 
 * The type of linklist node
 * */
struct queue_node
{
	Item item;
	link next;
};

/*
 * 用于管理queue的结构
 * The struct is used to handle queue
 * */
struct queue
{
	link head;
	link tail;
};


/*
 * Fuction	   : NEW
 * Paratemer   : item为节点中的数据，next为节点链域的值
 *			     item is the data of linklist node, and next is the pointer of next linklist node
 * Return      : 指向该节点的指针
 *			     return the pointer of the linklist node
 * Discription : 该函数用于创建一个新的节点
 *				 this function is to create a new linklist node
 * */
link NEW(Item item, link next)
{
	link x = malloc(sizeof(*x));
	x->item = item;
	x->next = next;
	return x;
}

/* 
 * Fuction     : queue_init
 * Parameter   : void
 * Return      : 返回一个指向queue的句柄
 *				 return the handler of queue
 * Discription : 初始化一个queue
 *			     initialize a queue
 * */

Q queue_init()
{
	Q q = malloc(sizeof(*q));
	q->head = NULL;
	return q;
}

/*
 * Fuction     : queue_empty
 * Parameter   : q为指向一个queue的句柄
 *				 q is the handler of a queue
 * Return      : int ,0为假， 1 为真
 *				 1 is true, 0 is false
 * Discription : 该函数用于测试一个queue是否为空
 *				 this function is to test whether a queue is NULL
 * */
int queue_empty(Q q)
{
	return NULL == q->head;
}


/* 
 * Fuction     : queue_put
 * Parameter   : q为指向一个queue的句柄， item 为要存在queue的数据
 *				 q is the handler of a queue, and item is the data which is going to be put in the
 *				 queue
 * Return      : void
 * Discription : 该函数用于将一个数据放入queue
 *				 this function is to put a data in queue
 * */
void queue_put(Q q, Item item)
{
	if(NULL == q->head)
	{
		q->tail = NEW(item, q->head);
		q->head = q->tail;
		return;
	}
	q->tail->next = NEW(item, q->tail->next);
	q->tail = q->tail->next;
}


/* 
 * Fuction     : queue_get
 * Parameter   : q为指向该queue的句柄
 *				 q is the handler of queue
 * Return      : queue中的数据
 *				 return a data of queue
 * Discription : 该函数用于出queue
 *				 this function is to pop and get a data from the queue
 * */
Item queue_get(Q q)
{
	if(queue_empty(q))
		return ;
	Item item = q->head->item;
	link t = q->head->next;
	free(q->head);
	q->head = t;
	return item;
}

/* 
 * Fuction	   : queue_dump
 * Parameter   : q为指向一个queue的句柄
 *				 q is a handler of queue
 * Return	   : void
 * Discription : 该函数用于销毁一个队列
 *				 this function is to destroy queue
 * */
void queue_dump(Q q)
{
	while(!queue_empty(q))
	{
		queue_get(q);
	}
	free(q);
	q = NULL;
}
