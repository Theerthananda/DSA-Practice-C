/*
 * @author Theerthananda
 */
#include<stdio.h>
#include<stdlib.h>

void MergeSortAssending(int a[],int n,int lb,int ub);
void MorgeSortDessending(int a[],int n,int lb,int ub);

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
			  MergeSortAssending(a,n,lb,ub);
			 printf("\nArray elemnts in Assending Order :\n");
			 for(int i=0;i<n;i++){
			 	printf("%d \n",a[i]);
			 }
			 break;
	/*	case 2:
			MorgeSortDessending(a,n,lb,ub);
			printf("\nArray elements in dessending order :\n");
			for(int i=0;i<n;i++){
				printf("%d \n",a[i]);
			}
			break;*/
		case 3:
			exit(0);
			break;
		default:
			printf("\nEnter vallid choice !\n");
			 	
	}
 }
	return 0;
}


void MergeA(int a[],int lb,int mid,int ub){
	int i=lb;
	int j=mid+1;
	int k=lb;
	int b[50];
	
	while(i<=mid&&j<=ub){
		if(a[i]<=a[j]){
			b[k]=a[i];
			i++;
		}
		else{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	
	if(i>mid){
		while(j<=ub){
			b[k]=a[j];
			j++;
			k++;
		}
	}
		else{
			while(i<=mid){
				b[k]=a[i];
				i++;
				k++;
			}
		}
		
		for(k=lb;k<=ub;k++){
			a[k]=b[k];
		}
}

void  MergeSortAssending(int a[],int n,int lb,int ub){
	int mid;
	if(lb<ub){
		mid=(lb+ub)/2;
		 MergeSortAssending(a,n,lb,mid);
		 MergeSortAssending(a,n,mid+1,ub);
		MergeA(a,lb,mid,ub);
	}
}


/*void MergeD(int a[],int lb,int mid,int ub){
	int i=lb;
	int j=mid+1;
	int k=lb;
	int b[50];
	
	while(i<=mid&&j<=ub){
		if(a[i]>=a[j]){
			b[k]=a[i];
			i++;
		}
		else{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	
	if(i>mid){
		while(j<=ub){
			b[k]=a[j];
			j++;
			k++;
		}
	}
		else{
			while(i<=mid){
				b[k]=a[i];
				i++;
				k++;
			}
		}
		
		for(k=lb;k<=ub;k++){
			a[k]=b[k];
		}
}

void MorgeSortDessending(int a[],int n,int lb,int ub){
	int mid;
	if(lb<ub){
		mid=(lb+ub)/2;
		MorgeSortDessending(a,n,lb,mid);
		MorgeSortDessending(a,n,mid+1,ub);
		MergeD(a,lb,mid,ub);
	}
}
*/

