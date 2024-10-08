#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random number between 1 and 100
    int random = (rand() % 100) + 1;

    int n;  // Variable to store the user's choice for limited or unlimited tries
    int c = 0;  // Counter for the number of attempts (used for unlimited tries)
    int co = 1;  // Counter for the number of attempts (used for limited tries)

    // Display the menu for choosing between limited and unlimited tries
    printf("Enter 1 if you want limited tries \n");
    printf("Enter 2 if you want unlimited tries \n");
    scanf("%d", &n);

    // If the user chooses limited tries
    if (n == 1) {
        int no;  // Variable to store the user's guess

        // Loop until the user guesses the number or runs out of attempts
        do {
            printf("\nGuess the number: ");
            scanf("%d", &no);

            // Check if the guess is too high
            if (co <= 10) {
                if (no > random) {
                    printf("Lower number please");
                    printf("\n%d chances remaining", 10 - co);
                }
                // Check if the guess is too low
                else if (no < random) {
                    printf("Higher number please");
                    printf("\n%d chances remaining", 10 - co);
                }
                // The guess is correct
                else {
                    printf("Congrats! \n");
                    printf("You guessed the number in %d guesses", co);
                }
                co++;  // Increment the attempt counter

                // If the user has used all 10 attempts, end the game
                if (co > 10) {
                    printf("\nAll your chances are used up!");
                    printf("\nThe correct guess is %d", random);
                    break;
                }
            }
        } while (no != random);
    }
    // If the user chooses unlimited tries
    else if (n == 2) {
        int no;  // Variable to store the user's guess

        // Loop until the user guesses the number
        do {
            printf("\nGuess the number \n");
            scanf("%d", &no);

            // Check if the guess is too high
            if (no > random) {
                printf("Lower number please");
            }
            // Check if the guess is too low
            else if (no < random) {
                printf("Higher number please");
            }
            // The guess is correct
            else {
                printf("Congrats! \n");
            }
            c++;  // Increment the attempt counter
        } while (no != random);

        // Display the number of attempts taken to guess the number
        printf("You guessed the number in %d guesses", c);
    }
    // If the user enters an invalid choice
    else {
        printf("Wrong input, please re-enter the choice");
    }

    return 0;
}
