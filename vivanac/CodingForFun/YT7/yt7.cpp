#pragma once

#include <cstdio>
#include <memory.h>
#include <cstdlib>

int searchBinary(int num, int* arr, int lb, int ub)
{/*
	if(lb>=ub)
	{
		if(arr[lb] == num) return lb;
		
		return -1;
	}*/

	if(lb>ub)
	{
		return -1;
	}

	if(arr[lb] > num)
		return -1;
	if(arr[ub] < num)
		return -1;
	if(arr[lb] == num && arr[ub] == num)
		return lb;

	int mid = (ub+lb)/2;
	if(arr[mid] >= num)
	{
		return searchBinary(num, arr, lb, mid);
	}
	else
	{
		return searchBinary(num, arr, mid+1, ub);
	}

}


int main()
{
	int size;
	printf("\nSize of sorted array:");
	scanf("%d", &size);

	int* arr = (int*)malloc(sizeof(int)*size);
	for(int i = 0; i<size; i++)
	{
		printf("\nEnter %d element of sorted array:", i);
		scanf("%d", &arr[i]);
	}

	int num;
	printf("\nFind 1st index of this element:");
	scanf("%d", &num);

	int index = searchBinary(num, arr, 0, size-1);

	printf("Index of 1st is %d", index);

	return 0;
}