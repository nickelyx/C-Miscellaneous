#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int i = 0, j = 0;

	double table_a[] = {-10.5, -1.8, 13.5, 6.13, 7.2, 5.1, 2.8, 8.0, 9.4, 10, 8, 15.1, 13, 19, 16.4, 17.8, 18.6, 19.4, 12.5, 20.5};
	double table_b[] = {-1.8, 13.1, 6.13, 2.7, 5.8, 6.8};

	double *ptr_table_a = &table_a[0];
	double *ptr_table_b = &table_b[0];

	while((ptr_table_a + i) < &table_a[20])
	{
		if(*(ptr_table_a + i) < *(ptr_table_b + j) && (ptr_table_a + i) < &table_a[20])
		{
			printf("Table C [%1d] = %.1lf\n", i, *(ptr_table_a + i));
			++i;
		}
		else if(*(ptr_table_b + j) < *(ptr_table_a + i) && (ptr_table_b + j) < &table_b[6])
		{
			printf("Table C [%1d] = %.1lf\n", j, *(ptr_table_b + j));
			++j;
		}
		else if(*(ptr_table_a + i) == *(ptr_table_b + j) && (ptr_table_a + i) < &table_a[20] && (ptr_table_b + j) < &table_b[6])
		{
			printf("Table C [%1d] = %.1lf\n", i, *(ptr_table_a + i));
			++i;
			++j;
		}
		else
		{
			printf("Table C [%1d] = %.1lf\n", i, *(ptr_table_a + i));
			++i;
		}
	}

	return 0;
}