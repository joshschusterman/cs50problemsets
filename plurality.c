#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct // Establishing the data type "candidate"
{
    string name;
    int votes;
}
candidate;

// Creating the array of candidates and setting number of elements to MAX
candidate candidates[MAX];

// Number of candidates
int candidate_count; // I think this initializes "candidate_count" at the global level?

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++) // Iterate over candidate names and compare to name entered in "Vote: "
    {
        if (strcmp(name, candidates[i].name) ==
            0) // Using strcmp from string.h. First arg is inputed name, second is iterated candidate name
        {
            candidates[i].votes++; // If the user entered name == the current candidate in the iteration, add 1 to their .votes count
            return true; // This is just to make sure it doesn't trigger the "Invalid vote"
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int highestVotes = 0; // Initializing the high vote number
    for (int i = 0; i < candidate_count; i++) // Iterate over the candidates
    {
        if (highestVotes < candidates[i].votes) // If the number of votes a candidate has is higher than the high count...
        {
            highestVotes = candidates[i].votes; // ...change high count to match his/her number of votes
        }
    }
    for (int i = 0; i < candidate_count; i++) // Iterate over candidates again
    {
        if (candidates[i].votes == highestVotes) // If candidate vote number == the highestVote...
        {
            printf("%s\n", candidates[i].name); // ...print that candidate's name. They are the winner.
        }
    }
    return;
}