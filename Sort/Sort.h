#pragma once
#include <stdio.h>
#include <assert.h>



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
//ѡ������    O(N*N)
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

//������  �����ô��   ������С��   O(N*logN)
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

// ��������

//��������
int PartSort(int* arr, int begin,int end)
{
	int key = arr[end];
	int keyindex = end;
	while (begin < end)
	{
		//�Ҵ��
		while (begin < end && arr[begin] < key)
			++begin;
		while (begin < end && arr[end] >= key)
			--end;
		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[begin], &arr[keyindex]);
	return begin;
}
//�ڿӷ�
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
//ǰ��ָ�뷨
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