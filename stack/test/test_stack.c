/*
 * =====================================================================================
 *
 *       Filename:  test_stack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月27日 09时24分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hanken (hk), 1061582570@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "stack.h"

int main()
{
	Stack stack1 = stack_init();
	Stack stack2 = stack_init();

	int i = 0;
	for(i; i < 10; i++)
	{
		stack_push(stack1, i);
	}
	for(i = 100; i < 110; i++)
	{
		stack_push(stack2, i);
	}
	for(i = 0; i < 10; i++)
	{
		printf("%d\n", stack_pop(stack1));
	}
	for(i = 0; i < 10; i++)
	{
		printf("%d\n", stack_pop(stack2));
	}
}
