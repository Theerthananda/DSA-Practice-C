/*#include<stdio.h>
void Increament(int a){
   a=a+1;
   printf("adress of a in function  %d\n",&a);
}

int main(){
    int a=10;
    Increament(a);
    
   printf("Value of a is %d\n",a);
   printf("adress ofa in main function %d\n",&a);
}
    
//output 10 adress of both a is diffrent 
*/

#include<stdio.h>
void Increament(int *p){
   *p=*p+1;
   printf("adress of a in function  %d\n",p);
}

int main(){
    int a=10;
    Increament(&a);
    
    printf("Value of a is %d\n",a);
    printf("adress of a in main function a %d\n",&a);
    // output : 11; 
}