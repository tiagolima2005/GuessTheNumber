#include <stdio.h>
#include <stdlib.h>

int main()
{
    int answer;
    int upper_bound = 10;
    int lower_bound = 0;
    int value = rand() % (upper_bound - lower_bound + 1) + lower_bound;

    printf("Welcome to the 'Guess the Number'\n");
    printf("Rules are simple, type a number and see if its the chosen number or not\n");
    printf("Good Luck!\n");
    printf("Insert your number:\n");
    scanf("%d", answer);

    return 0;
}