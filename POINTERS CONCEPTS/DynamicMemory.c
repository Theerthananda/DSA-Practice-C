#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    int *a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        a[i]=i;
    }
    // free(a);
     //a[2]=10; //after free we can not access the memory but here we are trying to access the memory which is already freed so it will give us garbage value its depnds on the compiler and system how it will handle this situation but in general it is not recommended to access the memory after free because it may lead to undefined behavior. 

     //int *b=(int*)realloc(a,2*n*sizeof(int)); //realloc is used to resize the memory block which is already allocated by malloc or calloc. it takes two arguments first is the pointer to the memory block which we want to resize and second is the new size of the memory block in bytes. it returns a pointer to the newly allocated memory block which is resized to the new size. if the new size is greater than the old size then the new memory block will be initialized with garbage values. if the new size is less than the old size then the excess memory will be freed and the remaining memory will be resized to the new size. if realloc fails to allocate the new memory block then it returns NULL and the original memory block remains unchanged.
      
     int *b=(int*)realloc(a,0); //if we pass 0 as the new size then it will free the memory block and return NULL. so we can not access the memory block after this because it is already freed.==> free(a);

   printf("prvious block address: %p and new block address: %p\n",a,b);
   printf("Elements of array: ");
    for(int i=0;i<2*n;i++){
        printf("%d ",b[i]);
    }
   
    return 0;

}