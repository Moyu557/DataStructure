#include <iostream>
using namespace std;


//顺序查找
int Sequential(int* a, int len, int value)
{
	int i = 0;
	while (i < len)
	{
		if (a[i] == value)
			return i;
		++i;
	}
	if (i == len)
		return -1;
}


//二分查找
int Binary(int* a, int len, int value)
{
	int low = 0;
	int high = len - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (value < a[mid])
			high = mid - 1;
		else if (value > a[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}


//哈希查找 —— 线性探测法
//创建哈希表
void create_hashTable(int hash_arr[], int hash_len, int arr[], int arr_len)
{
	//建立哈希表并初始化(全部初始化 -1)
	for (int i = 0; i < hash_len; ++i)
	{
		hash_arr[i] = -1;
	}

	//使用哈希函数处理后存储元素
	//自定义哈希函数 —— key = arr[i] % 11
	//模 11，得到的下标范围为 0 ~ 10，下标数量要比原数据大（一般大 1 个）
	for (int i = 0; i < arr_len; ++i)
	{
		int hash_add = arr[i] % 11;
		while (hash_add < hash_len)
		{
			if (hash_arr[hash_add] == -1)	//得到的 key 值没有元素
			{
				hash_arr[hash_add] = arr[i];	//将元素放在这里
				break;
			}
			++hash_add;		//若多个值有相同的key，则第二个后移一位开始寻找

			//若最后一个位置也被占，则从头开始找位置
			if (hash_add == hash_len)
				hash_add = 0;
		}
	}
}


//在哈希表中查找元素
int Hash(int hash_arr[], int hash_len, int value)
{
	//还原 key,直接得到该值的位置，但是可能有多个值对应该键值
	int hash_add = value % 11;

	/*
	*只找一圈，用于哈希表长与原数据等长的情况，
	*所以建表的时候最好表大于数据长度
	*/
	int flag = hash_add;
	while (hash_arr[hash_add] != -1)
	{
		if (hash_arr[hash_add] == value)
		{
			return hash_add;
		}
		++hash_add;

		//表长等于原数据长度的情况，防止死循环
		if (flag == hash_add)
		{
			break;
		}

		/*
		*循环查找，防止元素先前因为相同的 key,往后找位置时存在了
		*key 值前面的位置
		*/
		if (hash_add == hash_len)
			hash_add = 0;
	}
	return -1;
}


int main()
{
	int a[] = { 6, 2, 1, 0, 8, 3, 7, 4, 5, 9 };
	int b[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };	//二分查找元素要有序
	int c[11];

	//顺序查找
	cout << Sequential(a, 10, 4) << endl;

	//二分查找
	cout << Binary(b, 10, 3) << endl;

	//创建哈希表 c
	create_hashTable(c, 11, a, 10);
    
	//在哈希表中查找元素
	cout << Hash(c, 11, 4) << endl;
}