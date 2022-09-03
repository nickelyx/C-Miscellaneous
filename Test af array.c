#include <stdio.h>

int main(void)
{
	int i = 0, j = 0;

	double table_a[] = {-10.5, -1.8, 3.5, 6.3, 7.2};
	double table_b[] = {-1.8, 3.1, 6.3};
	
	double *ptr_table_a = &table_a[0];
	double *ptr_table_b = &table_b[0];

	while((ptr_table_a + i) < &table_a[5])
	{
		if(*(ptr_table_a + i) < *(ptr_table_b + j) && (ptr_table_a + i) < &table_a[5])
		{
			printf("Table C [%1d] = %.1lf\n", i, *(ptr_table_a + i));
			++i;
		}
		else if(*(ptr_table_b + j) < *(ptr_table_a + i) && (ptr_table_b + j) < &table_b[3])
		{
			printf("Table C [%1d] = %.1lf\n", j, *(ptr_table_b + j));
			++j;
		}
		else if(*(ptr_table_a + i) == *(ptr_table_b + j) && (ptr_table_a + i) < &table_a[5] && (ptr_table_b + j) < &table_b[3])
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