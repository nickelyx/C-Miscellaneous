#include <stdio.h>
#include <math.h>
double calc_g(double a, double h, int i);
double calc_h(double a, double h, int i);
double sum_calc(double a, double b, double n, double h, int sel);

int
main(void)
{
double a=0, b=0, h=0, n=0, sum=0;
int selected=0;
printf("indtast a og b vaerdier:\n");
scanf(" %lf %lf",&a,&b);
printf("indtast antal stykker du vil dele beregningen op i (større = mere precist:\n");
scanf(" %lf",&n);
printf("vælg funktion at teste 1=g 2=h\n");
scanf(" %d",&selected);
h=((b-a)/n);
printf("bredde h = %f\n",h);
sum=sum_calc(a,b,n,h,selected);

printf("arealet=%.4f\n",h/2*sum);

return(0);
}

double sum_calc(double a, double b, double n, double h, int sel)
{
double res=0, del=0;
int i=0;
if(sel==1)
{
while(i<n)
{
del=calc_g(a,h,i);
res+=del;
i++;
}
i=0;
del=calc_g(b,h,i);
printf("y værdien af b er %.2f\n",del);
res+=del;
return res;
}
else if(sel==2)
{
while(i<n)
{
del=calc_h(a,h,i);
res+=del;
i++;
}
i=0;
del=calc_g(b,h,i);
printf("y værdien af b er %.2f\n",del);
res+=del;
return res;
}
}
double calc_g(double a, double h, int i)
{
double x=0; double y=0;
x=(a+(i * h));
printf("nr %d x vaerdi er %.2f\n",i,x);
y=((x*x)*(sin(x)));
if(y>0)
return y;
else
return(0);
}

double calc_h(double a, double h, int i)
{
double x=0; double y=0;
x=(a+(i * h));
printf("det %d x er %.2f\n",i,x);
y=(sqrt(4-(x*x)));
if(y>0)
return y;
else
return(0);
}