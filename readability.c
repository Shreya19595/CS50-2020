#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{

    string text = get_string("Text: ");                                                                //getting a string as input
    
    int word = 1;
    int sentence = 0;
    int letter = 0;
        
    for (int i = 0; text[i] != '\0'; i++)
    {

        
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))                  //count of letter
        {
            letter++;
        }
        
        if (text[i] == ' ' && text[i + 1] != '\0')                                                   //count of word
        {
            word++;
        }
        
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')                                           //count of sentences
        {
            sentence++;
        }
    }

    float L = (100 * (float) letter / (float) word);
    float S = (100 * (float) sentence / (float) word);
    
    float index = 0.0588 * L - 0.296 * S - 15.8;                           //Calculating index value
    
    
    if (index < 16 && index >= 0)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}