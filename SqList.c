#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 20			//线性表容量

typedef int data_t;			//自定义数据类型

//线性表结构
typedef struct
{
	data_t arr[MAXSIZE];
	int len;				//线性表当前长度
}SqList;


/******************************************/
//创建线性表
SqList* create()
{
	SqList* L = (SqList*)malloc(sizeof(SqList));
	if (L == NULL)
	{
		perror("new");
		return NULL;
	}

	L->len = 0;				//初始化线性表长度
	return L;
}


/******************************************/
//清空线性表
int clear(SqList* L)
{
	L->len = 0;
	return 1;
}


/******************************************/
//判断是否为空
int is_empty(SqList* L)
{
	if (L->len == 0)
		return 1;
	else
		return -1;
}


/******************************************/
//判断是否为满
int is_full(SqList* L)
{
	if (L->len == MAXSIZE)
		return 1;
	else
		return -1;
}


/******************************************/
//线性表长度
int length(SqList* L)
{
	return L->len;
}


/******************************************/
//按位置插入数据
int insert(SqList* L, data_t data, int pos)
{
	//判断线性表是否支持插入
	if (L->len == MAXSIZE)
	{
		puts("SqList is full.\n");
		return -1;
	}

	//对插入的位置进行判断
	if (pos < 1 || pos > L->len + 1)	//len + 1表示插入到最后一个元素的后面
	{
		puts("pos is error");
		return -1;
	}

	//开始插入
	//指定位置及其后的元素依次后移
	for (int i = L->len - 1; i >= pos; --i)
	{
		L->arr[i + 1] = L->arr[i];
	}

	//新元素补到该位置
	L->arr[pos - 1] = data;

	//线性表长度加 1
	++L->len;

	return 1;		//成功标志
}


/******************************************/
//按位置删除数据
int delet(SqList* L, int pos)
{
	//判断线性表是否为空
	if (L->len == 0)
	{
		puts("SqList is empty");
		return -1;
	}

	//判断位置是否合理
	if (pos < 1 || pos > L->len)
	{
		puts("pos error");
		return -1;
	}

	//开始删除
	//指定位置后面的数前移
	for (int i = pos; i < L->len; ++i)
	{
		L->arr[i - 1] = L->arr[i];
	}
	--L->len;		//长度减1

	return 1;
}


/******************************************/
//修改指定位置的值
int change(SqList* L, data_t data, int pos)
{
	//判断线性表是否为空
	if (L->len == 0)
	{
		puts("SqList is empty");
		return -1;
	}

	//判断位置是否合理
	if (pos < 1 || pos > L->len)
	{
		puts("pos error");
		return -1;
	}

	//修改
	L->arr[pos - 1] = data;

	return 1;
}


/******************************************/
//查照指定位置的元素
data_t find(SqList* L, int pos)
{
	return L->arr[pos - 1];
}


/******************************************/
//打印线性表
void show(SqList* L)
{
	for (int i = 0; i < L->len; ++i)
	{
		printf("%d ", L->arr[i]);
	}
	puts("");
}



int main()
{
	SqList* L = create();

	printf("插入1~10：");
	for (int i = 1; i <= 10; ++i)
		insert(L, i, i);
	show(L);

	printf("删除第10个元素：");
	delet(L, 10);
	show(L);

	printf("修改第 6 个元素为 11：");
	change(L, 11, 6);
	show(L);

	printf("查找第4个位置的值：");
	int elem = find(L, 4);
	printf("%d\n", elem);
}
