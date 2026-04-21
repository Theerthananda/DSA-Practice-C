/*
 * @author Theerthananda
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int V;

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX;
    int min_index = -1;

    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}


void printMST(int parent[], int graph[MAX][MAX]) {
    int totalCost = 0;

    printf("\nEdge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }

    printf("Total Cost of MST = %d\n", totalCost);
}


void primMST(int graph[MAX][MAX]) {
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

   
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }

    key[0] = 0; // Start from vertex 0

   
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);

        if (u == -1) {
            printf("Graph is not connected!\n");
            return;
        }

        mstSet[u] = true;

        for (int j = 0; j < V; j++) {
            if (graph[u][j] != 0 && !mstSet[j] && graph[u][j] < key[j]) {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }

    printMST(parent, graph);
}


int main() {
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("Edge %d - %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph);

    return 0;
}
