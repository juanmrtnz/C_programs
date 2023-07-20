#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float colemanliau_index(int letternum, int wordnum, int sentnum);
float roundf(float index);

int main(void)
{
    string text = get_string("Text: ");

    int count_letters(string text);
    int letternum = count_letters(text);

    int count_words(string text);
    int wordnum = count_words(text);

    int count_sentences(string text);
    int sentnum = count_sentences(text);

    float colemanliau_index(int letternum, int wordnum, int sentnum);
    float index = colemanliau_index(letternum, wordnum, sentnum);

    if (index > 0 && index < 17)
    {
        printf("Grade %i\n", (int) round(index));
    }
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int letternum = 0;
    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letternum += 1;
        }
    }
    return letternum;
}

int count_words(string text)
{
    int wordnum = 0;
    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if ((text[i]) == ' ')
        {
            wordnum += 1;
        }
    }
    wordnum += 1;
    return wordnum;
}

int count_sentences(string text)
{
    int sentnum = 0;
    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if ((text[i]) == '.' || (text[i]) == '!' || (text[i]) == '?')
        {
            sentnum += 1;
        }
    }
    return sentnum;
}

float colemanliau_index(int letternum, int wordnum, int sentnum)
{
    float L = (float) letternum / (float) wordnum * 100;
    float S = (float) sentnum / (float) wordnum * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    return index;
}