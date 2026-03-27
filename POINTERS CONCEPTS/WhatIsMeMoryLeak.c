// This program is a simple card game where the player has to guess the position of the queen among three cards. The player starts with a certain amount of cash and can bet on each round of the game. If the player guesses correctly, they win a certain amount of cash, and if they guess incorrectly, they lose the amount they bet. The game continues until the player runs out of cash.
#include <stdio.h>
#include <stdlib.h>
#include<time.h> //including the time.h header file to use the time function for seeding the random number generator. and this will allow us to shuffle the cards in a different way each time we play the game, making it more interesting and unpredictable for the player. and this is important for a card game, as it adds an element of chance and excitement to the gameplay. and we can also use srand(1); to seed the random number generator with a fixed value, but this will result in the same sequence of random numbers each time we run the program, which may not be desirable for a card game.

int cash=100; //initial cash for the player to start with. and this variable will be used to keep track of the player's cash throughout the game. and the player can bet a certain amount of cash on each round of the game, and if they win, they will receive a certain amount of cash as a reward, and if they lose, they will lose the amount of cash they bet. and this variable will be updated after each round of the game to reflect the player's current cash balance.

void playGame(){
    char c[]={'j','q','k'};
    printf("Shuffling the cards...\n");
    srand(time(0)); //seeding the random number generator with the current time to ensure that we get different random numbers each time we run the program. and this will help us to shuffle the cards in a different way each time we play the game. and this is important to make the game more interesting and unpredictable for the player. and we can also use srand(1); to seed the random number generator with a fixed value, but this will result in the same sequence of random numbers each time we run the program, which may not be desirable for a card game.

    for(int i=0;i<5;i++){
        int x=rand();
        int y=rand();
        char temp=c[x%3]; //%3 is used to get a random index between 0 and 2, which corresponds to the three cards in the array. and this will allow us to shuffle the cards by swapping the elements at the random indices x%3 and y%3. and this will help us to create a random order of the cards for each round of the game, making it more challenging for the player to guess the position of the queen.
        c[x%3]=c[y%3];
        c[y%3]=temp;
    }
int playersGuess;
printf("Whats position of the queen? (1, 2, or 3): ");
scanf("%d",&playersGuess);
if(c[playersGuess-1]=='q'){
    printf("Congratulations! You win! result =\%c %c %c\n", c[0], c[1], c[2]);
    cash+=10;
    
}
else{
    printf("Sorry, you lose.\n");
    cash-=10;
    printf("The cards were: %c %c %c\n",c[0],c[1],c[2]);
}
}

int main(){
  int bet;
  printf("Welcome to the card game! You have $%d to start with.\n", cash);
  while(cash>0){
    printf("Enter your bet: ");
    scanf("%d",&bet);
    if(bet>cash||bet<=0){
      printf("You cannot bet more than you have. Try again.\n");
      continue;
    }
    playGame();
    printf("\n****************************************************\n");
    if(cash<=0){
      printf("You have no more cash left. Game over!\n");
      break;
    }
  }
  return 0;
}

// In this program, we have a simple card game where the player has to guess the position of the queen among three cards. The player starts with a certain amount of cash and can bet on each round of the game. If the player guesses correctly, they win a certain amount of cash, and if they guess incorrectly, they lose the amount they bet. The game continues until the player runs out of cash. We use the time function to seed the random number generator to ensure that we get different random numbers each time we run the program, making the game more interesting and unpredictable for the player.