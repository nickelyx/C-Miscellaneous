#include <stdio.h>

int Fag = 1;
int Studenter = 0;
int Grupper = 0;
int Gennemsnit = 0;

int main(void)
{
	printf("Angiv Antal af Grupper: \n");
	scanf("%d", &Grupper);
	printf("Angiv Antal Studenter: \n");
	scanf("%d", &Studenter);
	
	Gennemsnit = Studenter / Grupper;
	
	printf("Der er %d studenter pr. gruppe i %d fag\n", Gennemsnit, Fag);
	
	return 0;
}