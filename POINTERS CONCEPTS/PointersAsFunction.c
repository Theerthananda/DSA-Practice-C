#include<stdio.h>
#include<stdlib.h>
int* Sum(int *a,int *b){  //receives the addresses of x and y as parameters and returns the address of c which is the sum of x and y.
    printf("Adress of a and b in Sum function is %p and %p\n",a,b);
    int *c=(int*)malloc(sizeof(int)); //dynamic memory allocation to allocate memory for c on the heap.
    *c=*a + *b; //dereferencing the pointers to get the values of x and y and adding them to get the sum.

    //return &c;  //returning the address of c which is a local variable in the Sum function. This is not a good practice as the memory allocated for c will be deallocated once the function exits and we will be left with a dangling pointer. To avoid this we can use dynamic memory allocation to allocate memory for c on the heap and return the pointer to that memory location.
    return c;
}


int main(){
    int x=10;
    int y=10;
    printf("Adress of x and y in main function is %p and %p\n",&x,&y);
    int *c=Sum(&x,&y); //call by reference reduses the memory usage as we are not creating new variables in the function but using the same memory location of x and y by passing their addresses.
    printf("Sum of x and y is %d\n",*c);
    free(c); //freeing the dynamically allocated memory for c to avoid memory leaks.

    printf("Sum of x and y is %d\n",*c); //This will lead to undefined behavior as we are trying to access memory that has been deallocated. This is a common mistake when using dynamic memory allocation and it is important to always free the memory after we are done using it to avoid memory leaks and undefined behavior.

    return 0;
}