#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // variable decleration
    int letters = 0;
    int words = 1;
    int sentences = 0;
    // get user input
    string text = get_string("Text: ");

    // // print value output
    // printf("Grade ");

    // measure length of user input
    for (int a = 0; a < strlen(text); a++)
    {
        char c = text[a];
        // measure letters in ASCII / UNICODE format from A to Z
        if (isalpha(c) != 0)
        {
            // increment values until loop = false
            letters++;
        }

        // measure words per space used
        else if (c == ' ')
        {
            words++;
        }

        // measure end of sentences per ending punctuation mark commonly used
        else if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }

    // Calculation
    float L = ((float)letters / (float)words) * 100;
    float S = ((float)sentences / (float)words) * 100;
    float subindex = (0.0588 * L) - (0.296 * S) - 15.8;
    int index = round(subindex);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
