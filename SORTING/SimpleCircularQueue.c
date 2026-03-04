/*
 * @author Theerthananda
 */

#include<stdio.h>
#include<stdlib.h>
#define N 5

int q[N];
int front=-1,rear=-1;

void Enqueue(){
	int x;
	if((rear+1)%N==front){
		printf("Queue is full !\n");
		return;
	}
	
	printf("\nEnter value to insert :");
	scanf("%d",&x);
	
	if(front==-1&&rear==-1){
		front=rear=0;
		q[rear]=x;
	}
	
	else{
		rear=(rear+1)%N;
		q[rear]=x;
	}
	
}

void Dequeue(){
	if(front==-1&&rear==-1){
		printf("Empty Queue !\n");
		return;
	}
	
	if(front==rear){
		printf("Deleted element: %d\n", q[front]);
		front=rear=-1;
		
	}
	
	else{
		printf("Deleted element: %d\n", q[front]);
		front=(front+1)%N;
	}
}

void Display(){
	if(front==-1&&rear==-1){
		printf("Empty Queue !\n");
		return;
	}
	
	printf("Queue Elemnts :\n");
	
	int i=front;
	while(1){
		printf("%d \n",q[i]);
		if(i==rear)
		break;
		i=(i+1)%N;
	}
}

int main(){
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
            case 1: Enqueue(); break;
            case 2: Dequeue(); break;
            case 3: Display(); break;
            case 4: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}

