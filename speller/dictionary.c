// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <cs50.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int wordcount = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int key = hash(word);

    node *nodepointer = table[key];

    while (nodepointer != NULL)
    {
        if (strcasecmp(nodepointer-> word, word) == 0)
        {
            return true;
        }

        nodepointer = nodepointer-> next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    //return toupper(word[0]) - 'A';
    int val = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        val += tolower(word[i]);
    }

    return val % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *filepointer = fopen(dictionary, "r");
    if (filepointer == NULL)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char tmpword[LENGTH + 1];

    while (fscanf(filepointer, "%s\n", tmpword) != EOF)
    {
        node *tmpnode = malloc(sizeof(node));
        strcpy(tmpnode-> word, tmpword);
        int key = hash(tmpword);
        if (table[key] == NULL)
        {
            tmpnode-> next = NULL;
            table[key] = tmpnode;
        }
        else
        {
            tmpnode-> next = table[key];
            table[key] = tmpnode;
        }

        wordcount++;
    }

    fclose(filepointer);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *nodepointer = table[i];

        while (nodepointer != NULL)
        {
            node *erase = nodepointer;
            nodepointer = nodepointer-> next;
            free(erase);
        }

        table[i] = NULL;
    }

    return true;
}
