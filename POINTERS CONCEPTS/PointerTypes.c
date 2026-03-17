#include<stdio.h>
int main(){
    int a;
    int *p=&a;
    a=200;
    printf("Adress of p: %d and value of p : %d\n",p,*p);
    printf("Adress of p+1: %d and value of p : %d\n",p+1,*(p+1));
   unsigned char *p0;
    p0=(unsigned char*)p; //typecasting

    printf("Adress %d and value %d \n",p0,*p0);
    printf("Adress %d and value %d \n",p0+1,*(p0+1));

    void *p1;   //void pointer
    p1=p;

    printf("Adress : %d  ",p1+1);

}