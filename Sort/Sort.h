#pragma once
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <memory.h>
#include "Stack.h"


void Print(int* arr,int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}
//插入排序
void InsertSort(int* a, int n)
{
	assert(a);
	int i, j;
	int temp;

	for (i = 1; i < n; i++)               //执行n-1趟插入
	{
		temp = a[i];                 //将要插入的数暂存到temp
		j = i - 1;
		while (j >= 0 && temp < a[j])   //找出temp的插入位置
			a[j + 1] = a[j--];         //将a[j]后移，再将j减1
		a[j + 1] = temp;               //将temp插入到指定位置
	}
}
//选择排序    O(N*N)
void SelectSort(int* arr, int len)
{
	assert(arr);
	int begin = 0;
	int end = len - 1;
	int maxindex = begin;
	int minindex = begin;
	while (begin < end)
	{
		for (int i = begin; i <= end; ++i)
		{
			if(arr[i] < arr[minindex])
			{
				minindex = i;
			}
			if (arr[i] > arr[maxindex])
			{
				maxindex = i;
			}
			Swap(&arr[begin], &arr[minindex]);
			if (begin == maxindex)
				maxindex = minindex;
			Swap(&arr[end], &arr[maxindex]);
			++begin;
			--end;
		}
	}
}

//堆排序  升序用大堆   降序用小堆   O(N*logN)
//void HeapSort(int* arr, int len)
//{
//	assert(arr);
//
//}

void BubbleSort(int* arr, int len)
{
	assert(arr);
	int end = len;
	while(end--)
	{
		int exchage = 0;
		for (int i = 1; i <= end; ++i)
		{
			if (arr[i] < arr[i - 1])
			{
				Swap(&arr[i], &arr[i - 1]);
				exchage = 1;
			}
		}
		if (exchage == 0)
			break;
	}
}

// 快速排序

//三数取中法，优化方法
int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	//begin mid end
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] < a[end])
			return end;
		else
			return begin;
	}
	else  //mid <= begin
	{
		if (a[end] < a[mid])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
	return -1;
}
//单趟排序
int PartSort1(int* arr, int begin,int end)
{
	int key = arr[end];
	int keyindex = end;
	while (begin < end)
	{
		//找大号
		while (begin < end && arr[begin] < key)
			++begin;
		while (begin < end && arr[end] >= key)
			--end;
		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[begin], &arr[keyindex]);
	return begin;
}
//挖坑法
int PartSort2(int* arr, int begin, int end)
{
	int key = arr[end];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
			++begin;
		arr[end] = arr[begin];
		while (begin < end && arr[end] >= key)
			--end;
		arr[begin] = arr[end];
	}
	arr[begin] = key;
	return begin;
}
//前后指针法
int PartSort3(int* arr, int begin, int end)
{
	int mid = GetMidIndex(arr, begin, end);
	Swap(&arr[mid], &arr[end]);
	int prev = begin - 1;
	int cur = begin;
	int key = arr[end];
	while (cur < end)
	{
		if (arr[cur] < key && ++prev != cur)
			Swap(&arr[cur], &arr[prev]);
		++cur;
	}
	Swap(&arr[++prev], &arr[end]);
	return prev;
}

void QuickSort(int* arr, int left,int right)
{
	assert(arr);
	if (left >= right)
		return;

	int div = PartSort3(arr, left, right);

	//[left,div-1]   div   [div+1,right]
	QuickSort(arr, left, div - 1);
	QuickSort(arr, div + 1,right);
}
void QuickSortOP(int* arr, int left, int right)
{
	if (left >= right)
		return;
	assert(arr);
	if (right - left + 1 < 10)
	{
		InsertSort(arr + left, right - left + 1);
	}
	else
	{
		int div = PartSort3(arr, left, right);

		//[left,div-1]   div   [div+1,right]
		QuickSortOP(arr, left, div - 1);
		QuickSortOP(arr, div + 1, right);
	}
}
//非递归
void QuickSortNonR(int* a, int left, int right)
{
	assert(a);
	Stack s;
	StackInit(&s);

	StackPush(&s, a[left]);
	StackPush(&s, a[right]);

	while (!StackEmpty(&s))
	{
		int end = StackTop(&s);
		StackPop(&s);
		int begin = StackTop(&s);
		StackPop(&s);

		int div = PartSort3(a, begin, end);
		if (begin < div - 1)
		{
			StackPush(&s, begin);
			StackPush(&s, div - 1);
		}
		if (div + 1 < end)
		{
			StackPush(&s, div + 1);
			StackPush(&s, end);
		}
	}
}


//归并排序
void Merge(int* a, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int start = begin1;
	int len = end2 - begin1 + 1;
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[end1])
		{
			tmp[index++] = tmp[begin1++];
		}
		else
		{
			tmp[index++] = tmp[begin2++];
		}
	}
	while(begin1<=end1)
		tmp[index++] = tmp[begin1++];
	while(begin2<=end2)
		tmp[index++] = tmp[begin2++];
	memcpy(a+start, tmp+start, sizeof(int)*len);
	//for (int i = 0; i < len; ++i)
	//{
	//	tmp[i] = a[i];
	//}
}
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = begin + ((end - begin) >> 1);

	//[a,begin,mid,tmp]   [a,mid+1,end,tmp]
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	Merge(a, begin, mid, mid + 1, end, tmp);
}
//缺陷： 要借助辅助空间
void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int)*n);

	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

//计数排序
void CountSort(int* a, int n)
{
	assert(a);
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* counts = (int*)malloc(range * sizeof(int));
	memset(counts, 0, sizeof(int)*range);
	for (int i = 0; i < n; ++i)
	{
		counts[a[i - min]]++;
	}
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (counts[i]--)
		{
			a[index++] = i + min;
		}
	}
}