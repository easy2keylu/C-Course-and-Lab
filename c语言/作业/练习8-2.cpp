#include <stdio.h>
#include <math.h>
void sum_diff(float op1, float op2, float *psum, float *pdiff);
static float op1,op2,sum,diff,*psum,*pdiff;
int main(void)
{
	printf("Enter 2 numbers:");
	scanf ("%f %f",&op1,&op2);
	sum_diff(op1, op2, &sum, &diff);
	printf("sum=%f\ndiff=%f",*psum,*pdiff);
}
void sum_diff(float op1, float op2, float *psum, float *pdiff)
{
	*psum=op1+op2;
	*pdiff=abs(op1-op2);
}
