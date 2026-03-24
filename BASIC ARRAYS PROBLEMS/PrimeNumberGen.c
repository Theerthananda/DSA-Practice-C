#include<stdio.h>
int main(){
    int n;

    printf("Enter a Range genrate Prime Number : ");
    scanf("%d",&n);

    int a[n];
    //int size=sizeof(a)/sizeof(a[0]);
    

    for(int i=2;i<=n+1;i++){
        a[i]=i;
    }

    for(int i=2;i<=n;i++){
        if(a[i]!=0){
            for(int j=i+1;j<=n;j++){
                if(a[j]%a[i]==0){
                    a[j]=0;
                }
            }
        }
    }

    for(int i=2;i<n+1;i++){
        if(a[i]!=0){
            printf("%d ",a[i]);

        }
    }
}