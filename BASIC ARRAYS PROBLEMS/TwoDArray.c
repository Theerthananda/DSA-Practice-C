/*
 * @author Theerthananda
 */
#include<stdio.h>
void main(){
	int a[50][50],r,c;
	
	printf("Enter size of row and column :");
	scanf("%d %d",&r,&c);
	
	printf("Enter 2D array elemnts :");
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
		printf("2D array elemnts :\n");
	    for(int i=0;i<r;i++){
		     for(int j=0;j<c;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
