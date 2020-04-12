/*************************************************************************
	> File Name: LinkList.c
	> Author: moyu
	> Mail: 
	> Created Time: 2020年04月12日 星期日 15时58分12秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20		//链表容量
typedef int data_t;		//自定义类型

//链表结点类型
typedef struct Node
{
	data_t data;		//数据域
	struct Node* next;	//指针域
}LinkList;


/******************************************/
//创建链表(含头结点)
LinkList* create()
{
	LinkList* head = (LinkList*)malloc(sizeof(LinkList));
	if (head == NULL)
	{
		perror("malloc");
		return NULL;
	}

	head->next = NULL;		//头结点指向空
	return head;
}


//清空链表
int clear(LinkList* head)
{
	LinkList* p, * q;

	p = head;			//头结点位置不变
	while (p->next != NULL)		//链表不为空
	{
		q = p;				//使用临时变量保存下一结点
		free(p);
		p = q;
	}

	head->next = NULL;		//头结点指向空
	return 1;
}


//链表长度
int length(LinkList* head)
{
	int len = 0;					//长度
	LinkList* p = head;		//p来遍历

	while (p->next != NULL)
	{
		++len;
		p = p->next;
	}
	return len;
}


//插入数据(先连后面，再连前面)
int insert(LinkList* head, int pos, data_t data)
{
	LinkList* p = head;			//临时变量用来确定位置遍历
	int i = 1;					//遍历位置

	//找到指定位置的前一个位置，并且判断位置是否合理
	while (p != NULL && i < pos)
	{
		p = p->next;
		++i;
	}

	//位置不合理
	if (p == NULL && i > pos)
	{
		puts("pos error");
		return -1;
	}

	//开始插入
	//新建插入的一个结点
	LinkList* q = (LinkList*)malloc(sizeof(LinkList));
	q->data = data;
	q->next = p->next;		//先连后面
	p->next = q;			//再连前面

	return 1;
}


//删除数据
int delet(LinkList* head, int pos)
{
	LinkList* p = head;
	int i = 1;

	//找到指定位置之前的位置
	while (p->next != NULL && i < pos)
	{
		++i;
		p = p->next;
	}

	//遍历完都没有找到该位置
	if (p->next == NULL || i > pos)
	{
		puts("pos error");
		return -1;
	}

	//开始删除
	LinkList* q = p->next;	//q表示要删除的数据
	p->next = q->next;		//连后面
	free(q);

	return 1;
}


//查找指定位置的数据
int find(LinkList* head, int pos)
{
	LinkList* p = head;

	//指定位置过小
	if (pos < 1)
	{
		puts("pos error");
		return -1;
	}

	//指定位置过大
	while (pos--)
	{
		if (p->next != NULL)
		{
			p = p->next;
		}
		else
		{
			puts("pos error");
			return -1;
		}
	}
	return p->data;
}


//修改指定位置的值
int change(LinkList* head, int pos, data_t data)
{
	LinkList* p = head;

	if (pos < 1)
	{
		puts("pos error");
		return -1;
	}

	while (pos--)
	{
		p = p->next;

		//指定位置过长
		if (p == NULL)
		{
			puts("pos error");
			return -1;
		}
	}
	p->data = data;

	return 1;
}


//打印链表
void show(LinkList* head)
{
	LinkList* p = head->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	puts("");
}


int main()
{
	LinkList* head = create();

	for (int i = 1; i <= 10; ++i)
		insert(head, i, i);
	show(head);
	printf("%d\n", length(head));

	delet(head, 10);
	show(head);
	printf("%d\n", length(head));

	printf("%d\n", find(head, 9));

	change(head, 9, 12);
	show(head);
}

