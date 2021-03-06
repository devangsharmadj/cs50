// @ author Devang Sharma
// A runoff styled election program



#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX_CANDIDATES 9
#define MAX_VOTERS 9
#include<math.h>
typedef struct
{
    int votes;
    string name;
    bool eliminated;
}
candidate;
int voter_count;
int candidate_count;
int preferences[MAX_VOTERS][MAX_CANDIDATES];
candidate candidates[MAX_CANDIDATES];
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);
bool vote(int voter, int rank, string name);
int main(int argc, string argv[])
{
    if (argc > MAX_CANDIDATES || argc < 2)
    {
        // Checking if command line arguments are valid
        printf("Usage: ./plurality candidate names(upto 9 candidates)\n");
        exit(1);
    }
    candidate_count = argc - 1;
    // Storing names of candidates in the struct array
    for (int i = 1 ; i < argc ; i++)
    {
        // Storing initial values in the array
        candidates[i - 1].name = argv[i];
        candidates[i - 1].votes = 0;
        candidates[i - 1].eliminated = false;
    }
    int n;
    do
    {
        // Getting valid amount of voters
        n = get_int("Number of voters: ");
    }
    while (n > MAX_VOTERS);
    string name;
    voter_count = n;
    // For loop is only for the vote function
    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0; j < candidate_count; j ++)
        {
            name = get_string("Rank %i: ", j + 1);
            vote(i, j, name);
            if (vote(i, j, name) == false)
            {
                exit(1);
            }
        }
        printf("\n");
    }
    do
    {
        // Calling all functions
        tabulate();
        if (!print_winner())
        {
            int min = find_min();
            if (is_tie(min))
            {
                printf("The election is a TIE! \n");
                break;
            }
            else
            {
                eliminate(min);
            }
        }
        else
        {
            // If - else loop
            break;
        }
    }
    while (true);
}


bool vote(int voter, int rank, string name)
{
    // Look for candidate called 'name'
    // If candidate found update array preferences
    int found = 0;
    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(name, candidates[j].name) == 0)
        {
            // Storing the index of the candidate
            found = 1 ;
            preferences [voter][rank] = j;
            break;
        }
    }
    return (found == 1);
}

void tabulate(void)
{
    for (int i = 0; i < candidate_count; i ++)
    {
        // For loop for valid candidates
        if (!candidates[i].eliminated)
        {
            for (int j = 0; j < voter_count; j ++)
            {
                if (i == preferences[j][0])
                {
                    candidates[i].votes = candidates[i].votes + 1 ;
                }
            }
        }
        else
        {
            // For loop for invalid candidates
            for (int j = 0; j < voter_count; j ++)
            {
                int valid_candidate;
                int found = 0;
                if (i == preferences[j][found])
                {
                    do
                    {
                        // Traversing through the 2-D array
                        found++;
                        valid_candidate = preferences[j][found];
                    }
                    while (candidates[ valid_candidate].eliminated);
                    candidates[valid_candidate].votes = candidates[valid_candidate].votes + 1;
                }
            }
        }
    }

}

int find_min(void)
{
    int min = 100;
    // Going to find the candidate with the minimum vote
    // Going to call eliminated and is_tie function
    for (int i = 0; i < candidate_count; i ++)
    {
        if (!candidates[i].eliminated)
        {

            if (min > candidates[i].votes)
            {
                min = candidates[i].votes;
            }
        }
    }
    return min;
}

bool is_tie(int min)
{
    // Going to check if all the remaining candidates are tied
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

void eliminate(int min)
{
    // Eliminates all candidates with min votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}

bool print_winner(void)
{
    int n;
    if (voter_count % 2 == 0)
    {
        n = voter_count / 2 + 1 ;
        // Finding the majority of votes
    }
    else
    {
        n = ceil((float)voter_count / 2);
    }
    //Check if there is a winner and print the winner's name
    for (int i = 0; i < candidate_count; i ++)
    {
        if (!candidates[i].eliminated)
        {
            if (candidates[i].votes >= n)
            {
                // Printing the winner
                printf("%s\n", candidates[i].name);
                return true;
                exit(1);
            }
        }

    }
    return false;
}
