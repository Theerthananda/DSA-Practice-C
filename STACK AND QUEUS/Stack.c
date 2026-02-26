/*
 * @author Theerthananda
 */
 #include<stdio.h>
 #include<stdlib.h>
 #define N 5
 int s[N];
 int top=-1;
 
 void push(int x){
 	if(top==N-1){
 		printf("Stack is full !");
	 }
	 else if(top==-1){
	 	top++;
	 	s[top]=x;
	 	printf("INSERTED\n");
	 }else{
	 	top++;
	 	s[top]=x;
	 	printf("INSERTED\n");
	 }
	 
 }
 
 void pop(){
 	if(top==-1){
 		printf("Stack is empty !\n");
	 }
	 else{
	 	printf("DELETED\n");
	 	top--;
	 }
 }
 
 void display(){
 	if(top==-1){
 	printf("Stack is empty !");
	}
	
	else {
		for(int i=top;i>=0;i--){
			printf("\n%d ",s[i]);
		}
	}
 }
 int main(){
 	int ch;
 	int x;
 	
 	while(1){
 		printf("\nOPTIONS\n1.PUSH\n2.POP\n3.DSIPLAY\n4.EXIT\nEnter Your choice :");
 		scanf("%d",&ch);
 		
 		switch(ch){
 			case 1:
 			printf("\nEnter value to insert :");
			scanf("%d",&x);
			push(x);
			break;
			
			case 2:
			pop();
			break;
			
			case 3:
				display();
				break;
				
			case 4:
			exit(0);
			
			
			default:
			printf("Enter vallid choice !");	
		 }
	 }
	 return 0;
 }
 
