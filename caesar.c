#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc ,string argv[])
{

    int k = atoi(argv[1]);
    
    if (argc != 2)
    {
        printf ("Usage: ./caesar key\n");
        return 1;
    }

    if (k <= 0)
    {
        printf ("Usage: ./caesar key\n");
        return 1;
    }
    

    if (k > 0)
    {
        string plain = get_string ("plaintext:  ");
        string cipher = plain;

        for (int i = 0; i <=(strlen(plain)); i++)
        {

            if (isalpha(plain[i]))
            {
                if (isupper(plain[i]) && plain[i] >= 'A' && plain[i] <= 'Z')
                {
                    cipher[i] = (((plain[i] + k) - 65) % 26) + 65;
                }

                if (islower(plain[i]) && plain[i] >= 'a' && plain[i] <= 'z')
                {
                    cipher [i] = (((plain[i] + k) - 97) % 26) + 97;
                }
            }
            printf("ciphertest: ");
            printf("%s\n", cipher);
        }
        return 0;
    }
    
}
