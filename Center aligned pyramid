// @ author Devang Sharma
// Printing a middle aligned pyramid

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Levels : ");
    }
    while (n < 1 || n > 10);
    
    
    for (int i = 0 ; i < n  ; i++)
    {
        // For loop for printing n levels of rows
        for (int j = 0 ; j < n ; j++)
        {
            // For loop for printing right aligned pyramid
            if (n - 1 - i > j)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        for (int j = 0 ; j < n ; j++)
        {
            // For loop for printing small right aligned pyramid. 
            // Next to the left aligned pyramid.
            if (j == i || j > i)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
