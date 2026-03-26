#include<stdio.h>
void Hello(char *msg){  //takes a string as a parameter and prints it to the console.
    printf("%s\n", msg);
}
int Sum(int a,int b){  //receives the values of x and y as parameters and returns the sum of x and y.

    return a+b; //returning the value of a+b which is the sum of a and b.
}

int main(){
    int c;
    int (*p)(int,int); //declaring a function pointer p that can point to a function that takes two int parameters and returns an int. the syntax for declaring a function pointer is: return_type (*pointer_name)(parameter_types);
    
    //if we declare a function pointer without the return type and parameter types, it will be treated as a pointer to a function that takes no parameters and returns void. for example: void (*p)(); this is a pointer to a function that takes no parameters and returns void. and we declare int *p(int,int); this is a pointer to a function that takes two int parameters and returns an int. and we declare void *p(int,int); this is a pointer to a function that takes two int parameters and returns void. and we declare int (*p)(); this is a pointer to a function that takes no parameters and returns an int. and we declare void (*p)(); this is a pointer to a function that takes no parameters and returns void.
    
    p=Sum; //assigning the address of the Sum function to the function pointer p. This is called function pointer assignment. and p=&Sum; is also valid as the name of the function is a pointer to the function.
   
    c=p(5,10); //calling the function using the function pointer p with arguments 5 and 10. and this is equivalent to c=Sum(5,10); as the function pointer p is pointing to the Sum function.also we can use (*p)(5,10); to call the function using the function pointer p. and this is also equivalent to c=Sum(5,10); as the function pointer p is pointing to the Sum function.
    printf("The sum is %d\n",c);

    void (*ptr)(char*); //declaring a function pointer ptr that can point to a function that takes a char* parameter and returns void. the syntax for declaring a function pointer is: return_type (*pointer_name)(parameter_types);
    ptr=Hello; //assigning the address of the Hello function to the function pointer ptr. This is called function pointer assignment. and ptr=&Hello; is also valid as the name of the function is a pointer to the function.
    ptr("Hello, World!"); //calling the function using the function pointer ptr with the argument "Hello, World!". and this is equivalent to Hello("Hello, World!"); as the function pointer ptr is pointing to the Hello function. also we can use (*ptr)("Hello, World!"); to call the function using the function pointer ptr. and this is also equivalent to Hello("Hello, World!"); as the function pointer ptr is pointing to the Hello function.
}