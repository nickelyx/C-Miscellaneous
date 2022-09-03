#include <stdio.h>
#include <string.h>

int test1(char *input, char *temp, int len);

int test2(char *input, int *len);

int main(void)
{
	char input[100] = "";
	char c;
	int len = 0;

	printf("Enter a word: ");
	scanf("%s", input);

	len = strlen(input);

	printf("%s %d\n", input, len);

	printf("%c", input[len-1]);

	c = input[len - 1];


	if(c == 'y')
	{
		char temp[20] = "ies";
		test1(input, temp, len);
	}
	else if(c == 's')
	{
		
	}
	else if(c == 'h')
	{
		
	}
	else
	{

	}

	return 0;
}


int test1(char *input, char *temp, int len)
{
	
	*strcat(char input[len-1], const char temp);
	printf("\n%s", temp);
	printf("\n%s", input);

	return 0;
}


int test2 (char *input, int *len)
{
	char temp;
	temp = input[*len - 2];

	if(temp == 's')
	{
		char *strcat(char *input, const char *c);
	}
	else if(temp == 'c')
	{
		char *strcat(char *input, const char *c);
	}
	else
		printf("Fejl");
}