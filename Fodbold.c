#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define NUMBER_OF_GAMES 198
#define NUMBER_OF_ROUNDS 33
#define NUMBER_OF_TEAMS 12
#define GAMES_PER_ROUND 6

int Find_Goals(FILE *fp);
int Most_Goal_Round(FILE *fp);
int Time_And_Day(FILE *fp);
int Least_Spectator_Amount(FILE *fp);
int More_Out_Than_Home(FILE *fp);
int compare(const void *a, const void *b);
int Order(const void *a, const void *b);


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

typedef struct Team_Name
{
	char Name[4];
	double Spectators;
	int Won;
	int Draw;
	int Point;
	int Total_Goals;
	int Games;
	int Goals_For;
	int Goals_Against;
	int Goal_Diff;
} Team_Name;

Team_Name Team[12];


int main(int argc, char **argv)
{
	char file_name[25];
	int Choice = 0;
	int c;
	
	FILE *fp;
	
	printf("Enter the name of the file you wish to see\n");
	gets(file_name);

	fp = fopen(file_name, "r");

	if(fp == NULL)
	{
		perror("Error, unable to open file.\n");
		exit(EXIT_FAILURE);
	}

	if(c = getopt (argc, argv, "--print") != -1)
	{
		Find_Goals(fp);
		Most_Goal_Round(fp);
		More_Out_Than_Home(fp);
		Least_Spectator_Amount(fp);
		Time_And_Day(fp);
		Calc_Print_Table(fp);
	}

	printf("Choose what you want to find\n 1. More Than 7 Goals\n 2. Round with most goals\n 3. More Goals Out\n 4. Least Amount of Spectators\n 5. Time And Day\n 6. Print Table: ");
	scanf("%d", &Choice);

	if(Choice == 1)
	{
		Find_Goals(fp);
	}
	else if(Choice == 2)
	{
		Most_Goal_Round(fp);
	}
	else if(Choice == 3)
	{
		More_Out_Than_Home(fp);
	}
	else if(Choice == 4)
	{
		Least_Spectator_Amount(fp);
	}
	else if(Choice == 5)
	{
		Time_And_Day(fp);
	}
	else if(Choice == 6)
	{
		Calc_Print_Table(fp);
	}
	else
	{
		printf("Wrong fucking number");
	}

	fclose(fp);

	return 0;
}

/*Opgave 1*/

