#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int answer;          // User's guess
    int upper_bound;     // Upper limit for the random number
    int lower_bound = 0; // Lower limit for the random number
    int attempts;        // Counter for attempts
    int difficulty;      // Difficulty level chosen by the user
    int max_attempts;    // Maximum number of attempts (-1 means unlimited)
    int game_won;        // Flag to check if the player has won
    char play_again;

    do
    {
        // Reset variables for a new game
        attempts = 0;
        game_won = 0;
        max_attempts = -1;

        // Welcome message and game instructions
        printf("\nWelcome to the 'Guess the Number'\n");
        printf("Rules are simple: type a number and see if it's the chosen number or not.\n");
        printf("Good Luck!\n");

        // Validate difficulty level
        do
        {
            printf("Choose the difficulty level:\n");
            printf("1 - Easy (0-10) (Unlimited attempts)\n");
            printf("2 - Medium (0-50) (15 attempts)\n");
            printf("3 - Hard (0-100) (10 attempts)\n");
            if (scanf("%d", &difficulty) != 1) // Check if the input is not an integer
            {
                printf("Invalid input. Please enter a number between 1 and 3.\n");
                while (getchar() != '\n')
                    ;     // Clear invalid input from buffer
                continue; // Restart the loop
            }

            if (difficulty < 1 || difficulty > 3)
            {
                printf("Invalid choice. Please try again.\n");
            }
        } while (difficulty < 1 || difficulty > 3); // Repeat until valid input

        // Configure bounds and maximum attempts based on difficulty level
        if (difficulty == 1)
        {
            upper_bound = 10; // Easy: Numbers between 0 and 10, unlimited attempts
        }
        else if (difficulty == 2)
        {
            max_attempts = 15; // Medium: 15 attempts
            upper_bound = 50;  // Numbers between 0 and 50
        }
        else if (difficulty == 3)
        {
            max_attempts = 10; // Hard: 10 attempts
            upper_bound = 100; // Numbers between 0 and 100
        }

        printf("You have chosen difficulty %d.\n", difficulty);

        if (max_attempts == -1)
        {
            printf("You have unlimited attempts to guess the number.\n");
        }
        else
        {
            printf("You have %d attempts to guess the number.\n", max_attempts);
        }

        // Generate a random number within the chosen range
        srand(time(0));
        int value = rand() % (upper_bound - lower_bound + 1) + lower_bound;

        // Inform the user about the range
        printf("The number is between %d and %d.\n", lower_bound, upper_bound);

        // Main game loop
        while (1) // Infinite loop, controlled by break statements
        {
            printf("Insert your number:\n");
            if (scanf("%d", &answer) != 1) // Validate user input
            {
                printf("Invalid input. Please enter a valid number.\n");
                while (getchar() != '\n')
                    ;     // Clear invalid input from buffer
                continue; // Prompt the user again
            }

            attempts++; // Increment the attempt counter

            // Check if the guess is within the valid range
            if (answer < lower_bound || answer > upper_bound)
            {
                printf("Your guess is out of range! Please enter a number between %d and %d.\n", lower_bound, upper_bound);
                continue;
            }

            // Check if the guess is correct
            if (answer == value)
            {
                game_won = 1; // Mark the game as won
                break;        // Exit the loop
            }

            // Check if the maximum attempts have been reached (for Medium/Hard levels)
            if (max_attempts != -1 && attempts >= max_attempts)
            {
                // Game over message when attempts are exhausted
                printf("Game Over! You've used all %d attempts. The number was %d.\n", max_attempts, value);
                break;
            }

            // Provide hints to the user if the guess is incorrect
            if (answer > value)
            {
                printf("Your number is too big. Try a smaller number.\n");
            }
            else
            {
                printf("Your number is too small. Try a bigger number.\n");
            }
        }

        // If the game was won, print the congratulatory message
        if (game_won)
        {
            printf("Congratulations, you found the secret number in %d attempts!\n", attempts);
        }

        // Ask the user if they want to play again
        while (1)
        {
            printf("Do you want to play again? (y/n): ");
            while (getchar() != '\n')
                ; // Clear buffer
            scanf("%c", &play_again);

            if (play_again == 'y' || play_again == 'Y')
            {
                break; // Restart the game
            }
            else if (play_again == 'n' || play_again == 'N')
            {
                printf("Thanks for playing!\n");
                return 0; // Exit the program
            }
            else
            {
                printf("Invalid input. Please enter 'y' or 'n'.\n");
            }
        }

    } while (1); // Restart the game if the player chooses to play again

    return 0;
}