#include <stdio.h>

int main(void)
{
    int Hours, Minutes, Seconds, t;

    printf("Input an amount of seconds: ");
    scanf("%d", &t);

    if(t > 0)
    {
        Hours = t / 3600;
        t = t % 3600;
        Minutes = t / 60;
        Seconds = t % 60;

        Hours <= 0 ? : Hours == 1 ? printf("%d Hour ", Hours) : printf("%d Hours ", Hours);
        Minutes <= 0 ? : Minutes == 1 ? printf("%d Minute ", Minutes) : printf("%d Minutes ", Minutes);
        Seconds <= 0 ? : Seconds == 1 ? printf("%d Second ", Seconds) : printf("%d Seconds", Seconds);
    }
    else
        printf("Not valid amount of seconds\n");

    return 0;
}   




#include <stdio.h>

int main(void)
{
    int Ones, Threes, Fives, t, sum;

    scanf("%d", &t);

    if(t > 0)
    {
        Fives = t / 5;
        t = t % 5;
        Threes = t / 3;
        Ones = t % 3;

        sum = Fives + Threes + Ones;
        
        printf("%d\n")
    }
    else
        printf("Not valid amount of seconds\n");

    return 0;
}   


#include <stdio.h>
int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    while (fgets(line, 1024, file)) {
        // Do something with the line
    }
    return 0;
}