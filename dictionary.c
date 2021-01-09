// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table - *** Setting to 26 for now, one for each alphabet letter.
const unsigned int N = (LENGTH + 1) * 'z';

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
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
    while (fscanf(file, "%s", word) != EOF) // EOF is returned when we've reached the end of the file.
    {
        // create a node at address n, allocate memory the size of a node.
        node *n = malloc(sizeof(node));
        // arguments for fscanf = 1. file you're reading from, 2. format of the element (string in this case), 3. ???
        fscanf(file, "%s", word);
        // arguments for strcpy = 1. the DESTINATION, this case the word "field" (array) IN node n, 2. the source word (element)
        strcpy(n->word, word);
        // set the next pointer, but we don't know what it is yet.
        n->next = NULL;
        // next step is to run the hash function to get the index (in the linked list) where the word will go.
        wordIndex = hash(word); // * not sure about argument yet. Needs *?
        // if the index of this part of the table's node is NULL, place this new word (via where we copied it to)...
        // in that index spot.
        if(table[wordIndex] == NULL)
        {
            table[wordIndex] = n;
        }
        else
        {
            // *** I UNDERSTAND the visual explanation in the walkthrough, but how this code does it.
            // Ok, FIRST we make n's pointer (next) point to the first index of this table (???)
            n->next = table[wordIndex];
            // Then make the value of the first index the word we just copied to n (???)
            table[wordIndex] = n;
        }
    }
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
