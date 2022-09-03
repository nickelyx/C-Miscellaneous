#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Prototype Function*/
int CalcBills(int);

int main(void)
{
	/*Creates variables*/

	int d;

	/*Asks user for amount of dollars in a number dividable by 10*/
	printf("Input an amount of dollars dividable by 10: ");
	scanf("%d", &d);

	/*Calculates the amount of bills*/
	CalcBills(d);
}

int CalcBills(int d)
{
	int Hundred;
	int Fifty;
	int Twenty;
	int Ten;

	if(d < 1)
	{
		printf("0 or negativ number cannot be used\n");
	}
	else if(d % 10 == 0)
	{
		Hundred = d / 100;
		d = d % 100;
		Fifty = d / 50;
		d = d % 50;
		Twenty = d / 20;
		d = d % 20;
		Ten = d / 10;

		/*Checks whether the amount is <= 0, write the amount of bills, either sincular or multiple*/
		Hundred <= 0 ? : Hundred == 1 ? printf("%d Hundred Dollar Bill\n", Hundred) : printf("%d Hundred Dollar Bills\n", Hundred);
		Fifty <= 0 ? : Fifty == 1 ? printf("%d Fifty Dollar Bill\n", Fifty) : printf("%d Fifty Dollar Bills\n", Fifty);
		Twenty <= 0 ? : Twenty == 1 ? printf("%d Twenty Dollar Bill\n", Twenty) : printf("%d Twenty Dollar Bills\n", Twenty);
		Ten <= 0 ? : Ten == 1 ? printf("%d Ten Dollar Bill\n", Ten) : printf("%d Ten Dollar Bills\n", Ten);
	}
	else
	{
		/*Gives an error if the amount is not dividable by 10, negativ or 0*/
		printf("Not a valid amount\n");
	}
	return 0;
}