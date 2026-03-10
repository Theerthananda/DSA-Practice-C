/*
 * @author Theerthananda
 */
#include<stdio.h>
int main(){
	int a[50],n,key,result=-1;
	
	printf("Enter size of an array :");
	scanf("%d",&n);
	
	int low=0,high=n-1;
	
	printf("Enter array elemnts :");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	printf("Enter key to Search :");
	scanf("%d",&key);
	while(low<=high){
		int mid=(low+high)/2;
		
		if(a[mid]==key){
			result=mid;
			high=mid-1;
		}
		
		else if(key<a[mid]){
			high=mid-1;
			
		}
		
		else{
			low=mid+1;
		}
	}
	if(result!=-1){
		printf("First occureance index %d",result);
	}
	else{
		printf("Not found !");
	}
	
	return 0;
}
