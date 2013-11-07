#pragma once

#include <cstdio>

void findAllPairsThatSumToM(int* arr, int size, int index, bool* isSet, int m, int count)
{
	if(count>2)
		return;

	if(m == 0)
	{
		printf("\n( ");
		for(int i=0; i<size; i++)
		{
			if(isSet[i])
				printf(" %d", arr[i]);
		}
		printf(" )");
		return;
	}
	if(m<0)
		return;
	
	for(int i = index; i<size; i++)
	{
		isSet[i] = true;
		findAllPairsThatSumToM(arr, size, i+1, isSet, m-arr[i], count+1);	
		isSet[i] = false;
	}

}

void findAllPairsThatSumToM2(int* arr, int size, int M)
{
	int left = 0;
	int right = size-1;

	while(left<right)
	{
		int vl = arr[left];
		int vr = arr[right];
		int res = vl+vr;
		if(res == M)
		{
			printf("\n (%d,%d)", vl, vr);
			left++; right--;
		}
		else if(res < M)
			left++;
		else
			right--;
	}
}

void main()
{
	//int size = 10;
	//int arr[10] = {1,3,5,6,7,13,15,17,21,66};
	int size = 7;
	int arr[10] = {1,2,3,4,8,9,10};
	bool isSet[10] = {0};

	findAllPairsThatSumToM(arr, size, 0, isSet, 12, 0);
	//findAllPairsThatSumToM2(arr, size, 12);
	
	int a = 5;
}