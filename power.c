#include<stdio.h>
#include<math.h>
void main()
{
 
    int i,j,n;
    
    float A[40][40],x[40],z[40],e[40],zmax,emax;
    // A is the input matrix
    // X is the coloumn matrix
    
    
    printf("\nEnter the order of matrix:");
    scanf("%d",&n);
    
    
    printf("\nEnter matrix elements row-wise\n");
    
    // taking the input
    
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("A[%d][%d]=", i,j);
            scanf("%f",&A[i][j]);
        }
    }
    
    
    
    
    // asking for the coloumn vector for starting calculation
    
    printf("\nEnter the column vector\n");
    for(i=1; i<=n; i++)
    {
        printf("X[%d]=",i);
        scanf("%f",&x[i]);
    }
    
    
    
    // the main process begins
    
    
    do
    {    
    
    
    // first of all the matrix is multiplied with the coloumn matrix
        for(i=1; i<=n; i++)
        {
            z[i]=0;
            for(j=1; j<=n; j++)
            {
                z[i]=z[i]+A[i][j]*x[j];
            }
        }
        
     // the process of multiplication ends here
     
     
     // finding the largest value of the coloumn matrix we got after multiplication
     
     
        zmax=fabs(z[1]);
        for(i=2; i<=n; i++)
        {
            if((fabs(z[i]))>zmax)
                zmax=fabs(z[i]);
        }
        
        
     // we got the largest element in the coloumn matrix after multiplication
     
     
     // we divide all the elements of the coloumn matrix by the largest element
        for(i=1; i<=n; i++)
        {
            z[i]=z[i]/zmax;
        }
        
      // division process ends
      
      // now we take the difference of every element with the given coloumn matrix 
      
      
        for(i=1; i<=n; i++)
        {
            e[i]=0;
            e[i]=fabs((fabs(z[i]))-(fabs(x[i])));
        }
        
       // taking of the difference ends
       
       
       // we find the largest difference
       
        emax=e[1];
        for(i=2; i<=n; i++)
        {
            if(e[i]>emax)
                emax=e[i];
        }
        
        // we got the largest difference
        
        
        // we replace the new coloumn matrix with the previous coloumn matrix
        
        
        for(i=1; i<=n; i++)
        {
            x[i]=z[i];
        }
        
        // process of replacing ends
        
        printf("the eigen value is : %f\n\n",zmax);
        
        
    }
    
    
    // we set an approximation
    
    
    while(emax>0.001); 
    
    
    // main process ends here
    
    
    
    
    // printing the eigrn value
    printf("\n The fina eigen value is %f",zmax);
    
    
    
    // printing the eigen vector
    printf("\n\nThe final eigen vector is as follows :\n");
    
    
    for(i=1; i<=n; i++)
    {
        printf("%f\n",z[i]);
    }
    
    
    
    printf("\n");
    
    
}
