#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int answer;          // User's guess
    int upper_bound;     // Upper limit for the random number
    int lower_bound = 0; // Lower limit for the random number
    int attempts;        // Counter for the number of attempts
    int difficulty;      // Difficulty level chosen by the user
    int max_attempts;    // Maximum number of attempts (-1 means unlimited)
    int game_won;        // Flag to indicate if the player has won the game
    char play_again;     // Stores whether the user wants to play again

    srand(time(0)); // Seed the random number generator (done once, outside the loop)

    do
    {
        // Reset game variables for a new round
        attempts = 0;
        game_won = 0;
        max_attempts = -1;

        // Display welcome message and instructions
        printf("\nWelcome to the 'Guess the Number'\n");
        printf("Rules are simple: type a number and see if it's the chosen number or not.\n");
        printf("Good Luck!\n");

        // Ask the player to choose a difficulty level, with input validation
        do
        {
            printf("Choose the difficulty level:\n");
            printf("1 - Easy (0-10) (Unlimited attempts)\n");
            printf("2 - Medium (0-50) (15 attempts)\n");
            printf("3 - Hard (0-100) (10 attempts)\n");

            // Check if the input is valid (an integer)
            if (scanf("%d", &difficulty) != 1)
            {
                printf("Invalid input. Please enter a number between 1 and 3.\n");
                while (getchar() != '\n') // Clear invalid input from the buffer
                    ;
                continue; // Restart the loop
            }

            if (difficulty < 1 || difficulty > 3)
            {
                printf("Invalid choice. Please try again.\n");
            }
        } while (difficulty < 1 || difficulty > 3); // Repeat until a valid difficulty is chosen

        // Configure game settings based on the chosen difficulty
        if (difficulty == 1)
        {
            upper_bound = 10; // Easy: numbers between 0 and 10, unlimited attempts
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

        // Inform the user about their chosen difficulty and the number of attempts
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
        int value = rand() % (upper_bound - lower_bound + 1) + lower_bound;

        // Inform the player about the range of the random number
        printf("The number is between %d and %d.\n", lower_bound, upper_bound);

        // Main game loop
        while (1)
        {
            printf("Insert your number:\n");

            // Validate the user's input
            if (scanf("%d", &answer) != 1)
            {
                printf("Invalid input. Please enter a valid number.\n");
                while (getchar() != '\n') // Clear invalid input from the buffer
                    ;
                continue; // Prompt the user again
            }

            attempts++; // Increment the number of attempts

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
                break;        // Exit the game loop
            }

            // Check if the player has exceeded the maximum number of attempts
            if (max_attempts != -1 && attempts >= max_attempts)
            {
                // Inform the player of the game over
                printf("Game Over! You've used all %d attempts. The number was %d.\n", max_attempts, value);
                break;
            }

            // Provide a hint if the guess is incorrect
            if (answer > value)
            {
                printf("Your number is too big. Try a smaller number.\n");
            }
            else
            {
                printf("Your number is too small. Try a bigger number.\n");
            }
        }

        // Display a message if the player wins
        if (game_won)
        {
            printf("Congratulations, you found the secret number in %d attempts!\n", attempts);
        }

        // Ask the player if they want to play again
        while (1)
        {
            printf("Do you want to play again? (y/n): ");
            while (getchar() != '\n') // Clear buffer
                ;
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

    } while (1); // Restart the game if the player wants to play again

    return 0; // Exit the program
}