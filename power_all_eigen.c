# include <stdio.h>
# include <stdlib.h>
# include <math.h>

double **createMatrix(int row,int col){ // allocates memmory for a matrix of size="row*col" 
	double **Mat=(double **)(malloc(row*sizeof(double *)));
	int i;
	for(i=0;i<row;i++) Mat[i]=(double *)(malloc(col*sizeof(double)));
	return Mat;
}

void freeMatrix(double **Mat,int size){
	int i;
	for(i=0;i<size;i++) free(Mat[i]);
	free(Mat);
}

void printMat(double *X,int size){
	int i;
	for(i=0;i<size;i++) printf("%lf\n",X[i]);
}

double *multiply(double **Mat,double *X,int size){
	double *Mul=(double *)(malloc(size*sizeof(double)));
	int i,j,k;
	for(i=0;i<size;i++){
		Mul[i]=0;
	}
	for(i=0;i<size;i++){
		for(k=0;k<size;k++){
			Mul[i]+=Mat[i][k]*X[k];
		}
	}
	return Mul;
}

void power(double **Mat,int size,double *X,double prevEigen){
	double *Xnew,maxVal=0,newEigen,XXt=0;
	int i,j;
	Xnew=multiply(Mat,X,size);
	for(i=0;i<size;i++){
		if(fabs(Xnew[i])>maxVal){
			maxVal=fabs(Xnew[i]);
			newEigen=Xnew[i];	
		}
	}
	for(i=0;i<size;i++) Xnew[i]=Xnew[i]/maxVal;
	printf("%lf\t%lf\t%lf\n",prevEigen,newEigen,fabs(newEigen-prevEigen));
	if(fabs(newEigen-prevEigen)<0.000005){
		printf("Excecution Complete!\n--------------------------\n");
		printf("One Eigen Value Is : %lf\n",newEigen);
		printf("The corresponding Eigen Vector is as follows :\n");
		printMat(Xnew,size);
		// changing the state of matrix A(Mat) by eliminating newEigen from one of it's eigenValue
		for(i=0;i<size;i++) XXt+=Xnew[i]*Xnew[i];// calculating X*X(transpose);
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				Mat[i][j]=Mat[i][j]-newEigen*Xnew[i]*Xnew[j]/XXt;// A(modified)=A-newEigen*(Xtrainspose*X)/(X*Xtranspose)
			}	
			X[i]=1;// for the next call approximation of eigen vector is all ones
		}
		free(Xnew);
	}
	else{
		power(Mat,size,Xnew,newEigen);
	}
}


int main(){
	int size,row,col;
	double **A,*X;
	printf("Enter the size of matrix: ");
	scanf("%d",&size);
	A=createMatrix(size,size);
	X=(double *)(malloc(size*sizeof(double)));
	printf("Enter the elements of matrix rowwise\n");
	for(row=0;row<size;row++){
		X[row]=1; // intial approximation of eigen vector is all 1s
		for(col=0;col<size;col++) scanf("%lf",&A[row][col]);
	}
	for(row=0;row<size;row++){ // a n*n square matrix has n eigen values, thus n iterations
		printf("prevEigen\tnewEigen\terror\n------------------------------------------\n");
		power(A,size,X,1);// generates largest eigen value for current i
	}
	freeMatrix(A,size);
	return 0;	
}
