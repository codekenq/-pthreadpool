#ifndef __STACK_H__
#define __STACK_H__
#include "item.h"

/* The handle of stack for user 
 * 留给用户操作栈的句柄*/
typedef struct stack *Stack;

/* Fuction of destroy a stack
 * 该函数用于回收一个栈*/
void stack_dump(Stack);

/* Fuction of init a stack 
 * 该函数用于创建一个栈*/
Stack stack_init();

/* Fuction of test a stack is empty
 * 该函数用于测试一个栈是否为空*/
int stack_empty();

/* Fuction of push a item to a stack
 * 该函数入栈*/
void stack_push(Stack, Item);
/* Fuction of pop a item from a stack
 * 该函数用于出栈*/
Item stack_pop(Stack);

#endif/* __STACK_H__ */
