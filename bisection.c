#include<stdio.h>
#include<math.h>
float function (float x)
{
    return (x*x - x - 6);
}
void bisection (float *x, float a, float b, int *itr)
/* this function performs and prints the result of  iteration one after another */
{
  double abserror;
 double error;
 double temp;
  temp = abserror/fabs(a-b);
  error = log(temp);
  abserror = fabs(a-b); 
  
    *x=(a+b)/2;
    ++(*itr);
  
    printf("%d	           %f	%f	%f	%f\n",*itr,*x,a,b,fabs(a-b));	           
}
void main ()
{
    int itr = 0, maxmitr;
    float x, a, b, allerr, x1;
   
    printf("\nEnter the values of a, b, allowed error and maximum iterations:\n");
    scanf("%f %f %f %d", &a, &b, &allerr, &maxmitr);

     // checking condition if 'a' is the root 
  
	if ( function(a) == 0) {
	   printf("You have entered the root of the given equation.\n");
		return 0;
		exit(0);
	}

     // checking condition if 'b' is the root
      
         if ( function(b) == 0) {
             printf("You have entered the root of the given equation. \n");
                exit(0);
        }

   // checking wheather the input 'a' and 'b' is given properly or not

  if(function(a)*function(b) > 0){
       printf("you have given wrong value of 'a' and 'b'\n");
       exit(0);
      }

  // starting of the calculation


 printf("\n\nIter no.             root          a              b           error\n");

    bisection (&x, a, b, &itr);
    do
    {
        if(function(a)*function(x) == 0){
           
	   printf("you got the exact root before the given number of iteration and the root is %f\n",x);
       return x;
	   exit(0);
        }
        if (function(a)*function(x) < 0)
            b=x;
        else
            a=x;
        bisection (&x1, a, b, &itr);
	
        if (fabs(x1-x) < allerr)
        {
            printf("After %d iterations, root = %6.4f\n", itr, x1);
            return 0;
        }
        x=x1;
    }

    // if the iteration number is not sufficient according to the given approximation then the return argument

    while  (itr < maxmitr);
    printf(" iterations are not sufficient. Try with some large value of iterations.\n");
    return 0;
}
