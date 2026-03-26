#include<stdio.h>
#include<stdlib.h>
int Absolute_Campare(int a,int b){ //takes two integers as parameters and returns an integer. this function will be used as a callback function to compare the absolute values of two integers and return the result of the comparison. for example, we can use this function to sort an array of integers in ascending order by passing it as a callback function to a sorting algorithm such as bubble sort or quicksort. and this function will return a positive value if the absolute value of a is greater than the absolute value of b, a negative value if the absolute value of a is less than the absolute value of b, and zero if the absolute value of a is equal to the absolute value of b.
    if(abs(a)>abs(b)){
        return 1; //returning a positive value if the absolute value of a is greater than the absolute value of b.
    }
    else return -1; //returning a negative value if the absolute value of a is less than the absolute value of b. and this will be used to sort the array in ascending order. and if we want to sort the array in descending order, we can change the return values to return -1 if the absolute value of a is greater than the absolute value of b and return 1 if the absolute value of a is less than the absolute value of b. for example: if(abs(a)>abs(b)){ return -1; } else return 1; this will sort the array in descending order.
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
    int arr[]={5,-2,9,-4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,n,Absolute_Campare); //calling the BubbleSort function with the array, its size, and the Absolute_Compare function as arguments. and this will sort the array in ascending order using the bubble sort algorithm and the Absolute_Compare function as a callback function to compare the absolute values of the elements of the array. and we can also pass a different callback function to the BubbleSort function to perform a different comparison. for example: BubbleSort(arr,n,DescendingAbsoluteCompare); where DescendingAbsoluteCompare is a function that takes two integers as parameters and returns an integer. and this function will return a positive value if the absolute value of a is less than the absolute value of b, a negative value if the absolute value of a is greater than the absolute value of b, and zero if the absolute value of a is equal to the absolute value of b. and this will be used to sort the array in descending order.

    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}