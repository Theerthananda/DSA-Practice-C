//pointers to pointers
#include<stdio.h>
int main(){
    int a=6;
    int *p;
    p=&a;
    *p=5;
    int **q;
    q=&p;
    printf("%p\n",p);
    printf("adress of p is %d\n", &p);
    printf("adress of p stored in q is %d\n",**q);
}