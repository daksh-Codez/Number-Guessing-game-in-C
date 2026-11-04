//this Code is Written BY Daksh Goswami ( A CS Major Student From galgotias University )

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int choice;
    int maxNumber;
    int attempts;
    int secretNumber;
    int guess;
    int attemptsUsed = 0;
    int score = 0;
    char playAgain;
    int totalGames = 0;
    int gamesWon = 0;
    int gamesLost = 0;
    int totalScore = 0;
    
    srand(time(0));

        do{
            attemptsUsed = 0;
            score = 0;
            totalGames++ ;

            printf("\n");
            printf("=================================\n");
            printf("      NUMBER GUESSING GAME       \n");
            printf("=================================\n");

            printf("\n     Welcome to the game!\n");
            printf("Guess the secret number to win.\n");

                printf("\nSelect Difficulty:\n");
                printf("1. Easy\n");
                printf("2. Medium\n");
                printf("3. Hard\n");

                printf("\nEnter your choice: ");
                scanf("%d", &choice);
                
                switch (choice){
                    case 1:
                        maxNumber = 50;
                        attempts = 10;
                        break;

                    case 2:
                        maxNumber = 100;
                        attempts = 7;
                        break;

                    case 3:
                        maxNumber = 200;
                        attempts = 5;
                        break;

                    default:
                        printf("Invalid choice! Please restart the game.\n");
                            continue;
                }

                    printf("\nMaximum Number: %d\n", maxNumber);
                    printf("Your Attempts: %d\n", attempts);
                    
                    secretNumber = (rand() % maxNumber) + 1;

                    while (attemptsUsed < attempts){
                        printf("\nEnter your guess: ");
                            scanf("%d", &guess);
                                attemptsUsed++;

                        if (guess > secretNumber){
                            printf("Too High! Try a smaller number.\n");
                        }
                        else if (guess < secretNumber){
                            printf("Too Low! Try a bigger number.\n");
                        }
                        else {
                            printf("Congratulations! You guessed it!\n");
                            
                            score = (attempts - attemptsUsed + 1) * 100;
                                printf("Your Score: %d\n", score);
                                    totalScore += score;
                                        gamesWon++;
                            break;
                        }
                    }
                    if (guess != secretNumber){
                        printf("\nGame Over! You ran out of attempts.\n");
                        printf("The secret number was %d.\n", secretNumber);
                            
                        gamesLost++; 
                    }
        

            printf("\nDo you want to play again? (y/n): ");
                scanf(" %c", &playAgain);
            } while (playAgain == 'y' || playAgain == 'Y');
    
        printf("\n=================================\n");
        printf("         FINAL STATISTICS        \n");
        printf("=================================\n");

        printf("Total Games Played: %d\n", totalGames);
        printf("Games Won: %d\n", gamesWon);
        printf("Games Lost: %d\n", gamesLost);
        printf("Total Score: %d\n", totalScore);

        printf("\nThanks for playing!\n\n");
        
    return 0;
}