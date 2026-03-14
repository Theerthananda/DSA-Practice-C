/*
 * @author Theerthananda
 */

#include<stdio.h>
void Sum(int r,int c,int a[50][50],int b[50][50],int sum[50][50]){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
				sum[i][j]=a[i][j]+b[i][j];
		}
	}
	
	printf("\nSum of Matrix elements :\n");
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("%d ",sum[i][j]);
		}
		printf("\n");
	}
}


int main(){
	int a[50][50],b[50][50],sum[50][50];
	int r,c;
	
	printf("\nEnter the size of row and column of first matrix:");
	scanf("%d %d",&r,&c);
	
    printf("\nEnter elements of first matrix:\n");
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               scanf("%d",&a[i][j]);
           }
       }

       printf("\nEnter elements of second matrix:\n");
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
           scanf("%d",&b[i][j]);
           }
       }
		Sum(r,c,a,b,sum);
	
	return 0;
}
