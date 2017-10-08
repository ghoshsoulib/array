#include<stdio.h>
#include<math.h>

int main()
{

// taking variables
  float x[10],y[10][10],p,u,numerator=1.0, denominator=1.0,yp;
  int i,n,j,k=0,f,m;
// taking of variables ends
  
  
  // taking the input begins
  
  printf("\nwrite the order ");
  scanf("%d",&n); // taking the order 
  for(i=0; i<n; i++)
  {
   printf("\n value of x%d: ",i);
   scanf("%f",&x[i]);  // taking the x values
   printf("\n value of f(x%d): ",i);
   scanf("%f",&y[k][i]); // taking the respective y value
  }

  printf("\n\nEnter X where you want the value ");
  scanf("%f",&p); // where we have to find the value

// end of taking inputs


// checking condition for newton method
float diff;
diff = x[1] - x[0] ;
for(i=0;i<=n-2;i++){
	if((x[i+1] - x[i]) != diff){
	printf("the difference of x value is not same\n");
	return 0;
	}
}


// end of checking condition for newton method
// creating difference table
  for(i=1;i<n;i++)
  {
    for(j=0;j<n-i;j++)
    {
     y[i][j]=y[i-1][j+1]-y[i-1][j];
    }
  }
  
  // end of creating difference table
  
  
  //printing difference table starts
  printf("\n\n the difference table is as follows\n");
  printf("\n    x\t        y\t   ");
  printf("\n_____________________________________________________\n");
  for(i=0;i<n;i++)
  {
    printf("\n %.3f",x[i]);
    for(j=0;j<n-i;j++)
    {
     printf("   ");
     printf(" %.3f",y[j][i]);
    }
   printf("\n");
  }

// printing difference table ends


// the main interpolation process begins

f=0;
u=(p-x[f])/(x[f+1]-x[f]);
printf("\n the value of u = %.3f ",u);


yp = y[0][0];

  for (k=1;k<n;k++)
    {
        numerator *=u-k+1;
        denominator *=k;
        yp +=(numerator/denominator)*y[k][0];
    }
    printf("\nWhen x = %6.1f, corresponding y = %6.2f\n",p,yp);
    
    
// the main interpolation process ends

	return 0;
		
}






