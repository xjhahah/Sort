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
//—°‘Ò≈≈–Ú    O(N*N)
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

//∂—≈≈–Ú  …˝–Ú”√¥Û∂—   Ωµ–Ú”√–°∂—   O(N*logN)
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


