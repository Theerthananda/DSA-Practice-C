#include<stdio.h>

int checkUnique(int a[], int n);

int main() {
    int a[50], n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int res = checkUnique(a, n);

    if(res == 1)
        printf("All elements are UNIQUE");
    else
        printf("Array has DUPLICATE elements");

    return 0;
}

int checkUnique(int a[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                return 0;  // duplicate found
            }
        }
    }
    return 1;  // all unique
}
