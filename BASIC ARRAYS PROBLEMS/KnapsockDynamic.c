#include <stdio.h>

#define MAX 100


int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int n, int W, int w[], int p[]) {
    int V[MAX][MAX];

   
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= W; j++) {
            if(i == 0 || j == 0)
                V[i][j] = 0;
            else if(w[i-1] > j)
                V[i][j] = V[i-1][j];
            else
                V[i][j] = max(V[i-1][j], p[i-1] + V[i-1][j - w[i-1]]);
        }
    }


    printf("\nDP Table:\n");
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= W; j++) {
            printf("%3d ", V[i][j]);
        }
        printf("\n");
    }

    
    printf("\nMaximum Profit = %d\n", V[n][W]);


    printf("\nSelected Items:\n");

    int i = n, j = W;

    while(i > 0 && j > 0) {
        if(V[i][j] == V[i-1][j]) {
                                   // not selected
            i--;
        } else {
                                         // selected
            printf("Item %d (Weight=%d, Profit=%d)\n", i, w[i-1], p[i-1]);
            j = j - w[i-1];
            i--;
        }
    }
}


int main() {
    int n = 4;
    int w[] = {3,2,4,5};
    int p[] = {50,40,70,80};
    int W = 6;

    knapsack(n, W, w, p);

    return 0;
}

