
/*
 * @author Theerthananda
 */
 
#include<stdio.h>
int fib(int n){
	if(n==1){
		return 1;
	}
	
	if(n==0){
		return 0;
	}

	return fib(n-1)+fib(n-2);
	
}

int main(){
	int n;
	printf("Enter number of terms :");
	scanf("%d",&n);
	
	printf("Fibbonacci series :");
	for(int i=0;i<n;i++){
		printf("%d ",fib(i));
	}
}
