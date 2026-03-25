#include<stdio.h>
int main(){
    int a[3][2][2]={
        {{1,2},{3,4}},
        {{5,6},{7,8}},
        {{9,10},{11,12}}
    };

    int (*p)[2][2]=a;

   // printf("%d \n",*p);
    printf("%d \n",a[2][0][1]);
}