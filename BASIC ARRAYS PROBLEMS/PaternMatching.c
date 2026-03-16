#include<stdio.h>
#include<string.h>
int main(){
    char text[100];
    char pattern[50];


    printf("Enter Text :");
    gets(text);

    printf("Enter pattern :");
    gets(pattern);

    int n=strlen(text);
    int m=strlen(pattern);

  
    /* for(int i=0;i<=n-m;i++){
        j=0;
        while (j<m && text[i+j]==pattern[j])
        {
            j++;
        }                                                          //METHOD 1
        
        if(j==m){
            printf("Match found from  index %d to index %d",i,i+m-1);
            return 0;
        }
    }*/
   
    for(int i=0;i<=n-m;i++){
        int flag=0;
        for(int j=0;j<m;j++){                                      //METHOD 2
            if(text[i+j]==pattern[j]){
                flag++;
            }
        }
        if(flag==m){
                printf("matched from %d to %d",i,i+m-1);
                return 0;
            }
    }
printf("Not found ");
return 0;
}