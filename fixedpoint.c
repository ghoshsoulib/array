
#include<stdio.h>
#include<math.h>

float function (float x)
{
    return (x*x - 9);
}

float af (float x)
{
float y;
y = sqrt(x+6);
return y;
}


float derivative (float x)
{
	return (2*x - 1);
}

int main()
{
int count=1;
float x0,e; 
printf("write the initial approximation\n");
 
 printf("write the value of e\n");
 scanf("%f",&x0);
 scanf("%f",&e);
printf("iteration number	    X_i	         X_i+1	      absolute error\n");
float x1;
x1 = af(x0);

while((fabs(x1-x0) > e)){
printf("%d			%f	%f	   %f\n",count,x0,x1,fabs(x0-x1));
x0 = x1;
x1 = af(x0);
count++;
}
printf("the final root is %f\n you got the root after %d iteration\n",x1,count-1);
return 0;
}










