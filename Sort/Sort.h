#pragma once
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <memory.h>



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
//²åÈëÅÅĞò
void InsertSort(int* arr, int n)
{
	assert(arr);
	for (int i = 0; i < n-1; ++i)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				--end;
			}
			else
			{
				break;
			}
		}
		arr[end] = tmp;
	}
}
//Ñ¡ÔñÅÅĞò    O(N*N)
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

//¶ÑÅÅĞò  ÉıĞòÓÃ´ó¶Ñ   ½µĞòÓÃĞ¡¶Ñ   O(N*logN)
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

// ¿ìËÙÅÅĞò

//µ¥ÌËÅÅĞò
int PartSort1(int* arr, int begin,int end)
{
	int key = arr[end];
	int keyindex = end;
	while (begin < end)
	{
		//ÕÒ´óºÅ
		while (begin < end && arr[begin] < key)
			++begin;
		while (begin < end && arr[end] >= key)
			--end;
		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[begin], &arr[keyindex]);
	return begin;
}
//ÍÚ¿Ó·¨
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
//Ç°ºóÖ¸Õë·¨
int PartSort3(int* arr, int begin, int end)
{
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
//void QuickSortNonR(int* arr, int left, int right)
//{
//	assert(arr);
//
//}

//¹é²¢ÅÅĞò
void Merge(int* a, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int start = begin1;
	int len = end2 - begin1+1;
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
	//memcpy(a+start, tmp+start, sizeof(int)*len);
	for (int i = start; i < len; ++i)
	{
		tmp[i] = a[i];
	}
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
void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int)*n);

	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}