/*
 * @author Theerthananda
 */
#include<stdio.h>
#include<stdlib.h>
void InsetionSortAssending(int a[],int n);
void InsertionSortDessending(int a[],int n);

int main(){
	int a[50],n,ch;
	
	printf("Enter size of an array :");
	scanf("%d",&n);
	
	printf("Enter the array elemnts :");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	while(1){
	printf("\nOPTIONS\n1.ASSENDING ORDER\n2.DESSENDING ORDER\n3.EXIT\nEnter your choice (1 or 2 or 3):");
	scanf("%d",&ch);
	
	switch(ch){
		case 1:
			 InsetionSortAssending(a,n);
			 printf("\nArray elemnts in Assending Order :\n");
			 for(int i=0;i<n;i++){
			 	printf("%d \n",a[i]);
			 }
			 break;
		case 2:
			InsertionSortDessending(a,n);
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

void InsetionSortAssending(int a[],int n){
	int temp,j;
	for(int i=1;i<n;i++){
		temp=a[i];
		j=i-1;
		
		while(j>=0&&a[j]>temp){
			a[j+1]=a[j];
			j--;
		}
		
		a[j+1]=temp;
	}
}

void InsertionSortDessending(int a[],int n){
	int temp,j;
	for(int i=1;i<n;i++){
		temp=a[i];
		j=i-1;
		
		while(j>=0&&a[j]<temp){
			a[j+1]=a[j];
			j--;
		}
		
		a[j+1]=temp;
	}
}
