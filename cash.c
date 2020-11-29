#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    do
    {
        change = get_float("How much change? ");
    }
    while (change <= 0);
    change = round(change * 100);
    int coins = 0;
    while (change >= 25)
    {
        coins++;
        change = change - 25;
    }
    while (change >= 10)
    {
        coins++;
        change = change - 10;
    }
    while (change >= 5)
    {
        coins++;
        change = change - 5;
    }
    while (change >= 1)
    {
        coins++;
        change = change - 1;
    }
    printf("Number of coins required: %i\n", coins);
}