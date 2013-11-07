#pragma once

#include <cstdio>
#include <cmath>

using namespace std;

int main2()
{
	int a;
	printf("\nFind square root of number:");
	scanf("%d", &a);

	double lb = 0;
	double ub = a;
	double m;

	while(ub - lb > 1)
	{
		m = (ub+lb)/2;
		double res = m*m;
		if(res == a)
			break;
		else if(res > a)
			ub = m;
		else
			lb = m;
	}
	
	printf("\n%f is square root of %d", m, a);
	printf("\n%d is square root of %d", (int)ceil(m-0.5), a);

	return 0;
}

int main3()
{
	int a;
	printf("\nFind square root of number:");
	scanf("%d", &a);

	int lb = 0;
	int ub = a;
	int m;

	while(ub - lb > 1)
	{
		m = (ub+lb)/2;
		int res = m*m;
		if(res == a)
			break;
		else if(res > a)
			ub = m;
		else
			lb = m;
	}
	
	printf("\n%d is square root of %d", m, a);
	//printf("\n%d is square root of %d", (int)ceil(m-0.5), a);

	return 0;
}

int main()
{
	double a;
	printf("\nFind square root of number:");
	scanf("%lf", &a);

	if(a<0)
	{
		printf("\nNumber is negative!");
	}

	if(a == 0 || a==1)
		printf("\n Square root is:%f",a);
	else
	{
		double lb = 0;
		double ub = 1 + (a/2);
		double m;
		double precision = 0.0005;

		while(ub-lb>precision)
		{
			m = (ub+lb)/2;
			double res = m*m;
			if(res == a)
				break;
			else if(res < a)
				lb = m;
			else
				ub = m;
		}

		printf("\n Square root of %f is %f", a, m);
	}

	return 0;
}

int main5()
{
	double a;
	printf("\nFind square root of number:");
	scanf("%lf", &a);

	//newton

	double c = 1 + (a/2);
	while((c*c-a)>0.0001)
	{
		c=c-(c*c -a)/(2*c);		
	}

	printf("\n sqare root of %f is %f",a,c);

	return 0;
}

int main6()
{
	double a;
	printf("\nFind square root of number:");
	scanf("%lf", &a);

	//newton

	double c = 1 + (a/2);
	while((c*c*c-a)>0.0001)
	{
		c=c-(c*c*c -a)/(3*c*c);		
	}

	printf("\n 3rd root of %f is %f",a,c);

	return 0;
}