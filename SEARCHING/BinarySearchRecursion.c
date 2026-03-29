/*
 * @author Theerthananda
 */
#include<stdio.h>
int BinarySearchRecursion(int a[],int n,int low,int high,int data,int assending);
int main() {
    int a[50],n;
    char choice;
    int low=0,high;
	int assending,data;

    printf("Enter the Size of an array: ");
    scanf("%d",&n);
    high=n-1;
    
	printf("Enetr %d sorted Array :",n);

    for(int i=0;i<n;i++) {
      scanf("%d",&a[i]);
    }
    
    	if(a[0]<a[n-1]){
		assending=1;
	}
	else{
		assending=0;
	}
	
     
   do{
   	printf("Enter element to serach :");
    scanf("%d",&data);
    int res= BinarySearchRecursion(a,n,low,high,data,assending);

     if(res==-1){
        printf("Element Not found !");

     }
     else{
     	printf("%d is found at index %d",data,res);
	 }

     printf("\nDo you want to search another element? (y/n): ");
     scanf(" %c",&choice);
   }while(choice=='y'||choice=='Y');
   
    
    return 0;
}

int BinarySearchRecursion(int a[],int n,int low,int high,int data,int assending){
int mid;
	

	if(low>high){
    	return -1;
	}
	
	
	
	mid=(low+high)/2;
	if(data==a[mid]){
		return mid;
	}
	
	if(assending){
		if(data<a[mid]){
			return BinarySearchRecursion(a,n,low,mid-1,data,assending);
		}
		else{
			return BinarySearchRecursion(a,n,mid+1,high,data,assending);
		}
	}
	else{
		if(data>a[mid]){
			return BinarySearchRecursion(a,n,low,mid-1,data,assending);
		}
		else {
			return BinarySearchRecursion(a,n,mid+1,high,data,assending);
		}
	}
	

}
