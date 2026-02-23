/*
 * @author Theerthananda
 */
#include<stdio.h>
#include<stdlib.h>

void BubbleSortAseending(int a[],int n);
void BubbleSortDessending(int a[],int n);

int main() {
	int a[50],n;
	int ch;
	
	printf("Enter size of an array :");
	scanf("%d",&n);
	
	printf("Enter array elemnts :");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
while(1){
	printf("\nOPTIONS\n1.ASSENDING ORDER\n2.DESSENDING ORDER\n3.EXIT\nEnter your choice (1 or 2 or 3):");
	scanf("%d",&ch);
	
	switch(ch){
		case 1:
			 BubbleSortAseending(a,n);
			 printf("\nArray elemnts in Assending Order :\n");
			 for(int i=0;i<n;i++){
			 	printf("%d \n",a[i]);
			 }
			 break;
		case 2:
			BubbleSortDessending(a,n);
			printf("\nArray elements in dessending order :\n");
			for(int i=0;i<n;i++){
				printf("%d \n",a[i]);
			}
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("\nEnter vallid choice !\n");
			 	
	}
}
	return 0;
}

void BubbleSortAseending(int a[],int n){
		for(int i=0;i<n-1;i++){
		   for(int j=0;j<n-1-i;j++){
			 
			 if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void BubbleSortDessending(int a[],int n){
		for(int i=0;i<n-1;i++){
		   for(int j=0;j<n-1-i;j++){
			 
			 if(a[j]<a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
