#include<stdio.h>

void fractionalKnapsack(int n, int W, int w[], int p[]) {
    float ratio[n];
    for(int i = 0; i < n; i++) {
        ratio[i] = (float)p[i] / w[i];
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(ratio[j] < ratio[j + 1]) {                                               
                float tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;

                int tempW = w[j];
                w[j] = w[j + 1];
                w[j + 1] = tempW;

                int tempP = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tempP;
            }
        }
    }

    float totalProfit = 0.0;
    for(int i = 0; i < n; i++) {
        if(w[i] <= W) {
            totalProfit += p[i];
            W -= w[i];
        } else {
            totalProfit += ratio[i] * W;
            break;
        }
    }

    printf("Maximum profit in Knapsack = %.2f\n", totalProfit);
}





int main() {
    int n, W;
   
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    int w[n], p[n];
    
    printf("Enter weights and profits of items:\n");
    
    for(int i = 0; i < n; i++) {
        printf("Item %d-> weight: ", i + 1);
        scanf("%d", &w[i]);
        printf("Item %d-> profit: ", i + 1);
        scanf("%d", &p[i]);
    }
    
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

  
    fractionalKnapsack(n, W, w, p);

    return 0;
}