#include <iostream>
using namespace std;


//打印
void Show(int* a, int len)
{
	for (int i = 0; i < len; ++i)
		cout << a[i] << ' ';
	cout << endl;
}


//冒泡排序
void Bubble(int* a, int len)
{
	int i, j, temp;
	for (i = 0; i < len - 1; ++i)
	{
		for (j = 0; j < len - 1 - i; ++j)
		{
			//升序排列
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}


//选择排序
void Choice(int* a, int len)
{
	int i, j, temp;
	for (i = 0; i < len - 1; ++i)
	{
		for (j = i + 1; j < len; ++j)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}


//插入排序
void Insert(int* a, int len)
{
	int i, j, temp;
	for (i = 1; i < len; ++i)
	{
		temp = a[i];
		j = i - 1;
		while (j >= 0 && temp < a[j])
		{
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = temp;
	}
}


//希尔排序
/*将序列拆分若干个子序列，然后进行插入排序，最后
*再对所有数据进行插入排序
*将插入排序中的 1，全部替换成grap（分组数）即可
*/

void Shell(int* a, int len)
{
	int i, j, temp;
	int grap = len / 2;		//分组

	while (grap > 0)	//对分的组进行插入排序
	{
		for (i = grap; i < len; ++i)
		{
			temp = a[i];
			j = i - grap;
			while (j >= 0 && temp < a[j])
			{
				a[j + grap] = a[j];
				j -= grap;
			}
			a[j + grap] = temp;
		}
		grap /= 2;
	}
}


//快速排序
void Quick(int* a, int low, int high)
{
	int i = low;
	int j = high;
	int key = a[low];

	if (low >= high)
		return;

	while (low < high)
	{
		while (low < high && a[high] >= key)
			--high;
		if (a[high] < key)
		{
			a[low] = a[high];
			++low;
		}

		while (low < high && a[low] <= key)
			++low;
		if (a[low] > key)
		{
			a[high] = a[low];
			--high;
		}
	}
	a[low] = key;
	Quick(a, i, low - 1);
	Quick(a, low + 1, j);
}


int main()
{
	int arr[] = { 3,5,7,2,10,6,9,1,13,11 };

	//原序列对比
	cout << "原序列：";
	Show(arr, 10);


	/*cout << "冒泡排序：";
	Bubble(arr, 10);
	show(arr, 10);*/


	/*cout << "选择排序：";
	Choice(arr, 10);
	show(arr, 10);*/


	/*cout << "插入排序：";
	Insert(arr, 10);
	show(arr, 10);*/


	/*cout << "希尔排序：";
	Shell(arr, 10);
	Show(arr, 10);*/


	cout << "快速排序：";
	Quick(arr, 0, 9);
	Show(arr, 10);
}