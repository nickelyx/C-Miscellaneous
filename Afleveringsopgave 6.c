#include <stdio.h>
#include <math.h>

double calc_sum(double, double, double, double, int);
double calc_g(double, double, int);
double calc_h(double, double, int);

int main(void)
{
    double a = 0, b = 0, h = 0, n = 0, sum = 0;
    int selected = 0;

    printf("Input a value for a: ");
    scanf(" %lf", &a);
    printf("Input a value for b: ");
    scanf(" %lf", &b);

    printf("Input the amount to divide the calculation in: ");
    scanf(" %lf", &n);

    printf("Choose function to use, 1 = g  2 = h: ");
    scanf(" %d", &selected);

    h = ((b - a) / n);

    printf("Width h = %f\n", h);

    sum = calc_sum(a, b, h, n, selected);

    printf("The area = %.4f\n", ((h / 2) * sum));

    return 0;
}

double calc_sum(double a, double b, double h, double n, int selected)
{
    double res = 0, sub = 0;
    int i = 0;

    if(selected == 1)
    {
        while(i < n)
        {
            sub = calc_g(a, h, i);
            res += sub;
            i++;
        }

        i = 0;
        sub = calc_g(b, h, i);
        printf("The y value of b is: %.2f\n", sub);
        res += sub;

        return res;
    }
    else if (selected == 2)
    {
        while(i < n)
        {
            sub = calc_g(a, h, i);
            res = res + sub;
            i++;
        }

        i = 0;
        sub = calc_h(b, h, i);
        printf("The y value of b is: %.2f\n", sub);
        res += sub;

        return res;
    }
}

double calc_g(double a, double h, int i)
{
    double x = 0, y = 0;
    
    x = (a + (i * h));

    y = ((x * x) * (sin(x)));

    if(y > 0)
        return y;
    else
        return 0;
}

double calc_h(double a, double h, int i)
{
    double x = 0, y = 0;
    
    x = (a + (i * h));

    y = (sqrt(4 - (x * x)));

    if(y > 0)
        return y;
    else
        return 0;
}