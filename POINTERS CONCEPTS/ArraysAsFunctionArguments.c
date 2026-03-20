//Arrays As Function Arguments
#include<stdio.h>
int Sum(int a[],int n){  //int a[] and int *a both are same 
    int sum=0;
   // int size=sizeof(a)/sizeof(a[0]);  its wrong it doesnot work calculate size of array inside the function
    //printf("SOE size of a is %d , and size of a[0] %d\n",sizeof(a),sizeof(a[0]));
    for(int i=0;i<n;i++){
        sum+=a[i];  //a[i] as *(a+i)
    }

    return sum;
}


int main(){
    int a[]={1,2,3,4,5};
    int size=sizeof(a)/sizeof(a[0]);  
    printf("Sum of array elemnts is %d\n",Sum(&a[0],size)); // a and &a[0] both are same 
    //printf("Main size of a is %d , and size of a[0] %d\n",sizeof(a),sizeof(a[0]));
    printf("%d\n",&a+1);
    printf("%d\n",a+1);
    printf("%d\n",&a[1]);
    

}