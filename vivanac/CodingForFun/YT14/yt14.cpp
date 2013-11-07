#pragma once

#include <cstdio>

void printAllCombinationsOfReturnChange(int* setOfCoins, int size, int change, int index, int* usedCoins)
{
	if(change < 0)
		return;
	if(change == 0)
	{
		printf("\n( ");
		for(int i = 0; i<size; i++)
		{
			printf(" {%d x %d} ", usedCoins[i], setOfCoins[i]);
		}
		printf(" )");
	}
	if(index >= size)
		return;

	int coin = setOfCoins[index];
	int numOfCoins = change/coin;
	
	for(int i = numOfCoins; i>=0; i--)
	{
		usedCoins[index] = i;
		printAllCombinationsOfReturnChange(setOfCoins, size, change-coin*i, index+1, usedCoins);
		usedCoins[index] = 0;
	}
}

void main()
{
	double change = 0.26;
	int size = 6;
	int setOfCoins[10] = {50, 20, 10, 5, 2, 1};
	int usedCoins[10] = {0};

	printAllCombinationsOfReturnChange(setOfCoins, size, change*100, 0, usedCoins);

	int a = 5;

}