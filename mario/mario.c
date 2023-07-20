#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //n is an integer
    int n;
    do
    {
        //ask user for a height (n) between 1 and 8
        //ask again if imput is not between 1 and 8
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    //for each row
    for (int i = 0; i < n; i++)
    {
        //for each column
        for (int k = n; k > i + 1; k--)
        {
            //print a space
            printf(" ");
        }
        //for each column
        for (int j = 0; j <= i; j++)
        {
            //print a brick
            printf("#");
        }
        //for each column
        for (int l = 0; l < 2; l++)
        {
            //print two spaces
            printf(" ");
        }
        //for each column
        for (int m = 0; m <= i ; m++)
        {
            //print a brick
            printf("#");
        }


        //move to next row
        printf("\n");
    }

}