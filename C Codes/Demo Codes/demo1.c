#include <stdio.h>
#define N 5 // size of the pattern

int main()
{
    char word[] = "PROGRAM"; // word to print
    int len = sizeof(word) / sizeof(word[0]) - 1; // length of the word
    int i, j; // loop variables
    
    for (i = 0; i < N; i++) // iterate over rows
    {
        for (j = 0; j < N; j++) // iterate over columns
        {
            if (i == j) // diagonal from top-left to bottom-right
            {
                printf("%c ", word[i]);
            }
            else if (i + j == N - 1) // diagonal from top-right to bottom-left
            {
                printf("%c ", word[len - i]);
            }
            else // empty space
            {
                printf("  ");
            }
        }
        printf("\n"); // new line after each row
    }
    
    return 0;
}