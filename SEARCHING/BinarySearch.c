#include<stdio.h>
int BinarySearch(int a[],int n);

int main() {
    int a[50],n;
    char choice;

    printf("Enter the Size of an array: ");
    scanf("%d",&n);

    printf("Enetr %d sorted Array :",n);

    for(int i=0;i<n;i++) {
      scanf("%d",&a[i]);
    }
     
   do{
    int res= BinarySearch(a,n);

     if(res==-1){
        printf("Element Not found !");

     }

     printf("\nDo you want to search another element? (y/n): ");
     scanf(" %c",&choice);
   }while(choice=='y'||choice=='Y');
   
    
    return 0;
}

int BinarySearch(int a[],int n) {
    int low=0,high=n-1,mid,data;
    int assending;

     printf("Enter the element to search:");
     scanf("%d",&data);
if(a[0]<a[n-1]) {
	assending=1;
}
else{
	assending=0;
}
    while(low<=high){
        mid=(low+high)/2;

        if(a[mid]==data) {
            printf("%d is found at index %d",data,mid);
            return 0;
        }

        if(assending) {
        	if(data<a[mid]) {
        		high=mid-1;
			}
			else{
				low=mid+1;
			}
		}
		else {
			if(data>a[mid]){
				high=mid-1;
			}
			else{
				low=mid+1;
			}
		}

    }

    return -1;
}
