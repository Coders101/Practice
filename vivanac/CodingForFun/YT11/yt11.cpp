#pragma once

#include <cstdio>

void printBuffer(int* buffer, int size)
{
	printf("\n(");
	for(int i = 0; i< size; i++)
	{
		printf(" %d", buffer[i]);
	}
	printf(" )");
}

void printAllSubsets(int* set, int size, int* buffer, int length, int index)
{
	for(int i = index, j = length; i<size; i++)
	{
		buffer[j] = set[i];
		printBuffer(buffer, length+1);
		printAllSubsets(set, size, buffer, length+1, i+1);
	}
}

void printBuffer2(int* set, bool* isPrint, int size)
{
	printf("\n(");
	for(int i = 0; i< size; i++)
	{
		if(isPrint[i])
			printf(" %d", set[i]);
	}
	printf(" )");
}


void printAllSubsets2(int* set, int size, bool* isPrint, int index, int toProcess)
{
	if(toProcess == 0)
		return;

	for(int i = index; i<size; i++ )
	{
		isPrint[i] = 1;
		printBuffer2(set, isPrint, size);
		printAllSubsets2(set, size, isPrint, i+1, toProcess-1);
		isPrint[i] = 0;
	}
}

int main()
{
	int size = 4;
	int set[10] = {1,2,3,4};
	int buffer[10] = {0};
	
	bool isPrint[10] = {0};

	printAllSubsets(set, size, buffer, 0, 0);
	
	printf("\n--------------------------");
	printBuffer2(set, isPrint, size);
	printAllSubsets2(set, size, isPrint, 0, (1 << 4) - 1); 
	int a = 9;
}