int Find_Goals(FILE *fp)
{
	int i = 0, sum = 0, temp = 0;

	while(i < NUMBER_OF_GAMES)
	{
		fscanf(fp, " %s %d %*c %d %lf %s %*c %s %d %*c %d %lf", Game[i].Day, &Game[i].Date1, &Game[i].Date2, &Game[i].Time1, Game[i].Teams1, Game[i].Teams2, &Game[i].Goals1, &Game[i].Goals2, &Game[i].Spectators1);
		
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

	return 0;
}

/*Opgave 2*/

int Most_Goal_Round(FILE *fp)
{
	int i = 0;
	int Goal = 0, Temp_Goal = 0;
	int Round = 0, Temp_Round = 0;

	while(i < NUMBER_OF_GAMES)
	{
		fscanf(fp, " %s %d %*c %d %lf %s %*c %s %d %*c %d %lf", Game[i].Day, &Game[i].Date1, &Game[i].Date2, &Game[i].Time1, Game[i].Teams1, Game[i].Teams2, &Game[i].Goals1, &Game[i].Goals2, &Game[i].Spectators1);

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

	printf("The Round With Most Goals is: %d with %d goals", Temp_Round, Temp_Goal);

	return 0;
}

/*Opgave 3*/

int More_Out_Than_Home(FILE *fp)
{
	int i = 0, j = 0, g = 0, h = 1;
	int Home = 0, Out = 0;

	while(i < NUMBER_OF_GAMES)
	{
		fscanf(fp, "%s %d %*c %d %lf %s %*c %s %d %*c %d %lf", Game[i].Day, &Game[i].Date1, &Game[i].Date2, &Game[i].Time1, Game[i].Teams1, Game[i].Teams2, &Game[i].Goals1, &Game[i].Goals2, &Game[i].Spectators1);
		i++;
	}

	i = 0;

	while(i < GAMES_PER_ROUND)
	{
		strcpy(Team[g].Name, Game[i].Teams1);
		strcpy(Team[h].Name, Game[i].Teams2);
		g += 2;
		h += 2;
		i++;
	}

	i = 0;

	while(i < NUMBER_OF_TEAMS)
	{
		while(j < NUMBER_OF_GAMES)
		{
			if(strcmp(Team[i].Name, Game[j].Teams1) == 0)
			{
				if(Game[j].Goals1 > Game[j].Goals2)
				Home++;
			}
			else if(strcmp(Team[i].Name, Game[j].Teams2) == 0)
			{
				if(Game[j].Goals2 > Game[j].Goals1)
				Out++;
			}
			j++;
		}
		if(Out > Home)
		{
			printf("\n%s scored more goals out than home", Team[i].Name);
		}
		Home = 0;
		Out = 0;
		j = 0;
		i++;
	}

	return 0;
}

/*Opgave 4*/

int Least_Spectator_Amount(FILE *fp)
{
	int i = 0, j = 0, g = 0, h = 1;
	double d = NUMBER_OF_GAMES;

	while(i < NUMBER_OF_GAMES)
	{
		fscanf(fp, " %s %d %*c %d %lf %s %*c %s %d %*c %d %lf", Game[i].Day, &Game[i].Date1, &Game[i].Date2, &Game[i].Time1, Game[i].Teams1, Game[i].Teams2, &Game[i].Goals1, &Game[i].Goals2, &Game[i].Spectators1);
		i++;
	}

	i = 0;

	while(i < GAMES_PER_ROUND)
	{
		strcpy(Team[g].Name, Game[i].Teams1);
		strcpy(Team[h].Name, Game[i].Teams2);
		g += 2;
		h += 2;
		i++;
	}

	i = 0;

	while(i < NUMBER_OF_TEAMS)
	{
		while(j < NUMBER_OF_GAMES)
		{
			if(strcmp(Team[i].Name, Game[j].Teams1) == 0)
			{
				Team[i].Spectators += Game[j].Spectators1;
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
		if(Team[i].Spectators < d)
		{
			d = Team[i].Spectators;
			j = i;
		}
		i++;
	}
	printf("\n%s had least overall spectators with only %.3lf spectators", Team[j].Name, d);

	return 0;
}

/*Opgave 5*/

int Time_And_Day(FILE *fp)
{
	char Chosen_Day;
	double Lowest_Time = 0;
	double Highest_Time = 0;


	printf("\nEnter the day: ");
	scanf("%s", &Chosen_Day);
	printf("\nEnter the time it needs to be between: ");
	scanf(" %lf", &Lowest_Time);
	printf(" & ");
	scanf(" %lf", &Highest_Time);

	int i = 0;
	
	while(i < NUMBER_OF_GAMES)
	{		
		fscanf(fp, " %s %d %*c %d %lf %s %*c %s %d %*c %d %lf", Game[i].Day, &Game[i].Date1, &Game[i].Date2, &Game[i].Time1, Game[i].Teams1, Game[i].Teams2, &Game[i].Goals1, &Game[i].Goals2, &Game[i].Spectators1);
		i++;
	}

	i = 0;

	qsort(Game, NUMBER_OF_GAMES, sizeof(match), compare);

	while(i < NUMBER_OF_GAMES)
	{
		if(Chosen_Day == *Game[i].Day)
		{
			if(Game[i].Time1 >= Lowest_Time && Game[i].Time1 <= Highest_Time)
			{
				printf("%s %d/%d %.2lf %s - %s %d - %d %.3lf\n", Game[i].Day, Game[i].Date1, Game[i].Date2, Game[i].Time1, Game[i].Teams1, Game[i].Teams2, Game[i].Goals1, Game[i].Goals2, Game[i].Spectators1);
			}
		}

		i++;
	}

	return 0;
}

/*Opgave 6*/

int Calc_Print_Table(FILE *fp)
{
	int i = 0, j = 0, g = 0, h = 1;

	while(i < NUMBER_OF_GAMES)
	{
		fscanf(fp, " %s %d %*c %d %lf %s %*c %s %d %*c %d %lf", Game[i].Day, &Game[i].Date1, &Game[i].Date2, &Game[i].Time1, Game[i].Teams1, Game[i].Teams2, &Game[i].Goals1, &Game[i].Goals2, &Game[i].Spectators1);
		i++;
	}

	i = 0;

	while(i < GAMES_PER_ROUND)
	{
		strcpy(Team[g].Name, Game[i].Teams1);
		strcpy(Team[h].Name, Game[i].Teams2);
		g += 2;
		h += 2;
		i++;
	}

	i = 0;

	while(i < NUMBER_OF_TEAMS)
	{
		while(j < NUMBER_OF_GAMES)
		{
			if(strcmp(Team[i].Name, Game[j].Teams1) == 0)
			{
				Team[i].Games++;
				Team[i].Total_Goals += Game[j].Goals1;
				Team[i].Goals_For += Game[j].Goals1;
				Team[i].Goals_Against += Game[j].Goals2;

				if(Game[j].Goals1 > Game[j].Goals2)
				{
					Team[i].Won++;
				}
				else if(Game[j].Goals1 == Game[j].Goals2)
				{
					Team[i].Draw++;
				}
			}
			else if(strcmp(Team[i].Name, Game[j].Teams2) == 0)
			{
				Team[i].Games++;
				Team[i].Total_Goals += Game[j].Goals2;
				Team[i].Goals_For += Game[j].Goals2;
				Team[i].Goals_Against += Game[j].Goals1;

				if(Game[j].Goals1 < Game[j].Goals2)
				{
					Team[i].Won++;
				}
				else if(Game[j].Goals1 == Game[j].Goals2)
				{
					Team[i].Draw++;
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
		Team[i].Goal_Diff = Team[i].Goals_For - Team[i].Goals_Against;
		Team[i].Point = ((Team[i].Won * 3) + Team[i].Draw);
		i++;
	}

	qsort(Team, NUMBER_OF_TEAMS, sizeof(Team_Name), Order);

	i = 0;

	printf("\nName|Points|Games|Won|Draw|Lost|For|Against|Diff");

	while(i < NUMBER_OF_TEAMS)
	{
		printf("\n %3s|%6d|%5d|%3d|%4d|%4d|%3d|%7d|%4d", Team[i].Name, Team[i].Point, Team[i].Games, Team[i].Won, Team[i].Draw, Team[i].Games - (Team[i].Won + Team[i].Draw), Team[i].Goals_For, Team[i].Goals_Against, Team[i].Goal_Diff);
		i++;
	}
}


/*Compare Function for qsort*/

int compare(const void *a, const void *b)
{
	match *GameA = (match *)a;
	match *GameB = (match *)b;

	return ((GameB->Goals1+GameB->Goals2) - (GameA->Goals1+GameA->Goals2));
}

int Order(const void *a, const void *b)
{
	Team_Name *TeamA = (Team_Name *)a;
	Team_Name *TeamB = (Team_Name *)b;


	if((TeamA->Point) < (TeamB->Point))
	{
		return 1;
	}
	else if((TeamA->Point) > (TeamB->Point))
	{
		return -1;
	}
	else
	{
		if((TeamA->Total_Goals) < (TeamB->Total_Goals))
		{
			return 1;
		}
		else if((TeamA->Total_Goals) > (TeamB->Total_Goals))
		{
			return -1;
		}
	}

}