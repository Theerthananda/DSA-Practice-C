/*
 * @author Theerthananda
 */
#include<stdio.h>
int FirstOccurance(int a[],int n,int key);
int LastOccurance(int a[],int n,int key);

int main(){
	int a[50],n;
	int first,last,key;
	
	printf("Enter size of an array :");
	scanf("%d",&n);
	
	printf("Enter array elemnts :");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	printf("Enter key to Search :");
	scanf("%d",&key);
	
	first=FirstOccurance(a,n,key);
	last=LastOccurance(a,n,key);
	
	if(first==-1){
		printf("Count = 0");
	}
	
	else{
		printf("Count = %d",last-first+1);
	}
}

int FirstOccurance(int a[],int n,int key){
	int low=0,high=n-1;
	int result=-1;

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
	
	return result;
}


int LastOccurance(int a[],int n,int key){
	int res=-1,low,high=n-1,mid;
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
	return res;
}
