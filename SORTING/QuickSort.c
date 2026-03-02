/*
 * @author Theerthananda
 */
#include<stdio.h>
#include<stdlib.h>

void QuickSortA(int a[],int n,int lb,int ub);
int PartitionA(int a[],int n,int lb,int ub);

void QuickSortD(int a[],int n,int lb,int ub);
int PartitionD(int a[],int n,int lb,int ub);


int main() {
	int a[50],n;
	int ch;
	
	
	printf("Enter size of an array :");
	scanf("%d",&n);
	int lb=0,ub=n-1;
	
	printf("Enter array elemnts :");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
while(1){
	printf("\nOPTIONS\n1.ASSENDING ORDER\n2.DESSENDING ORDER\n3.EXIT\nEnter your choice (1 or 2 or 3):");
	scanf("%d",&ch);
	
	switch(ch){
		case 1:
			  QuickSortA(a,n,lb,ub);
			 printf("\nArray elemnts in Assending Order :\n");
			 for(int i=0;i<n;i++){
			 	printf("%d \n",a[i]);
			 }
			 break;
		case 2:
			QuickSortD(a,n,lb,ub);
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

//ASCENDING ORDER

void QuickSortA(int a[],int n,int lb,int ub) {
	int loc;
	if(lb<ub){
		loc=PartitionA(a,n,lb,ub);
		QuickSortA(a,n,lb,loc-1);
		QuickSortA(a,n,loc+1,ub);
	}
}


int PartitionA(int a[],int n,int lb,int ub){
	int pivot=a[lb];
	int start=lb;
	int end=ub;
	int temp;
	
	while(start<end){
		while(a[start]<=pivot){
			start++;
		}
		
		while(a[end]>pivot){
			end--;
		}
		
		if(start<end){
			temp=a[start];
			a[start]=a[end];
			a[end]=temp;
		}
	}
	
	temp=a[lb];
	a[lb]=a[end];
	a[end]=temp;
	
	return end;
}

//DESCENDING ORDER

void QuickSortD(int a[],int n,int lb,int ub) {
	int loc;
	if(lb<ub){
		loc=PartitionD(a,n,lb,ub);
		QuickSortD(a,n,lb,loc-1);
		QuickSortD(a,n,loc+1,ub);
	}
}


int PartitionD(int a[],int n,int lb,int ub){
	int pivot=a[lb];
	int start=lb;
	int end=ub;
	int temp;
	
	while(start<end){
		while(a[start]>=pivot){
			start++;
		}
		
		while(a[end]<pivot){
			end--;
		}
		
		if(start<end){
			temp=a[start];
			a[start]=a[end];
			a[end]=temp;
		}
	}
	
	temp=a[lb];
	a[lb]=a[end];
	a[end]=temp;
	
	return end;
}
