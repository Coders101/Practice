#pragma once

#include <cstdio>

bool isPalindrome(char* arr, int length)
{
	for(int i =0; i< length; i++)
	{
		int begin = i;
		int end = i-1;
		if(end < 0)
			end = length-1;
		bool isPal = true;
		int index = length/2;
		while(index > 0)
		{
			if(arr[begin] != arr[end])
			{
				isPal = false;
				break;
			}

			begin++;
			end--;

			if(begin>= length)
				begin = 0;
			if(end<0)
				end = length-1;

			index--;
		}

		if(isPal) return true;
	}

	return false;

}

int main()
{
	//char palindrome[1000] = {"43211234565\0"};
    char palindrome[1000] = {"11\0"};


	bool res = isPalindrome(&palindrome[0], 2);

	int a = 5;



}