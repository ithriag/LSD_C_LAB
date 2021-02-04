#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

int main()
{
double *descente(double A[N][N], double B[N], int n)
{
  double   *x;
  x = malloc(sizeof(double) * n);
  int i, j;
  double s;
  x[0]=B[0]/A[0][0];
  for(i=1;i<n;i++)
  {
        s=0;
        for(j=0;j<i;j++)
               s=s+A[i][j] * x[j];
        x[i]=(B[i]-s)/A[i][i];
  }
 

  return (x);
}

double *remontee(double A[N][N], double B[N], int n)
{

  double *x;
  x = malloc(sizeof(double) * n);
  int i, j;
  double s;
  x[n-1]=B[n-1]/A[n-1][n-1];
  for(i=n-2;i>=0;i--)
  {
         s=0;
         for(j=i+1;j<n;j++)
                s+=A[i][j] * x[j];
         x[i]=(B[i]-s)/A[i][i];
   }
  return (x);
}


int main()
  /* 
  ** What are you looking for ? \
  ** go ahead and code the solution by yourself. \
  ** you can always ask for help on slack.
  */

int i, j, k, n;
        double T[N][N];
        double *X;
        X = malloc(sizeof(double)*n);
        double *Y;
        Y=malloc(sizeof(double)*n);
	printf("Donner la taille de la matrice: ");
	scanf("%d", &n);
	double c[N][N], A[N][N], B[N], s, s1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("A[%d][%d]: ", i, j);
			scanf("%lf", &A[i][j]);
		}
	
	}
        
        for(i=0;i<n;i++)
        {
               printf("B[%d]: ", i);
               scanf("%lf", &B[i]);
        }
	c[0][0]=sqrt(A[0][0]);
	for(i=1;i<n;i++)
		c[i][0]=A[i][0]/c[0][0];
	for(j=1;j<n;j++)
	{
		for(i=0;i<j - 1;i++)
			c[i][j]=0;
		s = 0.0;
		for(k=0;k<j;k++)
	        	s+=pow(c[j][k], 2);
		c[j][j]=sqrt(A[j][j]-s);
		for(i=j + 1;i<n;i++)
		{
			s1 = 0.0;
			for(k=0;k<j;k++)
				s1+=c[i][k]*c[j][k];
			c[i][j]=(1.0/c[j][j])*(A[i][j]-s1);
		}
	}
        printf("\n");
        printf("C:\t");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
	        	printf("%lf\t", c[i][j]);
                printf("\n");
	}
        /*Transpose*/
        printf("T: \n");
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        T[i][j]=c[j][i];
                        printf("%lf\t", T[i][j]);
               
                }
                printf("\n");
        }        
         /*The system resolution*/
         double *V1;
         double *V2;
            
         V1 = descente(c, B, n);
         V2 = remontee(T, V1, n);

         printf("%lf, %lf, %lf, %lf\n", V1[0], V1[1], V1[2], V1[3]);
         printf("%lf, %lf, %lf, %lf\n", V2[0], V2[1], V2[3], V2[3]);
	 
  return (0);
}

