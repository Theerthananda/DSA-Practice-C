#include<stdio.h>

int RecursiveLinearSearch(int a[], int n, int data, int index);

int main() {
    int a[50], n;
    char choice;

    printf("Enter size of an array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    do{
        int data,result;

        printf("Enter the element to search: ");
        scanf("%d", &data);

         result=RecursiveLinearSearch(a,n,data,0);

         if(result!=-1) {
            printf("Element found at index %d",result);
         }

         else {
            printf("Not found !");
         }

        printf("\nDo you want to search another element? (y/n): ");
        scanf(" %c", &choice);
    }while(choice=='y'||choice=='Y');

}

int RecursiveLinearSearch(int a[],int n,int data,int index) {
    if(index==n) {
        return -1;
    }

    if(a[index]==data) {
        return index;
    }

    return RecursiveLinearSearch(a,n,data,index+1);
}