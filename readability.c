#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("Text: ");
    // Count letters
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    printf("%i letter(s)\n", letters);
    //

    // Couting words
    int words = 1; // Start at 1 because spaces are in between words.
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    printf("%i word(s)\n", words);
    //

    // Counting sentences
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    printf("%i sentence(s)\n", sentences);
    //

    // Getting L and S
    float l = 100 * (float)letters / (float)words;
    float s = 100 * (float)sentences / (float)words;

    // Plugging in Coleman-Liau formula
    float grade = 0.0588 * l - 0.296 * s - 15.8;

    if (grade < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    if (grade >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    printf("Grade %.f\n", grade); // %.f prints it without the decimal
}