/*
 * @author Theerthananda
 */
#include<stdio.h>
void SecondLargestElementInArray(int a[],int n);

int main() {
	int a[50],n;
	
	printf("Enter the size of an array :");
	scanf("%d",&n);
	
	printf("Enter %d elements:",n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		SecondLargestElementInArray(a,n);
		
		return 0;
}

void SecondLargestElementInArray(int a[],int n){
	int m1,m2;
	
	if(a[0]>a[1]){
		m1=a[0];
		m2=a[1];
	}
	else{
		m1=a[1];
		m2=a[0];
	}
	
	for(int i=2;i<n;i++){
		if(a[i]>m1){
			m2=m1;
			m1=a[i];
		}
		else if(a[i]>m2){
			m2=a[i];
		}
	}
	
	printf("Second Largest Number in array is %d",m2);
}

