/*
 * @author Theerthananda
 */
#include<stdio.h>
#include<stdlib.h>
#define N 5
int q[N];
int front=-1,rear=-1;

void Enque(int x){
	if(rear==N-1){
		printf("\nQueue is full !\n");
		return;
	}
	else if(rear==-1&&front==-1){
		rear=front=0;
		q[rear]=x;
		printf("\nINSERTED\n");
	}
	else{
		rear++;
		q[rear]=x;
		printf("\nINSERTED\n");
	}
}

void Deque(){
	if(front==-1&&rear==-1){
		printf("\nQueue is Empty !\n");
	}
	else if(rear==front){
		rear=front=-1;
		printf("\nDELETED\n");
	}
	else {
		front++;
		printf("\nDELETED\n");
	}
}

void display(){
	if(front==-1&&rear==-1){
	     printf("\nQueue is Empty !\n");
	}
	else{
		for(int i=front;i<=rear;i++){
			printf("\n %d\n",q[i]);
		}
	}
}

int main(){
	int ch;
	int x;
	
	/*while(1){
		printf("\nMENU\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\nENTER YOUR CHOICE (1-4) :");
		scanf("%d",&ch);
		*/
		switch(ch){
			case 1:
				printf("\nEnter value to insert :");
				scanf("%d",&x);
				Enque(x);
				break;
				
				case 2:
					Deque();
					break;
					
					case 3:
						display();
						break;
						
						case 4:
						exit(0);
						break;
						
						default:
						printf("\nEnter vallid choice !\n");		
		}
	//}
	return 0;
}
