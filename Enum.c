#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum forret {guacamole, tarteletter, lakserulle, graeskarsuppe};
enum hovedret {gyldenkaal, hakkeboef, gullash, forloren_hare};
enum dessert {pandekager_med_is, gulerodskage, chokolademousse, citronfromage};

void print_forret(enum forret d);
void print_hovedret(enum hovedret d);
void print_dessert(enum dessert d);

int main(void)
{
	int i = 0;

	srand(time(NULL));

	print_forret(rand()%4);
	print_hovedret(rand()%4);
	print_dessert(rand()%4);
}

void print_forret(enum forret d)
{
	switch(d)
	{
		case guacamole: printf("Guacamole\n");
			break;
		case tarteletter: printf("Tarteletter\n");
			break;
		case lakserulle: printf("Lakserulle\n");
			break;
		case graeskarsuppe: printf("Græskarsuppe\n");
			break;
	}
}

void print_hovedret(enum hovedret d)
{
	switch(d)
	{
		case gyldenkaal: printf("Gyldenkål\n");
			break;
		case hakkeboef: printf("Hakkeboef\n");
			break;
		case gullash: printf("Gullash\n");
			break;
		case forloren_hare: printf("Forloren Hare\n");
			break;
	}

}

void print_dessert(enum dessert d)
{
	switch(d)
	{
		case pandekager_med_is: printf("Pandekager Med Is\n");
			break;
		case gulerodskage: printf("Gulerodskage\n");
			break;
		case chokolademousse: printf("Chokolademouse\n");
			break;
		case citronfromage: printf("Citronfromage\n");
			break;
	}

}