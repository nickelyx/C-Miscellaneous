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
  double discriminant, root1, root2;

  discriminant = SolveDiscriminant(a, b, c);

  if (discriminant < 0)
    printf("No roots\n\n");
  else if (discriminant == 0)
  {
    root1 = SolveRoot1(a, b, discriminant);
    printf("One root: %.2f\n\n", root1);
  }
  else 
  {
    root1 = SolveRoot1(a, b, discriminant);
    root2 = SolveRoot2(a, b, discriminant);

    printf("Two roots: %.2f and %.2f\n\n", root1, root2);
  }
}

/*Function solving the discriminant*/
double SolveDiscriminant(double a, double b, double c)
{
  double discriminant;

  discriminant = b * b - 4 * a * c;

  return(discriminant);
}

/*Function solving the first root*/
double SolveRoot1(double a, double b, double discriminant)
{
  double root1;

  root1 = (-b + sqrt(discriminant)) / (2 * a);

  return(root1);
}

/*Functions solving the second root*/
double SolveRoot2(double a, double b, double discriminant)
{
  double root2;

  root2 = (-b - sqrt(discriminant)) / (2 * a);

  return(root2);
}