#include <stdio.h>
#include <math.h>

int main(void)
{
    int n = 0;
    int i = 0;
    int m = 0;

    printf("Angiv en værdi: ");
    scanf("%i", &n);

    while(++i <= n)
    {
        m = m + i;
    }

    printf("Den udregnede værdi er: %d \n", m);
    printf("Tjekker om udregnede værdi er ens med (n * (n + 1) / 2");

    if((n * (n + 1) / 2) == m)
    {
        printf("\nVærdierne er ens");
    }
    else
    {
        printf("\nVærdierne er forskellige");
    }

    return 0;
}