#include <stdio.h>
#include <math.h>

int main(void)
{
    int p = 9870;
    int i = 0;

    while(p <= 30000)
    {
        i++;
        p = p * 1.1;
    }

    printf("%d", i);

    return 0;
}