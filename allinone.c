#include<stdlib.h>
#include<stdio.h>
#include<math.h>

// function for the given equation

float f(float x)
{
    return x*x - x - 6;
}

//**************************************************************************************************************************

// derivative fof the given equation

float df (float x)
{
    return 2*x - 1;
}

//*************************************************************************************************************************

// code for newton rapshon method begins


void nr()
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

// code for newton rapshon method ends


//***********************************************************************************************************************


// code for secant method begins



int secant()
{
    float a,b,c=0,e;
    int count=0,n;
    float error;
    float conver;   
    // taking input for A and B
    printf("\nEnter the values of a and b:\n"); //(a,b) must contain the solution.
    scanf("%f%f",&a,&b);




   // checking condition for both input 
   if(f(a) == 0) {
	printf("the solution is %f\n",a);
	return 0;
  }

   if(f(b) == 0){
 	printf("the solution is %f\n",b);
	return 0;
    }

 if(f(a) * f(b) > 0){
	printf("the given input is wrong\n a,b should be on the opposite side of the root\n");
	return 0;
   }
 // checking of condition ends




// taking input for approximation and iteration number
    printf("Enter the values of allowed error and maximun number of iterations:\n");
    scanf("%f %d",&e,&n);



 // printing the heading
 printf("Iteration No.	   X0		X1	    Root	error\n\n");




// the main loop begins
    do
    {
       
        c=(a*f(b)-b*f(a))/(f(b)-f(a)); // the main formula
        error = fabs(a-b);
printf("%d              %f      %f      %f	%f\n",count+1,a,b,c,error);

        a=b;
        b=c;
       
        count++;

        // checking the condition if the iteration number exceeds
        if(count==n)
        {
	printf("the iteration number is very less to get the given approximation\n");
        break;
        }
        // condition checking ends



     } 
    // main loop ends
     while(fabs(f(c))>e); // the while loop for terminating  the do loop
    



    printf("\n\n\n after %d itteration the required solution is %f\n",count,c);// printing a final solution
    


    return 0; // return type
 
}


// code for secant method ends


//************************************************************************************************************************


// code for bisection method begins

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
void bis()
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


// code for bisection method ends


//*************************************************************************************************************************


// code for regula falsi method begins



void regula (float *x, float x0, float x1, float fx0, float fx1, int *itr)
{
    *x = x0 - ((x1 - x0) / (fx1 - fx0))*fx0;
    ++(*itr);
    printf("%d		%f	%f	%f	%f       %f\n",*itr,x0,x1,fabs(x0-x1),f(*x),*x);
}
void falsi()
{
    int itr = 0, maxmitr;
    float x0,x1,x2,x3,allerr;
    printf("\nEnter the values of x0, x1, allowed error and maximum iterations:\n");
    scanf("%f %f %f %d", &x0, &x1, &allerr, &maxmitr);
printf("iter. no.	 x1	         x2    	        abs. error	    fn value       root\n");
    regula (&x2, x0, x1, f(x0), f(x1), &itr);
  
    do
    {
        if (f(x0)*f(x2) < 0)
            x1=x2;
        else
            x0=x2;
        regula (&x3, x0, x1, f(x0), f(x1), &itr);
        if (fabs(x3-x2) < allerr)
        {
            printf("After %d iterations, root = %6.4f\n", itr, x3);
            return 0;
        }
        x2=x3;
    }
    while (itr<maxmitr);
    printf("after %d iterations the root is %f\n",itr,x3);
    printf("Solution does not converge or iterations not sufficient:\n");
    return 1;
}

// code for regula falsi method ends



//******************************************************************************************************************


// code for fixed point iteration method begins

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

int fixed()
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


// code for fixed point iteration method ends


//*****************************************************************************************************************************


// main function begins



int main(){
    
    
    
    printf("\n\narguments for newton rapshon\n\n");
    
    nr();
    
    printf("\n\narguments for secant method\n\n");
    
    secant();
    
    printf("\n\n arguments for bisection method\n\n");
    
    bis();
    
    printf("\n\n arguments for regula falsi method\n\n");
    
    falsi();
    
    printf("\n\n arguments for fixed point iteration method\n\n");
    
    fixed();
    
    
    
    return 0;
}


// main function ends

//******************************************** END OF PROGRAMME *********************************************************************************************888



