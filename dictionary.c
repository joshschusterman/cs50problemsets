// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h> // this is for the tolower function we used.
#include <string.h> // for strlen?
#include <strings.h> // for strcasecmp
#include <stdio.h> // for FILE function.
#include <cs50.h> // just in case?
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
// So this means the number of "buckets" we're going to have is...
// 'z' times 45, because z has the largets ASCII value, and words can be up
// up to 45 characters long. The + 1 I guess is for extra room?
const unsigned int N = (LENGTH + 1) * 'z';

// Initialize the word count so we can increment as we add words to the table.
int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Get the hash index (which "bucket" the word is in) simply by calling the hash function.
    int index = hash(word);
    // Set up the "cursor" that will traverse through the elements in this bucket (table[index])
    node *cursor = table[index];
    // Loop through until we hit a node that is NULL (signifying end of the bucket).
    while (cursor != NULL)
    {
        // See if the current word in the bucket matches the input word.
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        // Go to the next node (word) in this bucket.
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word) // FYI "unsigned" means no + o -, so basically a positive integer.
{
    int sum = 0;
    // Loop through each character of the input word.
    for (int i = 0; i < strlen(word); i++)
    {
        // We're adding the numeric ASCII value of all the letters in the word.
        // Doing it this way automatically casts each character into its ASCII value, apparently.
        sum += tolower(word[i]);
    }
    return (sum % N); // sum mod N in case the number goes over the number of "buckets" (N).
    // *** I don't really understand how this function organizes the words into the "buckets"
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    // Initialize the "word" array?
    char word[LENGTH + 1];
    // arguments for fscanf = 1. file you're reading from, 2. format of the element (string in this case), 3. ???
    while (fscanf(file, "%s", word) != EOF) // EOF is returned when we've reached the end of the file.
    {
        // create a node at address n, allocate memory the size of a node.
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // arguments for strcpy = 1. the DESTINATION, this case the word "field" (array) IN node n, 2. the source word (element)
        strcpy(n->word, word);
        // set the next pointer, but we don't know what it is yet.
        n->next = NULL;
        // next step is to run the hash function to get the index (in the linked list) where the word will go.
        int wordIndex = hash(word); // * not sure about argument yet. Needs *?
        // if the index of this part of the table's node is NULL, place this new word (via where we copied it to)...
        // in that index spot.
        if(table[wordIndex] == NULL)
        {
            table[wordIndex] = n;
        }
        else
        {
            // *** I UNDERSTAND the visual explanation in the walkthrough, but not how this code does it.
            // Ok, FIRST we make n's pointer (next) point to the first index of this table (???)
            n->next = table[wordIndex];
            // Then make the value of the first index the word we just copied to n (???)
            table[wordIndex] = n;
        }
        word_count++;

    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Need to iterate over every element in the array "table" (our array of linked lists).
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *tmp = head;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
