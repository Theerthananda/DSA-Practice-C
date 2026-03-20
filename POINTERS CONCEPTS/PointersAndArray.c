#include<stdio.h>
int main(){
    int a[]={5,2,9,4,3};
    int *p=a;
    //a++; invallid
    p++; //vallid

    //printf("%d\n",p);
    //printf("%d",q);
    //printf("%d",*(a+1));

   for(int i=0;i<5;i++){
    printf("Adress of index %d is %d and value %d\n",i,&a[i],a[i]);
    printf("Adress of index %d is %d and value %d\n",i,a+i,*(a+i));
   }
   printf("\n\n");

   printf("%d\n",a+1);
   printf("%d",&a+1);
}
