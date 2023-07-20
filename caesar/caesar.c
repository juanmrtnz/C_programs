#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

string rotate(string plaintext, int key);

int main(int argc, string argv[])
{
    //if argc is not 2
    if (argc != 2)
    {
        //print error and exit
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //check lenght of string argv[1]
    int n = strlen(argv[1]);

    //check every character of argv[1]
    for (int i = 0; i < n; i++)
    {
        //check if they are digits
        if (isdigit(argv[1][i]))
        {
        }

        else
        {
            //print error and exit
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //convert string srgv[1] to integer
    int key = atoi(argv[1]);

    //ask user for plaintext
    string plaintext = get_string("plaintext: \n");


    printf("ciphertext: ");

    int m = strlen(plaintext);

    for (int i = 0; i < m; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                int p = (int) plaintext[i] - 65;
                char c = ((p + key) % 26) + 65;
                printf("%c", c);
            }
            if (islower(plaintext[i]))
            {
                int p = (int) plaintext[i] - 97;
                char c = ((p + key) % 26) + 97;
                printf("%c", c);
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}