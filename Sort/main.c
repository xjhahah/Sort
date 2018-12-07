#include "Sort.h"

int main()
{
	int arr[] = { 9,4,5,1,6,3,8,7,2,0 };
	int len = sizeof(arr) / sizeof(arr[0]);

	//InsertSort(arr,len);
	//SelectSort(arr, len);
	//HeapSort(arr, len);
	//BubbleSort(arr, len);
	//QuickSort(arr, 0, len - 1);
	//QuickSortOP(arr, 0, len - 1);
	MergeSort(arr, len);
	Print(arr, len);
	return 0;
}