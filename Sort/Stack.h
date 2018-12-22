#pragma once
#include <stdio.h>

#define MAX_SIZE 10
typedef int DataType;
typedef struct Stack
{
	DataType _array[MAX_SIZE];
	DataType _top;  //栈的有效元素的个数和栈顶元素
}Stack;

void StackInit(Stack* s);
void StackPush(Stack* s, DataType data);
void StackPop(Stack* s);

int StackTop(Stack* s);
int StackSize(Stack* s);
int StackEmpty(Stack* s);

void StackInit(Stack* s)
{
	assert(s);
	s->_top = 0;
}
void StackPush(Stack* s, DataType data)
{
	assert(s);
	if (MAX_SIZE == s->_top)
	{
		printf("Stack is flow\n");
	}
	s->_array[s->_top++] = data;
}
void StackPop(Stack* s)
{
	assert(s);
	if (StackEmpty(s))
		return;
	s->_top--;
}

int StackTop(Stack* s)
{
	assert(!StackEmpty(s));
	return s->_array[s->_top];
}
int StackSize(Stack* s)
{
	assert(s);
	return s->_top;
}
int StackEmpty(Stack* s)
{
	assert(s);
	return 0 == s->_top;
}