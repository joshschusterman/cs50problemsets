#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// #define is just a "macro" way to define a constant value that can be used anywhere in the code.
#define BLOCKSIZE 512
#define FILE_NAME_SIZE 8

typedef uint8_t BYTE; // don't really understand this data type, not sure we need this line anyway

int main(int argc, char *argv[])
{
    // This is just in case the user doesn't enter a value argument on the command line
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // This will be an array where we story what we read in card.raw
    BYTE buffer[BLOCKSIZE];

    // Initialize a filename, the size of FILE_NAME_SIZE
    char filename[FILE_NAME_SIZE];

    // Initalize this boolean to use when determining whether we're (still) inside of a JPG or not
    bool insideJPG = false;

    // Initialize the counter for the filename - * Start at -1 so when we increment the first time, it'll be 0
    int count = -1;

    // Initialize the output file
    FILE *output = NULL;

    // Initialize the input file (open whatever filename the user typed in the command line)
    FILE *pic = fopen(argv[1], "r");

    // Making sure it's a valid file (not empty or corrupt)
    if (pic == NULL)
    {
        printf("Not a valid file: %s\n", argv[1]);
        return 1;
    }

    // Start the program, as long as fread is still returning values
    while (fread(buffer, sizeof(BYTE), BLOCKSIZE, pic))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Since we're inside of a jpb (above IF statement is true), set insideJPG to true
            insideJPG = true;

            // If there is anything in the output file, it's from an earlier JPG, so we need to close it
            if (output != NULL)
            {
                fclose(output);
            }

            // Increment the counter so file names will count up (000.jpg, 001, jpg, etc)
            count++;

            // Sends the output from buffer to our filename. *"%03i" just means print an integer filename with 3 digits
            sprintf(filename, "%03i.jpg", count);

            // Open the (newest) filename (e.g. 001.jpg), set to append mode. Not really sure about this part.
            output = fopen(filename, "a");

            // Write to the output file. Also not sure about the exact process that happens here.
            fwrite(buffer, sizeof(BYTE), BLOCKSIZE, output);
        }

        else
        {
            if (insideJPG)
            {
                fwrite(buffer, sizeof(BYTE), BLOCKSIZE, output);
            }
        }
    }

    // Close everything
    fclose(pic);

    fclose(output);

    return 0;
}


/* Arguments for fread are:
    1. name of file being read INTO (buffer)
    2. size of buffer's data type (BYTE)
    3. block size (512),
    4. and the opened file (f))
*/

/*

So while I do understand most of this code, I don't understand what is actually happening (beyond the
abstraction) of certain parts of it. In particular I don't know what's happening in...
1. The condition of the while loop. I do understand what the arguments are, but not really what the while is "whil-ing"
2. the sprintf - I don't know how it's printing the contents of the output file to filename, because "output" isn't
mentioned anywhere in that line of code or to the call of sprintf.
3. How the last 3 lines of the while loop (before the else) really work together to get the contents gathered
FROM pic, into buffer, and into the output file.
4. Not really sure why we need the pointer ("*") when initalizing input and output.

*/