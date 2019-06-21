#include<stdio.h>
void splitfloat(float x,int *intpart,float *fracpart);
int main()
{
	float x,fracpart;
	int intpart;
	printf("Enter number x:");
	scanf("%f",&x);
	splitfloat(x,&intpart,&fracpart);
	printf("intpart:%d\nfracpart:%f",intpart,fracpart);
}
void splitfloat(float x,int *intpart,float *fracpart)
{
	*intpart=(int)x;
	*fracpart=x-(int)x;
}
