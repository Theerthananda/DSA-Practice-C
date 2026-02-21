/*
 * @author Theerthananda
 */
#include<stdio.h>
void MaxAndMinArray(int a[],int n);

int main() {
	int a[50],n;
	
	printf("Enter the size of an array :");
	scanf("%d",&n);
	
	printf("Enter %d elements:",n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		
		MaxAndMinArray(a,n);
}

void MaxAndMinArray(int a[],int n){
	int min=a[0],max=a[0];
	
	for(int i=0;i<n;i++){
		if(a[i]>max){
			max=a[i];
		}
		
		if(a[i]<min){
			min=a[i];
		}
	}
		
	
	printf("MAX and MIN element of an array is %d and %d.",max,min);
}
