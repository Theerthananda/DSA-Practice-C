/*
 * @author Theerthananda
 */

#include<stdio.h>
void Multiply(int r1,int c1,int r2,int c2,int a[50][50],int b[50][50],int mul[50][50]){
	for(int i=0;i<r1;i++){
		for(int j=0;j<c2;j++){
			 mul[i][j]=0;
			for(int k=0;k<c1;k++){
				mul[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	
	printf("Multiplied Matrix elements :\n");
	for(int i=0;i<r1;i++){
		for(int j=0;j<c2;j++){
			printf("%d ",mul[i][j]);
		}
		printf("\n");
	}
}


int main(){
	int a[50][50],b[50][50],mul[50][50];
	int r1,c1,r2,c2;
	
	printf("Enter the size of row and column of first matrix:");
	scanf("%d %d",&r1,&c1);
	
	printf("\nEnter the size of row and column of second matrix:");
	scanf("%d %d",&r2,&c2);
	
	
	
	if(c1!=r2){
		printf("Column of first matrix must be equal to row of second matrix !\n");
		return 0;
	}
	else{
		printf("Enter elements of first matrix:\n");
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
               scanf("%d",&a[i][j]);
           }
       }

       printf("Enter elements of second matrix:\n");
       for(int i=0;i<r2;i++){
           for(int j=0;j<c2;j++){
           scanf("%d",&b[i][j]);
           }
       }
		Multiply(r1,c1,r2,c2,a,b,mul);
	}
	
	return 0;
}
