// Implements a dictionary's functionality

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Variable for size()
unsigned int WordCount;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // make a lowercase copy.
    int len = strlen(word);
    char copy[len + 1];
    for (int i = 0; i < len; i++)
    {
        copy[i] = tolower(word[i]);
    }
    copy[len] = '\0';
    // without a lowercase copy I got errors

    node *cursor = table[hash(word)];
    while (cursor != NULL)
    {
        if (strcasecmp(copy, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
// Source of hash function: stackoverflow.com/questions/14409466/simple-hash-functions
unsigned int hash(const char *word)
{
    // make a lowercase copy
    int len = strlen(word);
    char copy[len + 1];
    for (int i = 0; i < len; i++)
    {
        copy[i] = tolower(word[i]);
    }
    copy[len] = '\0';
    // without a lowercase copy I got errors

    unsigned int count;
    unsigned int hashValue = 0;
    for (count = 0; copy[count] != '\0'; count++)
    {
        hashValue = copy[count] + (hashValue << 6) + (hashValue << 16) - hashValue;
    }
    return (hashValue % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file  == NULL)
    {
        return false;
    }

    // Read strings from file one at a time
    char word[LENGTH + 1];
    while ((fscanf(file, "%s", word)) != EOF)
    {
        // Variable for size()
        WordCount++;

        // Create a new node for each word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }

        strcpy(new_node->word, word);

        // Hash word to obtain a hash value
        int index = hash(new_node->word);

        // Insert node
        if (table[index] == NULL)
        {
            table[index] = new_node;
            new_node->next = NULL;
        }
        else
        {
            new_node->next = table[index];
            table[index] = new_node;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (WordCount > 0)
    {
        return (WordCount);
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;
}
