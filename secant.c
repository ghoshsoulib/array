#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float f(float x); // the function 

int main()
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
    



    printf("\n\n\n The required solution is %f\n",c);// printing a final solution
    


    return 0; // return type
 
}


// user defined function begins
float f(float x)
{
    return (x*x-9); 
}
// user defined function ends
