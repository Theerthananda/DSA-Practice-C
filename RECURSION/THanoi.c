/*
 * @author Theerthananda
 */
#include<stdio.h>
int mov=0;
int Hanoi(int n,char source,char via,char destination){
	
	if(n==1){
		printf("Move disk 1 from %c to %c\n",source,destination);
		mov++;
		return 0;
	}
		Hanoi(n-1,source,destination,via);
		printf("Move disk %d from %c to %c\n",n,source,destination);
		mov++;
		Hanoi(n-1,via,source,destination);
}

int main(){
	char A,B,C;
	int n;
	
	printf("Enter number of disk :");
	scanf("%d",&n);
	Hanoi(n,'A','B','C');
	printf("\nTotal moves %d\n",mov);
	
	return 0;
}
