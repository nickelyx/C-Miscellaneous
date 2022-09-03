#include <stdio.h>

int main(void)
{
	double a[5] = {-10.5, -1.8, 3.6, 6.3, 7.2};
	double b[3] = {-1.8, 3.1, 6.3};
	double *pa = &a[0];
	double *pb = &b[0];
	int i = 0;
	int j = 0;
	int h = 0;


double pac = *(pa + h);

for(i = 0; i < 8;)
{

	if(*(pa + h) < *(pb + j))
	{
		pac = *(pa + h);
		printf("a[%1d] = %.1lf\n", i, pac);
		++h;
	}
	else if(*(pb + j) < *(pa + h))
	{
		pac = *(pb + j);
		printf("a[%1d] = %.1lf\n", i, pac);
		++j;
	}
	else
	{
		printf("a[%1d] = %.1lf\n", i, pac);
		++j;
		++h;

		if(*(pb + j) < *(pa + h))
		{
			--h;
			pac = *(pb + j);
		}
		else if(*(pa + h) < *(pb + j))
		{
			--j;
			pac = *(pa + h);
		}
		else
		{
			printf("a[%1d] = %.1lf\n", i, pac);
			++j;
			++h;
		}
	}
	++i;
}


	return 0;
}




/*
	if(*(pb + j) == *(pa + h))
	{
		printf("a[%1d] = %.1lf\n", i, pac);
		++j;
		++h;
		if(*(pb + j) > *(pa + h))
		{
			--j;
			pac = *(pa + h);
		}
		else if(*(pa + h) > *(pb + j))
		{
			--h;
			pac = *(pb + j);
		}
		else
		{
			pac = *(pb + j);
		}
	}
	else if(*(pb + j) < pac)
	{
		pac = *(pb + j);
		++j;
	}
	else
	{
		printf("a[%1d] = %.1lf\n", i, pac);
		pac = *(pa + h);
		++h;
	}
	++i;*/

