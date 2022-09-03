#include <stdio.h>
#include <stdlib.h>
#define ARRAY_A 5
#define ARRAY_B 3

double sort(double *table_a, double *table_b, int *i, int *j);

int main(void)
{
	int i = 0, j = 0, h = 0;
	double sorted = 0;

	double table_a[] = {-10.5, -1.8, 3.5, 6.3, 7.2};
	double table_b[] = {-1.8, 3.1, 6.3};

	while(i < 5)
	{
		sorted = sort(table_a, table_b, &i, &j);
		printf("Table C [%1d] = %.1lf\n", h, sorted);
		h++;

	}
}

double sort(double *table_a, double *table_b, int *pi, int *pj)
{
	if((table_a[*pi]) < (table_b[*pj]) && (&table_a[*pi]) < &table_a[5])
		{
			*pi+=1;
			return table_a[*pi];
		}
		else if((table_b[*pj]) < (table_a[*pi]) && (&table_b[*pj]) < &table_b[3])
		{
			*pj++;
			return table_b[*pj];
		}
		else if((table_a[*pi]) == (table_b[*pj]) && (&table_a[*pi]) < &table_a[5] && (&table_b[*pj]) < &table_b[3])
		{
			*pi++;
			*pj++;
			return table_a[*pi];
		}
		else
		{
			*pi++;
			return table_a[*pi];
		}
}