#include<stdio.h>
int main(){
    int a;
    int *p;

    a=10;
    p=&a;

    printf("%d\n",a);
    printf("%p\n",p);
    printf("%p\n",&a);
    *p=23;
    printf("%d",*p);


}