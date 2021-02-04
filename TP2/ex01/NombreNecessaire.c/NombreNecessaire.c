#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f( double x)
{
    return exp((-pow(x,2))/2);
}
double RecatangleDroite(double(*f)(double), double a,double b,int n)
{
    double h = (b - a)/n;
    double s = 0;
    int i;
    for ( i = 0 ; i < n; i++)
            s = s + f(a +i *h);
    return(h * s);
}
double RectangleGauche(double(*f)(double),double a , double b,int n)
{
    double h = (b - a)/n;
    double  s  = 0;
    int i;
    for ( i = 0 ; i < n -1 ; i++)
            s = s + f(a +i *h);
    return(h * s);
}
double Trapeze(double(*f)(double),double a,double  b ,int n)
{

    double h = (b -a )/n;
    double z = 0.5 * (f(a ) + f(b));
    int i;
    for (i = 1; i < n;i++)
        z = z +f(a + i * h);
    return h * z;
}
double Simpson(double(*f)(double),double a,double b ,int n)
{
    double h = (b -a )/n;
    double z = (f(a) + f(b))/6;
    int i;
    for (i = 1; i< n ; i++)
        z= z + f(a+ i * h) / 3;
    for (i = 0;i<n ;i++)
         z= z + f ( a + ( 2 * i + 1)  * h/2) * 2/3;

    return h * z;
}
double NombreNecessaire(double(*f)(double),double a,double b, double(*Methode)(double(*)(double), double, double, int), double Err)
{
       double I=0.855624391892149;
       double n=1;
       while(fabs(Methode(f, a, b, n)-I)>Err)
       {
               n=n+1;
       }
       return n;
}

int main()
{
        int a=0;
        int b=1;
        double Err=pow(10, -9);
        printf("%lf", NombreNecessaire(f, a, b, Simpson, Err));
        printf("\n");
        return 0;
}

















