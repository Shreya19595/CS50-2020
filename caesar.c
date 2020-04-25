#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc ,string argv[])
{
    if (argc != 2 || argc == 1)
    {
        printf ("Usage: ./caesar key\n");
        return 1;
    }
    
    int k = atoi(argv[1]);   
    printf("key: %i, %i", k, argc);
    if (k == 0)
    {
        printf ("Usage: ./caesar key\n");
        
    }
    
    else
    {
        string plain = get_string ("plaintext:  ");
        string cipher = plain;
       
        for (int i = 0; i <=(strlen(plain)); i++)
        {

            if (isalpha(plain[i]))
            {
                if (isupper(plain[i]) && plain[i] >= 'A' && plain[i] <= 'Z')
                {
                    cipher[i] = ((plain [i] + k) - 65);
                    cipher[i] = cipher[i] % 26;
                    cipher[i] = cipher [i] + 65;
                }
               
                if (islower(plain[i]) && plain[i] >= 'a' && plain[i] <= 'z')
                {
                    cipher[i] = ((plain [i] + k) - 97);
                    cipher[i] = cipher[i] % 26;
                    cipher[i] = cipher [i] + 97;
                }
            }

        }
        printf("ciphertext: ");
        printf("%s\n", cipher);
    }

}