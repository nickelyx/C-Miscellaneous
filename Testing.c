#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUMBER_OF_GAMES 198
#define NUMBER_OF_ROUNDS 33
#define NUMBER_OF_TEAMS 12
#define GAMES_PER_ROUND 6

int compare(const void *a, const void *b);

	typedef struct match 
	{
		char Day[4];
		int Date1;
		int Date2;
		double Time1;
		char Teams1[4];
		char Teams2[4];
		int Goals1;
		int Goals2;
		double Spectators1;
	} match;

	match Game[198];

int main(void)
{
	int i = 0;	


	char file_name[25];
	FILE *fp;

	int sum = 0;
	int temp = 0;
	

	printf("Enter the name of the file you wish to see\n");
	gets(file_name);

	fp = fopen(file_name, "r");

	if(fp == NULL)
	{
		perror("Error, unable to open file.\n");
		exit(EXIT_FAILURE);
	}

	
	while(i < NUMBER_OF_GAMES)
	{
		fscanf(fp, "%s %d %*c %d %lf %s %*c %s %d %*c %d %lf", Game[i].Day, &Game[i].Date1, &Game[i].Date2, &Game[i].Time1, Game[i].Teams1, Game[i].Teams2, &Game[i].Goals1, &Game[i].Goals2, &Game[i].Spectators1);
		
		sum = Game[i].Goals1 + Game[i].Goals2;

		if(sum >= 7)
		{
			printf("%s %d/%d %.2lf %s - %s %d - %d %.3lf\n", Game[i].Day, Game[i].Date1, Game[i].Date2, Game[i].Time1, Game[i].Teams1, Game[i].Teams2, Game[i].Goals1, Game[i].Goals2, Game[i].Spectators1);
		}
		else if(sum > temp)
		{
			temp = sum;
		}
		i++;
	}

	int Temp_Goal = 0;
	int Round = 0;
	int Goal = 0;
	i = 0;
	int Temp_Round = 0;

	while(i < NUMBER_OF_GAMES)
	{
		Goal += Game[i].Goals1 + Game[i].Goals2;
		
		if((i + 1) % 6 == 0)
		{
			Round++;

			if(Goal > Temp_Goal)
			{
				Temp_Goal = Goal;
				Goal = 0;
				Temp_Round = Round;
			}
			else
			{
				Goal = 0;
			}
		}

		i++;
			
	}

	printf("The Round With Most Goals is: %d with %d\n", Temp_Round, Temp_Goal);

	char Chosen_Day;
	double Lowest_Time = 0;
	double Highest_Time = 0;

	printf("\nEnter the day: ");
	scanf("%s", &Chosen_Day);
	printf("\nEnter the time it needs to be between: ");
	scanf(" %lf", &Lowest_Time);
	printf(" & ");
	scanf(" %lf", &Highest_Time);

	i = 0;



	typedef struct Matches 
	{
		char Day[4];
		int Date1;
		int Date2;
		double Time1;
		char Teams1[4];
		char Teams2[4];
		int Goals1;
		int Goals2;
		double Spectators1;
		int Sum;
	} Matches;

	Matches Cookie[198];




	int j = 0;


	qsort(Game, NUMBER_OF_GAMES, sizeof(match), compare);

	while(i < NUMBER_OF_GAMES)
	{
		if(Chosen_Day == *Game[i].Day)
		{
			if(Game[i].Time1 >= Lowest_Time && Game[i].Time1 <= Highest_Time)
			{
				printf(" %s %d/%d %.2lf %s - %s %d - %d %.3lf\n", Game[i].Day, Game[i].Date1, Game[i].Date2, Game[i].Time1, Game[i].Teams1, Game[i].Teams2, Game[i].Goals1, Game[i].Goals2, Game[i].Spectators1);
			
				j++;

			}
		}

		i++;
	}


	printf(" %d", j);
/*
	while(j > 0)
	{
		printf(" %s %d/%d %.2lf %s - %s %d - %d %.3lf\n", Cookie[j].Day, Cookie[j].Date1, Cookie[j].Date2, Cookie[j].Time1, Cookie[j].Teams1, Cookie[j].Teams2, Cookie[j].Goals1, Cookie[j].Goals2, Cookie[j].Spectators1);
		j--;
	}

	int k = j;

	while(j > 0)
	{
		Cookie[j].Sum = (Cookie[j].Goals1 + Cookie[j].Goals2);
		
		printf("%d\n", Cookie[j].Sum);

		j--;
	}

	qsort(Cookie.Sum, k sizeof(int), element_compare);

	printf("\nAfter sort: \n");
	for(n = 0; n < k; n++)
	{
		printf("%d", Cookie[n].Sum);
	}
*/


//START PÅ OPGAVE 3
/*
	typedef struct Team_Name
	{
		char Name[4];
	} Team_Name;

	Team_Name Name[12];
	int Home = 0;
	int Out = 0;


	while(i < NUMBER_OF_TEAMS)
	{
		while(j < NUMBER_OF_GAMES)
		{
			if(strcmp(const Name[i].Name, const Game[j].Teams1) == 0)
			{
				Home++;
			}
			else if(strcmp(const Name[i].Name, const Game[j].Teams2 == 0))
			{
				Out++;
			}

			j++;
		}
		if(Out > Home)
		{
			printf("%s scored more goals out than home", Name[i].Name);
		}
		Home = 0;
		Out = 0;
		j = 0;
		i++;
	}


*/


typedef struct Team_Name
{
	char Name[4];
	double Spectators;
	int Won;
	int Draw;
	int Point;
}Team_Name;

Team_Name TeamName[12];

int Home = 0;
int Out = 0;
j = 0;
i = 0;

int  g = 0, h = 1;

while(i < GAMES_PER_ROUND)
{
	strcpy(TeamName[g].Name, Game[i].Teams1);
	strcpy(TeamName[h].Name, Game[i].Teams2);
	g += 2;
	h += 2;
	i++;
}

i = 0;

while(i < NUMBER_OF_TEAMS)
{
	while(j < NUMBER_OF_GAMES)
	{
		if(strcmp(TeamName[i].Name, Game[j].Teams1) == 0)
		{
			if(Game[j].Goals1 > Game[j].Goals2)
			Home++;
		}
		else if(strcmp(TeamName[i].Name, Game[j].Teams2) == 0)
		{
			if(Game[j].Goals2 > Game[j].Goals1)
			Out++;
		}
		j++;
	}
	if(Out > Home)
	{
		printf("\n%s scored more goals out than home", TeamName[i].Name);
	}
	Home = 0;
	Out = 0;
	j = 0;
	i++;
}


/*Opgave 4*/

double d = 99999;

i = 0;
j = 0;

while(i < NUMBER_OF_TEAMS)
{
	while(j < NUMBER_OF_GAMES)
	{
		if(strcmp(TeamName[i].Name, Game[j].Teams1) == 0)
		{
			TeamName[i].Spectators += Game[j].Spectators1;
		}
		j++;
	}
	j = 0;
	i++;
}

i = 0;
j = 0;

while(i < NUMBER_OF_TEAMS)
{
	if(TeamName[i].Spectators < d)
	{
		d = TeamName[i].Spectators;
		j = i;
	}	
	i++;
}
printf("\n%s had the lowest amount of spectators with only %.3lf spectators", TeamName[j].Name, d);





printf("\n\n\n");






/*Opgave 6*/
j = 0;
i = 0;


while(i < NUMBER_OF_TEAMS)
{
	while(j < NUMBER_OF_GAMES)
	{
		if(strcmp(TeamName[i].Name, Game[j].Teams1) == 0)
		{
			if(Game[j].Goals1 > Game[j].Goals2)
			{
				TeamName[i].Won++;
			}
			else if(Game[j].Goals1 == Game[j].Goals2)
			{
				TeamName[i].Draw++;
			}
		}
		else if(strcmp(TeamName[i].Name, Game[j].Teams2) == 0)
		{
			if(Game[j].Goals1 < Game[j].Goals2)
			{
				TeamName[i].Won++;
			}
			else if(Game[j].Goals1 == Game[j].Goals2)
			{
				TeamName[i].Draw++;
			}
		}

		j++;
	}
	j = 0;
	i++;
}

i = 0;

while(i < NUMBER_OF_TEAMS)
{
	TeamName[i].Point = ((TeamName[i].Won * 3) + TeamName[i].Draw);
	printf("\n %s got %d points", TeamName[i].Name, TeamName[i].Point);
	i++;
}


while(i < NUMBER_OF_TEAMS)
{
	while(j < NUMBER_OF_GAMES)
	{
		Game[i].Goal_Diff = Game[j].Goals1;
	}
}












/*
	char Teams;

	i = 0;

	int AAB = 0;
	int AGF = 0;
	int BIF = 0;
	int EFB = 0;
	int FCK = 0;
	int FCN = 0;
	int FCM = 0;
	int FCV = 0;
	int OB  = 0;
	int RFC = 0;
	int SDR = 0;
	int VFF = 0;

	while(i < NUMBER_OF_GAMES)
	{
		if(Game[i].Goals1 < Game[i].Goals2)
		{
			Teams = *Game[i].Teams2;

			if(Teams == *"AAB")
				AAB += 1;
			else if(Teams == *"AGF")
				AGF += 1;
			else if(Teams == *"BIF")
				BIF += 1;
			else if(Teams == *"EFB")
				EFB += 1;
			else if(Teams == *"FCK")
				FCK += 1;
			else if(Teams == *"FCN")
				FCN += 1;
			else if(Teams == *"FCM")
				FCM += 1;
			else if(Teams == *"FCV")
				FCV += 1;
			else if(Teams == *"OB")
				OB += 1;
			else if(Teams == *"RFC")
				RFC += 1;
			else if(Teams == *"SDR")
				SDR += 1;
			else if(Teams == *"VFF")
				VFF += 1;
		}
		else if(Game[i].Goals2 < Game[i].Goals1)
		{
			Teams = *Game[i].Teams1;

			if(Teams == *"AAB")
				AAB -= 1;
			else if(Teams == *"AGF")
				AGF -= 1;
			else if(Teams == *"BIF")
				BIF -= 1;
			else if(Teams == *"EFB")
				EFB -= 1;
			else if(Teams == *"FCK")
				FCK -= 1;
			else if(Teams == *"FCN")
				FCN -= 1;
			else if(Teams == *"FCM")
				FCM -= 1;
			else if(Teams == *"FCV")
				FCV -= 1;
			else if(Teams == *"OB")
				OB -= 1;
			else if(Teams == *"RFC")
				RFC -= 1;
			else if(Teams == *"SDR")
				SDR -= 1;
			else if(Teams == *"VFF")
				VFF -= 1;
		}
		i++;
	}

	while(AAB > 0 || AGF > 0 || BIF > 0 || EFB > 0 || FCK > 0 || FCN > 0 || FCM > 0 || FCV > 0 || OB > 0 || RFC > 0 || SDR > 0 || VFF > 0)
	{
		if(AAB > 0)
		{
			printf("AAB scored more goals out than home\n");
			AAB = 0;
		}
		else if(AGF > 0)
		{
			printf("AGF scored more goals out than home\n");
			AGF = 0;
		}
		else if(BIF > 0)
		{
			printf("BIF scored more goals out than home\n");
			BIF = 0;
		}
		else if(EFB > 0)
		{
			printf("EFB scored more goals out than home\n");
			EFB = 0;
		}
		else if(FCK > 0)
		{
			printf("FCK scored more goals out than home\n");
			FCK = 0;
		}
		else if(FCN > 0)
		{
			printf("FCN scored more goals out than home\n");
			FCN = 0;
		}
		else if(FCM > 0)
		{
			printf("FCM scored more goals out than home\n");
			FCM = 0;
		}
		else if(FCV > 0)
		{
			printf("FCV scored more goals out than home\n");
			FCV = 0;
		}
		else if(OB > 0)
		{
			printf("OB scored more goals out than home\n");
			OB = 0;
		}
		else if(RFC > 0)
		{
			printf("RFC scored more goals out than home\n");
			RFC = 0;
		}
		else if(SDR > 0)
		{
			printf("SDR scored more goals out than home\n");
			SDR = 0;
		}
		else if(VFF > 0)
		{
			printf("VFF scored more goals out than home\n");
			VFF = 0;
		}
	}

START PÅ OPGAVE 4

	i = 0;
	AAB = 0;
	AGF = 0;
	BIF = 0;
	EFB = 0;
	FCK = 0;
	FCN = 0;
	FCM = 0;
	FCV = 0;
	OB  = 0;
	RFC = 0;
	SDR = 0;
	VFF = 0;


	while(i < NUMBER_OF_GAMES)
	{

		teams = *game[i].Teams1;

		if(teams == *"AAB")
		{
			AAB += *game[i].Spectators1;
		}
		else if(teams == *"AGF")
		{
			AGF += *game[i].Spectators1;
		}
		else if(teams == *"BIF")
		{
			BIF += *game[i].Spectators1;
		}
		else if(teams == *"EFB")
		{
			EFB += *game[i].Spectators1;
		}
		else if(teams == *"FCK")
		{
			FCK += *game[i].Spectators1;
		}
		else if(teams == *"FCN")
		{
			FCN += *game[i].Spectators1;
		}
		else if(teams == *"FCM")
		{
			FCM += *game[i].Spectators1;
		}
		else if(teams == *"FCV")
		{
			FCV += *game[i].Spectators1;
		}
		else if(teams == *"OB")
		{
			OB += *game[i].Spectators1;
		}
		else if(teams == *"RFC")
		{
			RFC += *game[i].Spectators1;
		}
		else if(teams == *"VFF")
		{
			VFF += *game[i].Spectators1;
		}

		i++;
	}

	temp = 0;

*/






	return 0;
}




int compare(const void *a, const void *b)
{
	match *GameA = (match *)a;
	match *GameB = (match *)b;

	return ((GameB->Goals1+GameB->Goals2) - (GameA->Goals1+GameA->Goals2));
}
/*

int element_compare(const void *ip1, const void *ip2)
{
	int result;
	int *ipi1 = (int *) ip1,
		*ipi2 = (int *) ip2;
	return int_compare(*ipi1, *ipi2);
}*/