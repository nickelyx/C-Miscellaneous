#include <stdio.h>

int Timer;
int Minutter;
int Sekunder;
int t;

int main(void)
{
	printf("Skriv et antal sekunder nedenfor\n");	
	scanf("%d", &t);
	Timer = t / 3600;
	t = t % 3600;
	Minutter = t / 60;
	t = t % 60;
	Sekunder = t;
	
	printf("%d Timer %d Minutter %d Sekunder", Timer, Minutter, Sekunder);
	return 0;
}