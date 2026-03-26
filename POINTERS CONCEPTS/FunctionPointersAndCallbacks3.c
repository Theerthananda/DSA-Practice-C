#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int Compare(const void *a,const void *b){ //passing the addresses of the integers to the Compare function and comparing the values at those addresses. this function will be used as a callback function to compare two integers and return the result of the comparison. for example, we can use this function to sort an array of integers in ascending order by passing it as a callback function to a sorting algorithm such as bubble sort or quicksort. and this function will return a positive value if the value at address a is greater than the value at address b, a negative value if the value at address a is less than the value at address b, and zero if the value at address a is equal to the value at address b.
    
    int A=*((int*)a); //dereferencing the pointer a to get the value at that address and storing it in a variable A. and we can also use int A=*a; to get the value at the address pointed to by a. and this is equivalent to int A=*((int*)a); as the pointer a is of type int* and we are dereferencing it to get the value at that address.
    int B=*((int*)b); //dereferencing the pointer b to get the value at that address and storing it in a variable B. and we can also use int B=*b; to get the value at the address pointed to by b. and this is equivalent to int B=*((int*)b); as the pointer b is of type int* and we are dereferencing it to get the value at that address.
    return A-B; //returning the result of the comparison. and this will be used to sort the array in ascending order. and if we want to sort the array in descending order, we can change the return value to return B-A; for example: return B-A; this will sort the array in descending order.

}

int main(){
    int arr[]={5,2,9,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    qsort(arr,n,sizeof(int),Compare); //calling the qsort function from the standard library to sort the array. and this will sort the array in ascending order using the quicksort algorithm and the Compare function as a callback function to compare the elements of the array. and we can also pass a different callback function to the qsort function to perform a different comparison. for example: qsort(arr,n,sizeof(int),DescendingCompare); where DescendingCompare is a function that takes two const void* parameters and returns an int. and this function will return a positive value if the value at address a is less than the value at address b, a negative value if the value at address a is greater than the value at address b, and zero if the value at address a is equal to the value at address b. and this will be used to sort the array in descending order.
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}