#include<stdio.h>
void A(){
    printf("Hello from function A\n");
}

void B(void (*ptr)()){ //takes a function pointer as a parameter and calls the function pointed to by the function pointer.
    printf("Hello from function B\n");
    ptr(); //calling the function pointed to by the function pointer
}

int main(){
    void (*ptr)(); //declaring a function pointer ptr that can point to a function that takes no parameters and returns void. the syntax for declaring a function pointer is: return_type (*pointer_name)(parameter_types);
    
    ptr=A; //assigning the address of the A function to the function pointer ptr. This is called function pointer assignment. and ptr=&A; is also valid as the name of the function is a pointer to the function.
    
    B(ptr); //calling the function B with the function pointer ptr as an argument. and this is equivalent to B(A); as the function pointer ptr is pointing to the A function. here A is the callback function that will be called by the function B when it is called. and this is a common use case of function pointers and callbacks in C programming. we can also use a function pointer variable to store the address of the callback function and pass that variable as an argument to the function that will call the callback function. for example: void (*callback)() = A; B(callback); this is also valid as the function pointer variable callback is pointing to the A function.

    // or we can directly pass the function A as an argument to the function B without using a function pointer variable. for example: B(A); this is also valid as the name of the function is a pointer to the function.

    //use case is of fucntion pointers and callbacks is when we want to implement a callback function. A callback function is a function that is passed as an argument to another function and is called by that function when a certain event occurs. For example, we can use a callback function to handle an event such as a button click in a graphical user interface (GUI) application. We can define a callback function that will be called when the button is clicked and we can pass that function as an argument to the button click event handler. This allows us to separate the event handling logic from the main application logic and makes our code more modular and easier to maintain.

    
    return 0;
}