#include<stdio.h>
#include<math.h>

#define maximum 10
#define minvalue 0.0005

int main()
{
 float augmentedmatrix[maximum][2*maximum] ;  
 int n,m;                               
 float temporary, r ;
 int i, j, k, dimension, temp;                                 

 printf("\n Enter the dimension of the matrix to be provided as input : \n");
 scanf("%d",&dimension);

 
 // scanning starts
 
 printf("\n Enter a non-singular %dx%d matrix : \n",dimension,dimension);
 for(i=0; i<dimension; i++)
  for(j=0; j<dimension; j++)
            scanf("%f",&augmentedmatrix[i][j]) ;

// scanning ends 
  

 // making a identity matrix

 for(i=0;i<dimension; i++)
  for(j=dimension; j<2*dimension; j++)
      if(i==j%dimension)
         augmentedmatrix[i][j]=1;
      else
         augmentedmatrix[i][j]=0;

      
    // making identity matrix ends  
      
      
  // printing matrix starts
 
  for(n=0; n<dimension; n++)
 {
  for(m=0; m<2*dimension; m++)
            printf("    %4.2f",augmentedmatrix[n][m]) ;
  printf("\n");
 }
 
 printf("\n\n\n");
        
 // printing matrix ends
 
 
 // the process begins
 for(j=0; j<dimension; j++)
 {
  temp=j;

 /* finding maximum jth column element in last (dimension-j) rows */

  for(i=j+1; i<dimension; i++)
if(augmentedmatrix[i][j]>augmentedmatrix[temp][j])
                        temp=i;

  if(fabs(augmentedmatrix[temp][j])<minvalue)
             {
                printf("\n Elements are too small to deal with !!!");
                return 0;
             }

 /* swapping row which has maximum jth column element */

  if(temp!=j)
            for(k=0; k<2*dimension; k++)
            {
            temporary=augmentedmatrix[j][k] ;
            augmentedmatrix[j][k]=augmentedmatrix[temp][k] ;
            augmentedmatrix[temp][k]=temporary ;
            }

/* performing row operations to form required identity matrix out of the input matrix */

  for(i=0; i<dimension; i++)
            if(i!=j)
            {
            r=augmentedmatrix[i][j];
            for(k=0; k<2*dimension; k++)
              augmentedmatrix[i][k]-=(augmentedmatrix[j][k]/augmentedmatrix[j][j])*r ;
            }
            else
            {
            r=augmentedmatrix[i][j];
            for(k=0; k<2*dimension; k++)
              augmentedmatrix[i][k]/=r ;
            }
            
            
            
            for(n=0; n<dimension; n++)
 {
  for(m=0; m<2*dimension; m++)
            printf("     %4.2f",augmentedmatrix[n][m]) ;
  printf("\n");
 }
 
 printf("\n\n\n");
            
 }
 
 // the process end here
 
 
 // Display the inverse
 
 
 printf("\n\n\n The inverse of the entered non-singular matrix is : \n\n");

 for(i=0; i<dimension; i++)
 {
  for(j=dimension; j<2*dimension; j++){
            printf("     %.5f",augmentedmatrix[i][j]);
  }
            printf("\n");
 
 }
 
 return 0;
 }
 
 
