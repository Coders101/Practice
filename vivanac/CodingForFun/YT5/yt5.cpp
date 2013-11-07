#pragma once

#include<cstdio>

int gcd(int a, int b)
{
	int res = 0;
		
	while(1)
	{
		res = a % b; 
		if(res == 0)
			return b;
		a = b;
		b = res;
	}
	return 0;
}

int main()
{
	double a;
	printf("\n Enter double so it can be converted to rational number:");
	scanf("%lf", &a);

	bool isNegative = false;
	double num = a;
	if(a<0)
	{
		isNegative = true;
		num = -a;
	}

	int numIntPart = (int)num;
	double numDecPart = num - (int)num;

	int maxDecimal = 8;
	int currDecimal = 0;	
	int multiplier = 1;
	
	double numExpDecPart = numDecPart;

	while(currDecimal < maxDecimal)
	{
		int numInt = (int)numExpDecPart;
		double diff = numExpDecPart - numInt;
		if(diff == 0.0)
			break;

		numExpDecPart *= 10;
		multiplier *= 10;
		currDecimal++;
	}

	int numIntDecPart = (int)numExpDecPart;

	int gcdNum = gcd(numIntDecPart, multiplier);
	int upp = numIntDecPart/gcdNum;
	int dwn = multiplier/gcdNum;

	printf("\n Number %lf can be written as: ", a);
	if(isNegative)
		printf(" -");
	if(numIntPart != 0)
		printf("%d", numIntPart);
	printf(" %d/%d", upp, dwn);

	return 0;
}