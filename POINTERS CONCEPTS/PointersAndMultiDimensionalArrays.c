#include<stdio.h>
int main(){
    int b[][3]={
    {1,2,3},
    {4,5,6},
    {7,8,9}
};

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",b[i][j]);
        }

        printf("\n");
        
    }

    int (*p)[3]=b;
    /*printf("%d\n",p);
    printf("%d\n",*(*(b+2)+2));
    printf("%d",sizeof(b));*/

    printf("%d \n",*b);
    printf("%d\n",b[0]);
    printf("%d\n",&b[0][0]);


    printf("%d\n",*(*(b+0))+0);
    printf("%d \n",*(b[2]+0));




}
