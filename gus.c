#include<stdio.h>
int main()
{
    int i,j,k,n;
    float A[20][20],c,x[10],sum=0.0;
    
    // A is the augmented marix
    // X is the variables
    // n is the number of variables
    
    
    printf("\nEnter the order of matrix or the number of variables: ");
    //asking for the number of variables
    scanf("%d",&n);
   
    
    //asking for the input of the co efficients and the constant term in augmented form
    printf("\nEnter the elements of augmented matrix row-wise:\n\n");
    // the size of the matrix in increased by one for taking the constant term also
    
    // start of taking inputs
    
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {
            printf("A[%d][%d] : ", i,j);
            scanf("%f",&A[i][j]);
        }
    }
    
    // end of taking input
    
    
    // loop starts for generating upper triangular matrix
    
    
    for(j=1; j<=n; j++) 
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    x[n]=A[n][n+1]/A[n][n];
    
    // end of creating upper triangular matrix
    
    
    // for calculating the value of the variables , the loop begins
    
    
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+A[i][j]*x[j];
        }
        x[i]=(A[i][n+1]-sum)/A[i][i]; // the array X stores the value of the variables
    }
    
    // calculating the value of the variables ends here
    
    // displaying the output begins
    
    
    printf("\nThe solution is: \n");
    for(i=1; i<=n; i++)
    {
        printf("x%d=%f\n",i,x[i]); /* x1, x2, x3 are the required solutions*/
    }
    
    // displaying the output ends
    
    return(0);
}
