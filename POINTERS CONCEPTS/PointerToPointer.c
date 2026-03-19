//pointers to pointers
#include<stdio.h>
int main(){
    int a=6;
    int *p;
    p=&a;
    *p=5;
    int **q;
    q=&p;
    int ***r;
    r=&q;

    printf("%d\n",*p);
    printf("%d\n",*q);
    printf("%d\n",**q);
    printf("%d\n",*r);
    printf("%d\n",**r);
    printf("%d\n",***r);

   
}