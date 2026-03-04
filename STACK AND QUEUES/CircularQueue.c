#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = 0;
int rear = -1;
int count = 0;


int isFull() {
    return count == MAX;
}


int isEmpty() {
    return count == 0;
}


void enqueue() {
    int value;

    if (isFull()) {
        printf("Queue is Full\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    rear = (rear + 1) % MAX;
    queue[rear] = value;
    count++;

    printf("Inserted Successfully\n");
}


void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted Element: %d\n", queue[front]);

    front = (front + 1) % MAX;
    count--;
}


void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue Elements: ");
    int i = front;

    for (int j = 0; j < count; j++) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}
