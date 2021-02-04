#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f( double x)
{
    return pow(x,2);
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
int main ()
{
    double a =0;
    double b =1;
    int n = 10;
    printf ("%lf\n" , RecatangleDroite(f,a,b,n));
    printf ("%lf\n" , RectangleGauche(f,a,b,n));
    printf ("%lf\n" , Trapeze(f,a,b,n));
    printf ("%lf\n" , Simpson(f,a,b,n));
}

