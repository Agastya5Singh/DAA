# include <stdio.h>
# include <stdlib.h>
# include <math.h>   
int main(void)
{
	int lrange = 1;
	int hrange = 100;
	int possibleGuesses = hrange + lrange - 1;
	int maxTurns = (int)(log(possibleGuesses)/log(2)) + 1; 
	int yourGuess;
	int playerAnswer;
	int countNumTurns = 1;

	printf("Choose a number from %d to %d.\n", lrange, hrange);
	printf("I will guess your number in %d turns or less.\n\n", maxTurns );

			do{
				possibleGuesses = hrange + lrange - 1;
				yourGuess = (int) ceil(possibleGuesses / 2.0);

				printf("Is your number %d ?\n",yourGuess );
				printf("Press (1) Yes (2) Guess a lower number (3) Guess a higher number\n");
                                scanf("%d", &playerAnswer);

				if(playerAnswer == 3)
					lrange = yourGuess + 1;
				if(playerAnswer == 2) 
					hrange = yourGuess - 1;
				if (playerAnswer == 1)
				    break;
                               
                                 countNumTurns++;
                                
			}while(playerAnswer != 1 && countNumTurns <=maxTurns);

        if(countNumTurns > maxTurns)
    	     printf("You've exceeded the maximum turns. \n");
	else
	     printf("I guessed your number in %d turns !\n", countNumTurns );
}
