/*************************************************************************
	> File Name: SqStack.c
	> Author: moyu
	> Mail: 
	> Created Time: 2020年04月13日 星期一 09时35分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20		//栈空间容量
typedef int data_t;
typedef struct
{
	data_t arr[MAXSIZE];
	int top;			//栈顶指针，用来遍历和返回长度
}SqStack;


//创建
SqStack* create()
{
	SqStack* S = (SqStack*)malloc(sizeof(SqStack));
	if (S == NULL)
	{
		perror("malloc");
		return NULL;
	}

	S->top = -1;		//栈顶指针初始化-1，第一个数据下标为0
	return S;
}


//清空
int clear(SqStack* S)
{
	S->top = -1;
	return 1;
}


//求长度
int length(SqStack* S)
{
	return (S->top + 1);	//初始化为-1，长度要加1
}


//入栈
int push(SqStack* S, data_t data)
{
	//判断是否栈满
	if (S->top + 1 == MAXSIZE)
	{
		puts("Stack full");
		return -1;
	}

	++S->top;					//指针向上移动，指向新值
	S->arr[S->top] = data;		//给新值赋值

	return 1;
}


//出栈
int pop(SqStack* S)
{
	//判断栈是否为空
	if (S->top == -1)
	{
		puts("Stack empty");
		return -1;
	}

	--S->top;
	return 1;
}


//打印
void show(SqStack* S)
{
	int i = 0;
	while (i <= S->top)
	{
		printf("%d ", S->arr[i++]);
	}
	printf("\n");
}


int main()
{
	SqStack* S = create();

	for (int i = 1; i <= 10; ++i)
		push(S, i);
	show(S);
	printf("%d\n", length(S));

	pop(S);
	show(S);
	printf("%d\n", length(S));
}
