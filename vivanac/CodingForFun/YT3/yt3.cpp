#pragma once

#include <cstdio>
#include <cstdlib>

int indexOf(int a, int* arr, int size)
{
	int lb = 0;
	int ub = size-1;
	int c;

	while(lb<ub)
	{
		c = (ub+lb)/2;
		if(arr[c] == a)
			return c;
		else if(arr[c] > a)
			ub = c;
		else
			lb = c;	
	}

	if(arr[c] == a)
		return c;

	return -1;

}

int main2()
{
	/*int size = 20;
	int* arr = (int*)malloc(size*sizeof(int));
	
	for(int i = 0; i<20; i++)
	{

	}*/
	
	int arr[20] = {1, 2, 2, 3, 3, 3, 4, 5, 7, 77, 77,77,77,77,99, 104, 224, 228, 314, 456};
		
	int a;
	printf("\nfind occurances of what number?");
	scanf("%d", &a);

	//find index of element
	int i = indexOf(a, arr, 20);

	int count = 0;
	if(i != -1)
	{
		int index = i;
		while(index > 0 && arr[index] == a)
		{
			count++;
			index--;
		}
		index = i+1;
		while(index<20 && arr[index] == a)
		{
			count++;
			index++;
		}
	}

	printf("\n %d found %d times.", a, count);
	
	return 0;
}

int getOccurances(int a, int* arr, int lb, int ub)
{
	if(lb>ub)
		return 0;

	if(arr[lb] > a)
		return 0;
	if(arr[ub] < a)
		return 0;
	if(arr[lb] == a && arr[ub]== a)
		return ub - lb + 1;

	int count = 0;
	int m = (ub+lb)/2;
	if(arr[m] == a)
	{
		count++;
		count += getOccurances(a, arr, lb, m-1);
		count += getOccurances(a, arr, m+1, ub);
	}
	else if(arr[m] < a)
	{
		count += getOccurances(a, arr, m+1, ub);
	}
	else
		count += getOccurances(a, arr, lb, m-1);

	return count;
	

}

int main()
{
	int arr[20] = {1, 2, 2, 3, 3, 3, 4, 5, 7, 77, 77,77,77,77,99, 104, 224, 228, 314, 456};
		
	int a;
	printf("\nfind occurances of what number?");
	scanf("%d", &a);

	int count = getOccurances(a, arr, 0, 19);

	printf("\n We found %d of %d", count, a);

	return 0;

}