/*
 * @author Theerthananda
 */
#include<stdio.h>
void ArrayReverse(int a[],int n);

int main() {
	int a[50],n;
	
	printf("Enter the size of the array :");
	scanf("%d",&n);
	
	printf("Enter an array elements :\n");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Array elements :");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	ArrayReverse(a,n);
	
	return 0;
}

void ArrayReverse(int a[],int n){
	for(int i=0;i<n/2;i++){
		int temp=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=temp;
	}
	
	printf("\nReversed array :");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
