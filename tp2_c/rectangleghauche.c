#include<stdio.h>

double f (int t)
{
	return t;
}

double rectangle(int a,int b,int n)
{
	/*
	printf("donnez votre subdivision de n : ");
        scanf("%d",&n);
	*/
	double h=(double)(b-a)/n;
	printf("%f \n",h);
	double s=0;
	for(int i=0; i<n ;i++)
	{
		s+=f(a+i*h);
	}
	return h*s;
}
int main()
{
	int a=1 , b=9,n=9; 
	double x;

	x=rectangle(a,b,n);

	printf("%f \n",x);
}
	
