#include <stdlib.h>
#include "stack.h"

/* the pointer of a stack_node 
 * 指向一个栈链表节点的指针类型*/
typedef struct stack_node *link;

/* the type of stack node
 * 链表中每个节点的类型*/
struct stack_node
{
	Item item;
	link next;
};

/* the handle for user to use 
 * 留给用户操作栈的句柄*/
struct stack
{
	link head;
};

/*
 * Function    : NEW
 * Parameter   : item 是该节点存储的有效数据， next为每个节点的链域的值
 *				 item is the data of linklist node, and next is the pointer of next linklist node
 * Return      : 指向该节点的指针
 *				 return the pointer of the linklist node
 * Discription : 该函数是为了创建一个新的链表节点。
 *				 this function is to create a new linklist node
 */

link NEW(Item item, link next)
{
	link x = malloc(sizeof(*x));
	x->item = item;
	x->next = next;
}

/* 
 * Fuction	   : stack_init
 * Parameter   : void
 * Return	   : 返回一个指向栈的句柄
 *				 return the handler of stack
 * Discriptoin : 初始化一个栈，并且返回指向栈的句柄。
 *				 initialize a stack
 * */

Stack stack_init()
{
	Stack s = malloc(sizeof(*s));
	s->head = NULL;
	return s;
}

/* 
 * Fuction	   : stack_empty
 * Parameter   : s 为指向一个栈的句柄
 *				 q is the handler of a stack
 * Return	   : 返回一个int值，1为真， 0为假
 *				 1 is true, 0 is false
 * Discription : 该函数用于判别一个栈是否为空
 *				 this function is to test whether a stack is NULL
 * */

int stack_empty(Stack s)
{
	return NULL == s->head;
}

/* Fuction	   : stack_push
 * Parameter   : s 为指向一个栈的句柄， item为将要压入栈的数据
 *				 q is the handler of a stack, and item is the data which is going to be put in the
 *				 stack
 * Return	   : void 
 * Discription : 该函数用于压栈
 *				 this function is used to push stack
 * */

void stack_push(Stack s, Item item)
{
	s->head = NEW(item, s->head);
}

/* 
 * Fuction     : stack_pop
 * Parameter   : s 指向一个栈的句柄
 *				 q is the handler of stack
 * Return	   : Item返回一个出栈后的数据
 *				 return a data of stack
 * Discription : 该函数用于出栈
 *				 this function is to pop and get a data from the stack
 * */

Item stack_pop(Stack s)
{
	Item item = s->head->item;
	link t = s->head->next;
	free(s->head);
	s->head = t;
	return item;
}

/* 
 * Fuction     : stack_dump
 * Parameter   : s为指向一个栈的句柄
 *				 q is a handler of satck
 * Return	   : void
 * Discription : 该函数用于销毁一个栈
 *				 this function is to destroy stack
 * */

void stack_dump(Stack s)
{
	while(!stack_empty(s))
	{
		stack_pop(s);
	}
	free(s);
}
