#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int answer;
    int upper_bound;
    int lower_bound = 0;
    int attempts = 0;
    int difficulty;

    printf("Welcome to the 'Guess the Number'\n");
    printf("Rules are simple, type a number and see if its the chosen number or not\n");
    printf("Good Luck!\n");
    printf("Choose the difficulty level:\n1 - Easy (0-10)\n2 - Medium (0-50)\n3 - Hard (0-100)\n");
    scanf("%d", &difficulty);

    if (difficulty == 1)
    {
        upper_bound = 10;
    }
    else if (difficulty == 2)
    {
        upper_bound = 50;
    }
    else if (difficulty == 3)
    {
        upper_bound = 100;
    }
    else
    {
        printf("Invalid number. Defaulting to Easy Difficulty (0-10)");
        upper_bound = 10;
    }

    srand(time(0));
    int value = rand() % (upper_bound - lower_bound + 1) + lower_bound;

    printf("Insert your number:\n");
    scanf("%d", &answer);

    while (answer != value)
    {
        if (answer > value)
        {
            printf("Your number is too big, try a smaller number\n");
        }
        else if (answer < value)
        {
            printf("Your number is too small, try a bigger number\n");
        }

        printf("Insert your number:\n");
        scanf("%d", &answer);
        attempts++;
    }

    printf("Congratulations, you found the secret number in %d attempts!\n", attempts);

    return 0;
}