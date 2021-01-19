#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

float *descente(float A[N][N], float B[N], int n)
{
float *x;
for(int i=0;i<n;i++)
{
        for(int j=0;j<n;j++)
                printf("%f \t",A[i][j]);
        printf("\n");
}
 x = malloc(sizeof(float)*n);
 x[0]=B[0]/A[0][0];
	for(int i=1;i<n;i++)
	{
		float s=0;
		for(int j=0;j<=i-1;j++)
		{
			s=s+A[i][j]*x[j];
		}
		x[i]=(B[i]-s)/A[i][i];

	}       
  return x;
}

float *remontee(float A[N][N], float B[N], int n)
{
float   *x;

x = malloc(sizeof(float)*n);
x[n-1]=B[n-1]/A[n-1][n-1];
for(int i=n-2;i>=0;i--)
        {
                float s=0;
                for(int j=i+1;j<n;j++)
                {
                        s=s+A[i][j]*x[j];
                }
        x[i]=(B[i]-s)/A[i][i];
        }
return x;
}



float *cholski(float A[N][N],float B[N],int n)
{
	float C[N][N];
        C[0][0]=sqrt(A[0][0]);
        for (int i=1; i<n;i++)
        {
                C[i][0]=A[i][0]/C[0][0];
        }
        for (int j=0; j<n ;j++)
        {
                for (int i=0 ; i<j-1;i++)
                {
                        C[i][j]=0;
                }
                for (int k=0;k<j-1;k++)
                {
                        C[j][j]=sqrt(A[j][j]-(C[j][k])*(C[j][k]));
                }
        
        	for (int i=j+1;i<n;j++)
        	{
                	for (int k=0;k<=j-1;k++)
                	{
                        	C[i][j]=(1/C[j][j])*(A[i][j]-(C[i][k])*(C[i][k]));
                	}

        	}
	}

	float CT[N][N];
	for(int i=0;i<n;i++)
	{
        	for(int j=0;j<n;j++)
                	CT[j][i]=C[i][j];
	}

	float *y=descente(C, B, n);
	for(int i=0;i<n;i++)
		printf("%f \t",y[i]);

	float   *x;
	x = malloc(sizeof(float) * n);
	x=remontee(CT, y, n);
	return x;
}


int main()
{
  float   A[N][N], B[N];
  float   *r;
  int     n;

  printf("Enter  la taille de la matrice : ");
  scanf("%d", &n);

  printf("donner les donner de la matrice A:\n");
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("A[%d][%d] = ", i, j);
      scanf("%f", &A[i][j]);
    }
  }
  printf("Filling the matrix B\n");
  for (int i = 0; i < n; i++)
 {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }
        /* calcule des resultas avec cholesky*/
  r=cholski(A, B, n);
  printf("\n");
  /* Printing the results */
  printf("\n The resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", r[i], ",]"[i == n - 1]);
  return (0);
}
