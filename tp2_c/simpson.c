#include<stdio.h>

double f (double t)
{
	return t;
}

double rectangle(double(*f)(double),double a,double b,double n)
{
	/*
	printf("donnez votre subdivision de n : ");
        scanf("%d",&n);
	*/
	double h=(double)(b-a)/n;
	printf("%f \n",h);
	double s,z,m,x;
	
	for(int i=0; i<n-1;i++)
	{
		z = a + (i+1/2)*h;
		s+=f(z+i*h);
		printf("%lf",z);
	}
	for(int i=1; i<n-1 ;i++)
	{
		x+=f(a+(i*h)); 
		printf("%lf",x);
	}
	m=(double)(h/6)*(f(a)+f(b)+4*s+2*x);
	
	return m;
}
int main()
{
	int a=1 , b=9,n=9; 
	double x;

	x=rectangle(f,a,b,n);

	printf("%f \n",x);
}
	
