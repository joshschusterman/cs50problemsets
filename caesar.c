#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool is_valid_key(string s); // prototype for the function at bottom

int main(int argc, string argv[])
{
    if (argc == 2 && is_valid_key(argv[1]))
        // checks that there was only 1 argument
        // AND runs is_valid_key function on the argument (argv[1])
    {
        printf("Success\n"); // confirms that command line and argument (key) are valid.
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k = atoi(argv[1]); // converts the key to an integer and prints it.
    printf("The key is %i\n", k);
    string p = get_string("Type the message you want to encrypt: ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(p); i++) // iterate over each character in p
    {
        if (p[i] >= 'a' && p[i] <= 'z')
        {
            printf("%c", ((p[i] - 'a') + k) % 26 + 'a'); // formula for staying in the lowercase alphas
        }
        else if (p[i] >= 'A' && p[i] <= 'Z')
        {
            printf("%c", ((p[i] - 'A') + k) % 26 + 'A'); // formula for staying in the uppercase alphas
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");

    //printf("Encoded message: %s\n", encoded); // need to make a function
    return 0;
}

// FUNCTION TO CHECK IF ARGUMENT IS A VALID KEY (INTEGERS ONLY)
bool is_valid_key(string s) // this function returns a boolean value
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i])) // iterates through each character of the string (argument - argv[1]) to see if it's NOT a digit.
        {
            return false;
        }
    }
    return true;
}