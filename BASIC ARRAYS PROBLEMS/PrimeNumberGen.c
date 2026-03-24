#include<stdio.h>
#include<stdlib.h>
void GenPrime(int a[],int n);
//void Prime();
int main(){
    int n;
    int a[n];
    int ch;

    while(1){
        printf("\n1.CHECK NUMBER IS PRIME OR NOT\n2.GENERATE PRIME NUMBER\n\nEnter your choice (1-2 or 3):");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            //Prime();
            break;

            case 2:
             printf("Enter a Range genrate Prime Number : ");
             scanf("%d",&n);
             GenPrime(a,n);
             break;

             case 3:
             return 0;

             default:
             printf("\n!Enter Vallid choice Idiot Uneducated fellow.   Read Menu correctly then choose !\n");

        }
    }

}


void GenPrime(int a[],int n) {

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

    printf("\n");
}

/*void Prime(){
    int n,cnt=0;
    char ch;

    do{
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

   printf("\nDo tou want check Another Number (y/n) :");
    scanf(" %c",&ch);
   }while(ch=='Y'||ch=='y');

    printf("\nProgram Terminated Thank You for using this tool\n");

}*/

