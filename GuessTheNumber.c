#include <stdio.h>
#include <stdlib.h>

int main()
{
    int answer;
    int upper_bound = 10;
    int lower_bound = 0;

    srand(time(0));
    int value = rand() % (upper_bound - lower_bound + 1) + lower_bound;

    printf("Welcome to the 'Guess the Number'\n");
    printf("Rules are simple, type a number and see if its the chosen number or not\n");
    printf("Good Luck!\n");
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
        else
        {
            printf("Congratulations, you found the secret number!\n");
        }
    }

    return 0;
}