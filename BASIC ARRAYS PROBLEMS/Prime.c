#include<stdio.h>
int main(){
    int n,cnt=0;
    char ch;

    //do{
        printf("\nEnter a Number :");
        scanf("%d",&n);

        for(int i=1;i<=n;i++){
            if(n%i==0){
                cnt++;
            }
        }
        
        if(cnt==2){
            printf("\n%d is Prime !",n);
        }
        else{
            printf("\n%d is not prime !",n);
        }

   // printf("\nDo tou want check Another Number (y/n) :");
    //scanf(" %c",&ch);
   // }while(ch=='Y'||ch=='y');

    printf("\nProgram Terminated Thank You for using this tool");

    return 0;
}
