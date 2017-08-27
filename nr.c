#include<stdio.h>
#include<math.h>
float f(float x)
{
    return x*x - 9;
}
float df (float x)
{
    return 2*x;
}
void main()
{
    int itr, maxmitr;
	float g,i;
    float h,h1=0, x0, x1, allerr;
    printf("\nEnter x0, allowed error and maximum iterations\n");
    scanf("%f %f %d", &x0, &allerr, &maxmitr);
printf("itteration number       x1         x2        absoulute_error         function_value        convergence\n");

    for (itr=1; itr<=maxmitr; itr++)
    {
        h=f(x0)/df(x0);
        x1=x0-h;
	g = h1/h;
        i = log(g);
        
        if (fabs(h) < allerr)
        {
            printf("After %3d iterations, root = %8.6f\n", itr-1, x1);
            return 0;
        }
	
	h1 = fabs(x1-x0);

printf("%d		   %f	%f	%f	       %f           %f\n",itr,x0,x1,h1,f(x0),i);
        x0=x1;
	
    }
    printf(" The required solution does not converge or iterations are insufficient\n");
    return 1;
}
