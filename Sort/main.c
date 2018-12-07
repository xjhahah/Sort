#include "Sort.h"

int main()
{
	int arr[] = { 2,4,5,1,3,8,7,9,0 };
	int len = sizeof(arr) / sizeof(arr[0]);

	SelectSort(arr, len);
	Print(arr, len);
	return 0;
}