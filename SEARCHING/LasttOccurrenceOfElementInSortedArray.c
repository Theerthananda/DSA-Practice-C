/*
 * @author Theerthananda
 */
#include<stdio.h>
int main() {
	int low,high,mid,res=-1,key;
	int a[50],n;
	
	printf("Enter size of array an array :");
	scanf("%d",&n);
	low=0;
	high=n-1;
	
	printf("Enter an array elements :\n");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter a Element to check Last Occurance :");
	scanf("%d",&key);
	while(low<=high){
		mid=(low+high)/2;
		
		if(key==a[mid]){
			res=mid;
			low=mid+1;
		}
		
		else if(key<a[mid]){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	
	if(res!=-1){
		printf("Elelemnt last occurance at index %d",res);
	}
	else{
		printf("Not Found !");
	}
	
}
