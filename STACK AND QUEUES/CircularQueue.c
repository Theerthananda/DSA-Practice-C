#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Insert element
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is Full\n");
        return;
    }

    if (front == -1)  // first element
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("Inserted: %d\n", value);
}

// Delete element
void dequeue() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear) {   // only one element
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display queue
void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;

    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    display();

    enqueue(60);
    display();

    return 0;
}