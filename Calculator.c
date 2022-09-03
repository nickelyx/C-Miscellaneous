#include <stdio.h>
#include <math.h>

double Scan_Data(double *, double *, char *);

int main(void)
{
	double a = 0, b = 0;
	char c = 0;
	printf("To Exit the program enter q0\nEnter a start value: ");

	Scan_Data(&a, &b, &c);
}

double Scan_Data(double *a, double *b, char *c)
{
	int done = 0;

	while(!done)
	{
		scanf(" %c %lf", c, b);
		

		switch(*c)
		{
			case '+':
			{
				*a = *a + *b;
				break;
			}

			case '-':
			{
				*a = *a - *b;
				break;
			}

			case '*':
			{
				*a = *a * *b;
				break;
			}

			case '/':
			{
				*a = *a / *b;
				break;
			}

			case '^':
			{
				double p = pow(*a, *b);
				*a = p;
				break;	
			}

			case 'q':
			{
				return (done);
			}
		}

		printf("Result so far is: %.2lf\n", *a);
	}
}