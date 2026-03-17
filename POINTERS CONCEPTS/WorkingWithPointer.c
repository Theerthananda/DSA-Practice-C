#include<stdio.h>
int main(){
    int a;
    int *p;
    p=&a;
    a=10;
    printf("%d\n",p);
    printf("%d\n",*p);
    printf("%d\n",&a);
    *p=12; //Dereferencing
    printf("%d\n",a);
    int b=20;
    *p=b;
    p=&b;
    printf("%d\n",p);
    printf("%d\n",*p); 


}