#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int myRandom(int max){
    int x;
    /*create a randome number b/w 1 nd max no.*/
    x = rand() % max + 1;

    return x;
}

int main(){
    int balance, bet, guess, dice;

    srand(getpid());

    balance = 1000;

    while(1){

        printf("Make your bet: ");
        fflush(stdout);
        scanf("%d", &bet);

        /* user process zero*/

        printf("Make your guess (1-6, and 0 means quit):\n");
        scanf("%d", &guess);
        if (guess == 0)
            return 0;
    
        sleep(2);
        dice = myRandom(6);
        printf("%d\n", dice);

        if(guess != dice)
        {
            balance = balance - bet;
            printf("Sorry, You lost\n");
        }
        else
        {
            bet = bet * 3;
            balance += bet;
            printf("You won - Congratulations\n");
        }

        if(balance == 0)
        {
            printf("GAME OVER\n");
            return 0;
        }

        printf("Balance : $%d\n", balance);
        }
    return 0;
    }


