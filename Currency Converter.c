#include <stdio.h>
#include <math.h>

double Converter(double, double *, double *, double *, double *);

int main(void)
{
	double Dollars = 0, Euros = 0, Rupees = 0, Ruble = 0, Yen = 0; 

	printf("Input the amount of dollars: ");
	scanf("%lf", &Dollars);

	Converter(Dollars, &Euros, &Rupees, &Ruble, &Yen);

	printf("%.2lf Euros\n%.2lf Rupees\n%.2lf Ruble\n%.2lf Yen\n", Euros, Rupees, Ruble, Yen);
}

double Converter(double Dollars, double *Euros, double *Rupees, double *Ruble, double *Yen)
{
	*Euros = Dollars * 77;
	*Rupees = Dollars * 89.46;
	*Ruble = Dollars * 31.77;
	*Yen = Dollars * 77.88;

	return 0;
}