#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height; // Declare the variable first
    do
    {
        height = get_int("Type a positive integer between 1 and 8: ");
    }
    while (height < 1 || height > 8); // Re-prompts if number entered is less than 1 OR more than 8

    for (int i = 0; i < height; i++) // for loop for ROWS
    {
        for (int k = 1; k < height - i; k++) // print spaces to right-align
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) // for loop for NUMBER OF HASHES in the row
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j <= i; j++) // for loop for NUMBER OF HASHES in the row
        {
            printf("#");
        }
        printf("\n");
    }
}