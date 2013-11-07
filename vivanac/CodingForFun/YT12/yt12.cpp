#pragma once

#include <cstdio>

void mergeTo(int* large, int numberOfElements, int sizeLarge, int* small, int sizeSmall)
{
	
	int indexL = numberOfElements-1;
	int indexS = sizeSmall-1;
	int indexMerge = numberOfElements + sizeSmall -1;
	while(true)
	{
		if(indexS == -1) return;

		if(indexL < 0 || small[indexS] >= large[indexL])
		{
			large[indexMerge] = small[indexS];
			indexS--;
		}
		else
		{
			large[indexMerge] = large[indexL];
			indexL--;
		}

		indexMerge--;	
	}

}

int main()
{
	int large[15] = { 1, 4, 5, 6, 9, 11, 12, 0, 0, 0, 0, 0, 0, 0, 0};
	int small[5] = {0,7, 10, 15, 20};

	mergeTo(large, 7, 15, small, 5);

	return 0;
}