#include<stdio.h>

void MaxAndMinArray(int a[], int n);

int main() {
    int a[50], n;

    printf("Enter the size of an array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    MaxAndMinArray(a, n);

    return 0;
}

void MaxAndMinArray(int a[], int n) {
    int min = a[0], max = a[0];

    for(int i = 1; i < n; i++) {
        if(a[i] > max) {
            max = a[i];
        }

        if(a[i] < min) {
            min = a[i];
        }
    }

    printf("Max element = %d\n", max);
    printf("Min element = %d\n", min);
}
