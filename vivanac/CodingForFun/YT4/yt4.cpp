#pragma once

#include <cstdio>
#include <cstdlib>

void parenthesis(char* comb, int index, int rem, int open, int count)
{
	if(count == 0)
	{
		printf("\n%s", comb);
		return;
	}

	if(rem > 0)
	{
		comb[index] = '(';
		parenthesis(comb, index+1, rem-1, open +1, count-1);
	}
	if(open > 0)
	{
		comb[index] = ')';
		parenthesis(comb, index+1, rem, open-1, count -1);
	}


}

int main()
{
	int a;
	printf("\n Print combinations of how much parenthesis?");
	scanf("%d", &a);

	int arrSize = 2*a+1;
	char* arr = (char*)malloc(arrSize*sizeof(char));

	arr[arrSize-1] = '\0';

	parenthesis(arr, 0, a, 0, arrSize-1);

	return 0;
}