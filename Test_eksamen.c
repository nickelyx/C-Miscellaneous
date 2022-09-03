#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 

int LineReader(char *);
int Seperate(char *, char *, char *, char *, char *, char *, char *);



int main(void)
{
	char Day[4] = "";
	char Date[6] = "";
	char Time[6] = "";
	char Teams[10] = "";
	char Goals[8] = "";
	char Spectators[7] = "";

    char ch, file_name[25];
    char Game[60] = "";
    FILE *fp;
 
 	printf("Enter the name of file you wish to see\n");
    gets(file_name);
 
    fp = fopen(file_name,"r"); // read mode
 
    if( fp == NULL )
    {
      	perror("Error while opening the file.\n");
      	exit(EXIT_FAILURE);
    }



 
   	printf("The contents of %s file are :\n", file_name);
 
   	while( ( ch = fgetc(fp) ) != EOF )
      	printf("%c",ch);


  	/*fgets(fp, sizeof(fp), stdin),
  	printf("%s", stdin);

*/
  	Seperate(file_name, Day, Date, Time, Teams, Goals, Spectators);




   	fclose(fp);
   	return 0;
}


int LineReader(char *file_name)
{
	return 0;
}



int Seperate(char *file_name, char *Day, char *Date, char *Time, char *Teams, char *Goals, char *Spectators)
{


	printf("Test");

	int i = 0, j = 0;

	int c;

	while (isalnum((int) file_name[i]))
	{
		i++;
	}

	strncpy(Day, file_name, i);
	Day[i + 1] = '\0';
	j = i;

	printf("%s",Day);

	printf("Test 2");

	while(isspace((int) file_name[i]))
	{
		i++;
	}
	j = i;



	printf("Test 3");

	while(isalnum((int) file_name[i]))
	{
		i++;
	}
	

	strncpy(Date, file_name + j, i - j);
	Date[i - j] = '\0';
	j = i;

	while(isspace((int) file_name[i]))
	{
		i++;
	}
	j = i;




	while(isalnum((int) file_name[i]))
	{
		i++;
	}

	strncpy(Time, file_name + j, i - j);
	Time[i - j] = '\0';
	j = i;

	while(isspace((int) file_name[i]))
	{
		i++;
	}
	j = i;




	while(isalnum((int) file_name[i]))
	{
		i++;
	}

	strncpy(Teams, file_name + j, i - j);
	Teams[i - j] = '\0';
	j = i;

	while(isspace((int) file_name[i]))
	{
		i++;
	}
	j = i;




	while(isalnum((int) file_name[i]))
	{
		i++;
	}

	strncpy(Goals, file_name + j, i - j);
	Goals[i - j] = '\0';
	j = i;

	while(isspace((int) file_name[i]))
	{
		i++;
	}
	j = i;

	printf("Test 4");


	while(isalnum((int) file_name[i]))
	{
		i++;
		printf("\nTesting");
	}

	c = getchar();

	printf("Test 5");

	strncpy(Spectators, file_name + j, i - j);
	j = i;

	printf("Død");

	while(c = getchar() != EOF)
	{
		file_name[i] = c;
		++i;
		printf("Kage");
	}

	printf("Det virkede?");

	
	return 0;
}