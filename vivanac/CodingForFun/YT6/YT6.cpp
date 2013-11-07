#pragma once

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define CHAR_ARRAY_SIZE 256

void permutationSen(int index, char* sen, int length, int* numChar)
{
	if(index >= length)
	{
		printf("\n%s", sen);
		return;
	}

	for(int i=0; i < CHAR_ARRAY_SIZE; i++)
	{
		if(numChar[i] != 0)
		{
			sen[index] = i;
			numChar[i]--;
			permutationSen(index+1, sen, length, numChar);
			numChar[i]++;
		}
	}
}

int main2()
{
	printf("Write sentences for all permutation:");	
	char sen[1000];
	scanf("%[^\n]s", sen);
	//cout << "Write sentences for all permutation:";
    //cin >> sen;


	int length = 0;
	int numChar[CHAR_ARRAY_SIZE];
	memset(&numChar[0], 0, CHAR_ARRAY_SIZE*sizeof(int));

	int index = 0;
	while(sen[index] != '\0')
	{
		numChar[sen[index]]++;
		index++;
		length++;
	}

	permutationSen(0, &sen[0], length, &numChar[0]);

	return 0;
}

void swap(int indexA, int indexB, char* sen)
{
	char tmp = sen[indexA];
	sen[indexA] = sen[indexB];
	sen[indexB] = tmp;
}

void perm(char* sen, int length, int index)
{
	if(index == length-1)
	{
		printf("\n%s", sen);
		return;
	}

	perm(sen, length, index+1);
	for(int i = index+1; i< length; i++)
	{
		swap(index, i, sen);
		perm(sen, length, index+1);
		swap(index, i, sen);
	}

}

int main()
{
	printf("Write sentences for all permutation:");	
	char sen[1000];
	scanf("%[^\n]s", sen);
	
	int length = 0;
	while(sen[length] != '\0')
	{
		length++;
	}

	perm(&sen[0], length, 0);

	return 0;
}

