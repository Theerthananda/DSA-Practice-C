#include<stdio.h>
int main(){
    int a;
    int *p;
    p=&a;
    a=10;
    printf("adress p is  %d\n",p);
   /* p is 2002
   p+1 is 2004 bcz size of an integer is 4
   so 2002+4 is 2006*/
    printf("size of int is %d bytes \n",sizeof(int));
    printf("adress p+1 is %d\n",p+1); 
    printf("Value of adress P is %d\n",*p);
    printf("Value of adress P+1 is %d\n",*(p+1));  /*If it’s not an array → don’t use p+1
    Pointer arithmetic is safe ONLY with arrays  "real memory behavior"
    Access memory only where you own data (array or allocated memory)*/

}