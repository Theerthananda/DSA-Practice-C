/*#include<stdio.h>
void BubbleSort(int *arr, int n){ //takes an array of integers, the size of the array, and a function pointer as parameters. the function pointer is used to call the callback function after each pass of the bubble sort algorithm.
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){ //comparing the current element with the next element and swapping them if the current element is greater than the next element. this will sort the array in ascending order. and if we want to sort the array in descending order, we can change the comparison operator to <. for example: if(arr[j]<arr[j+1]){ this will sort the array in descending order.
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int arr[]={5,2,9,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,n); //calling the BubbleSort function with the array and its size as arguments. and this will sort the array in ascending order using the bubble sort algorithm. and we can also pass a callback function as an argument to the BubbleSort function to perform some action after each pass of the bubble sort algorithm. for example: BubbleSort(arr,n,callback); where callback is a function that takes no parameters and returns void. and this callback function will be called after each pass of the bubble sort algorithm.

    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

*/

//we can also use function pointers to implement a callback function in C programming. a callback function is a function that is passed as an argument to another function and is called by that function when a certain event occurs. for example, we can use a callback function to handle an event such as a button click in a graphical user interface (GUI) application. we can define a callback function that will be called when the button is clicked and we can pass that function as an argument to the button click event handler. this allows us to separate the event handling logic from the main application logic and makes our code more modular and easier to maintain.

#include<stdio.h>
int Compare(int a,int b){ //takes two integers as parameters and returns an integer. this function will be used as a callback function to compare two integers and return the result of the comparison. for example, we can use this function to sort an array of integers in ascending order by passing it as a callback function to a sorting algorithm such as bubble sort or quicksort. and this function will return a positive value if a is greater than b, a negative value if a is less than b, and zero if a is equal to b.
    if(a>b){
        return 1; //returning a positive value if a is greater than b.
    }
    else return -1; //returning a negative value if a is less than b. and this will be used to sort the array in ascending order. and if we want to sort the array in descending order, we can change the return values to return -1 if a is greater than b and return 1 if a is less than b. for example: if(a>b){ return -1; } else return 1; this will sort the array in descending order.
}


void BubbleSort(int *arr, int n, int (*compare)(int,int)){ //takes an array of integers, the size of the array, and a function pointer as parameters. the function pointer is used to call the callback function after each pass of the bubble sort algorithm.
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(compare(arr[j],arr[j+1])>0){ //comparing the current element with the next element using the callback function and swapping them if the current element is greater than the next element. this will sort the array in ascending order. and if we want to sort the array in descending order, we can change the comparison operator to <. for example: if(compare(arr[j],arr[j+1])<0){ this will sort the array in descending order.
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int arr[]={5,2,9,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,n,Compare); //calling the BubbleSort function with the array, its size, and the Compare function as arguments. and this will sort the array in ascending order using the bubble sort algorithm and the Compare function as a callback function to compare the elements of the array. and we can also pass a different callback function to the BubbleSort function to perform a different comparison. for example: BubbleSort(arr,n,DescendingCompare); where DescendingCompare is a function that takes two integers as parameters and returns an integer. and this function will return a positive value if a is less than b, a negative value if a is greater than b, and zero if a is equal to b. and this will be used to sort the array in descending order.

    return 0;
}


