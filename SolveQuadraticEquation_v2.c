#include <stdio.h>
#include <math.h>

/*Prototype Functions*/
void SolveQuadraticEquation(double, double, double);
double SolveDiscriminant(double, double, double);
double SolveRoot1(double, double, double);
double SolveRoot2(double, double, double);

int main(void) 
{
  double a = 1; 
  double b = 1; 
  double c = 1;

  do
  {
    /*Asking for coeficients*/
    printf("Enter coeficient a: ");
    scanf("%lf", &a);

    printf("Enter coeficient b: ");
    scanf("%lf", &b);

    printf("Enter coeficient c: ");
    scanf("%lf", &c);

    /*Checking whether or not the coeficients make up a Quadratic Equation*/
    if(a == 0 && b == 0 && c == 0)
    {
      printf("All variables can't be 0, program will now terminate\n");
      break;
    }
    else if(a == 0)
    {
      printf("This is not a Quadratic Equation, program will now terminate\n");
      break;
    }
    else
    {
      SolveQuadraticEquation(a, b, c);  
    }
  }
  while(a != 0 || b != 0 || c != 0);
  
  return 0;
}

/* Prints roots of the quadratic equation a * x*x + b * x + c = 0 */
void SolveQuadraticEquation(double a, double b, double c)
{
  double discriminant = SolveDiscriminant(a, b, c);

  if (discriminant < 0)
    printf("No roots\n\n");
  else if (discriminant == 0)
    printf("One root: %.4f\n\n", SolveRoot1(a, b, discriminant));
  else 
    printf("Two roots: %.4f and %.4f\n\n", SolveRoot1(a, b, discriminant), SolveRoot2(a, b, discriminant));
}

/*Function solving the discriminant*/
double SolveDiscriminant(double a, double b, double c)
{
  return b * b - 4 * a * c;
}

/*Function solving the first root*/
double SolveRoot1(double a, double b, double discriminant)
{
  return (-b + sqrt(discriminant)) / (2 * a);
}

/*Functions solving the second root*/
double SolveRoot2(double a, double b, double discriminant)
{
  return (-b - sqrt(discriminant)) / (2 * a);
}