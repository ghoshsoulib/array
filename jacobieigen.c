# include <stdio.h>
# include <stdlib.h>
# include <math.h>

double **createMatrix(int row,int col){ // allocates memmory for a matrix of size="row*col" 
	double **Mat=(double **)(malloc(row*sizeof(double *)));
	int i;
	for(i=0;i<row;i++) Mat[i]=(double *)(malloc(col*sizeof(double)));
	return Mat;
}

void freeMatrix(double **Mat,int row){
	int i;
	for(i=0;i<row;i++) free(Mat[i]);
	free(Mat);
}

void printMat(double **X,int row,int col){
	int r,c;
	for(r=0;r<row;r++){
		for(c=0;c<col;c++)printf("%.3lf\t",X[r][c]);
		printf("\n");
	}
	printf("\n");
}

double **multiply(double **B,double **C,int size){
	double **A=createMatrix(size,size);
	int i,j,k;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			for(k=0;k<size;k++){
				A[i][j]+=B[i][k]*C[k][j];
			}
		}
	}
	return A;
}

double **symTranspose(double **A,int size){
	double **AT=createMatrix(size,size);
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			AT[i][j]=A[j][i];
		}
	}
	return AT;
}

void maxOffDia(double **A,int size,int *m,int *n){
	double max=A[0][size-1];
	*m=0;
	*n=size-1;
	int i,j;
//	printf("A inside maxOffDia is\n");
//	printMat(A,size,size);
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(A[i][j]>max){
				max=A[i][j];
				*m=i;
				*n=j;
			}
		}
	}
}

double **getOrthoMat(double **A,int size){
	double **P=createMatrix(size,size);
	int m,n,i,j;
//	printf("A inside getOrthoMat is\n");
//	printMat(A,size,size);
	maxOffDia(A,size,&m,&n);
	for(i=0;i<size;i++)P[i][i]=1;
	double theta=atan(2*A[m][n]/(A[m][m]-A[n][n]))/2;
	P[m][m]=cos(theta);
	P[n][n]=P[m][m];
	P[n][m]=sin(theta);
	P[m][n]=-1*P[n][m];
	return P;
}

int checkOffDia(double **A,int size){
	int i,j;
//	printf("A inside checkOffDia is\n");
//	printMat(A,size,size);
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(A[i][j]>0.1) return 0;
		}
	}
	return 1;
}

void jacobiEigen(double **A,int size,double **V){
	double **P,**PT;
	P=getOrthoMat(A,size);
	printf("Matrix P is:\n");
	printMat(P,size,size);
	PT=symTranspose(P,size);
	A=multiply(PT,A,size);
	A=multiply(A,P,size);
	V=multiply(V,P,size);
	printf("Matrix A is\n");
	printMat(A,size,size);
	freeMatrix(P,size);
	freeMatrix(PT,size);
}


int main(){
	double **A,**V;
	int size,i,j;
	printf("Enter size of aquare matrix:");
	scanf("%d",&size);
	A=createMatrix(size,size);
	V=createMatrix(size,size);
	printf("Enter the elements of the matrix row wise\n");
	for(i=0;i<size;i++){
		V[i][i]=1;
		for(j=0;j<size;j++) scanf("%lf",&A[i][j]);
	}
	jacobiEigen(A,size,V);
	freeMatrix(A,size);
	freeMatrix(V,size);
	return 0;
}