#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");         //h marks the height of pyramid
    }    
    while (h > 8 || h <= 0);

    for (int i = 1; i <= h; i++) 
    {
        //This loop is for space to cover 
        for (int j = 1; j <= h - i; ++j)       
        {   
            // h-i place in each line of pyramid
            printf(" "); 
        }
        for (int k = 0; k < i; k++)            //this loop is for #
        {
            printf("#");
        }
        printf("\n");
    } 
}