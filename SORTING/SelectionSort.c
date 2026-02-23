/*
 * @author Theerthananda
 */
#include<stdio.h>
#include<stdlib.h>
void SelectionSortAssending(int a[],int n);
void SelectionSortDessending(int a[],int n);

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
			 SelectionSortAssending(a,n);
			 printf("\nArray elemnts in Assending Order :\n");
			 for(int i=0;i<n;i++){
			 	printf("%d \n",a[i]);
			 }
			 break;
		case 2:
			SelectionSortDessending(a,n);
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

void SelectionSortAssending(int a[],int n){
	for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		if(min!=i){
			int temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
}

void SelectionSortDessending(int a[],int n){
	for(int i=0;i<n-1;i++){
		int max=i;
		for(int j=i+1;j<n;j++){
			if(a[j]>a[max]){
				max=j;
			}
		}
		if(max!=i){
			int temp=a[i];
			a[i]=a[max];
			a[max]=temp;
		}
	}
}
