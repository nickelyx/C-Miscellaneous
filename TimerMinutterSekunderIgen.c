#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*Angiver variabler*/
    int Timer;
    int Minutter;
    int Sekunder;
    int t;

    /*Giver prompt til bruger for input*/
    printf("Skriv et antal sekunder nedenfor\n");
    scanf("%d", &t);

    /*Tjekker om det angivne tal er større end 0*/
    if(t > 0)
    {
        /*Udregner antallet af timer etc.*/
        Timer = t / 3600;
        t = t % 3600;
        Minutter = t / 60;
        t = t % 60;
        Sekunder = t;

        /* Tjekker om antal er <= 0, skrive fx time hvis der 1 og fx timer ved flere.*/
        Timer <= 0 ? : Timer == 1 ? printf("%d Time ", Timer) : printf("%d Timer ", Timer);
        Minutter <= 0 ? : Minutter == 1 ? printf("%d Minut ", Minutter) : printf("%d Minutter ", Minutter);
        Sekunder <= 0 ? : Sekunder == 1 ? printf("%d Sekund ", Sekunder) : printf("%d Sekunder\n", Sekunder);
    }
    else
    {
        /*Giver fejl hvis antallet er negativt eller 0*/
        printf("Ikke gyldigt antal sekunder\n");
    }

    return 0;
}   