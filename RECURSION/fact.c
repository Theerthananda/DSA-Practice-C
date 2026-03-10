/*
 * @author Theerthananda
 */

#include<stdio.h>
int fact(int n){
	if(n==1||n==0){
		return 1;
	}
	
	return n*fact(n-1);
	
}

int main(){
	int n;
	printf("Enter number :");
	scanf("%d",&n);
	
	printf("Factorial of : %d is ",n);
	printf("%d ",fact(n));

}
