#include <stdio.h>

int CalcSeconds(int);

int main(void)
{
	int t;

	/*Asks the user for a number of seconds*/
	printf("Input an amount of seconds: ");
	scanf("%d", &t);

	if(t > 0)
		CalcSeconds(t);
	else
		/*Gives error if the amount of seconds is negativ or 0*/
		printf("Not valid amount of seconds\n");

	return 0;
}

int CalcSeconds(int t)
{
	int Hours, Minutes, Seconds;

	/*Calculates the amount of Hours, Minutes & Seconds*/
	Hours = t / 3600;
	t = t % 3600;
	Minutes = t / 60;
	Seconds = t % 60;

	Hours <= 0 ? : Hours == 1 ? printf("%d Hour ", Hours) : printf("%d Hours ", Hours);
	Minutes <= 0 ? : Minutes == 1 ? printf("%d Minute ", Minutes) : printf("%d Minutes ", Minutes);
	Seconds <= 0 ? : Seconds == 1 ? printf("%d Second ", Seconds) : printf("%d Seconds ", Seconds);
	
	return 0;
}