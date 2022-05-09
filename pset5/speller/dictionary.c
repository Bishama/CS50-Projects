// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include<ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

//Number of words
unsigned int word_count;

//Index value after hashing
unsigned int hash_value;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    hash_value = hash(word);        // Get hash value
    node *cursor = table[hash_value];      //Point cursor to head
   
    while (cursor != NULL)     //Iterate through the link list
    {
        if (strcasecmp(word, cursor->word) == 0)                                  //Compare strings
        {
            return true;
        }
        else
        {
            cursor = cursor->next;         //Point cursor to next element of linked list
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;
    while ((c = toupper(*word++)))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    char dword[LENGTH + 1];                                      //storing each word in a buffer(dword)

    // Open dictionary file
    FILE *dfile = fopen(dictionary, "r");
    if (!dfile)
    {
        return false;
    }

    //Read string from file
    while (fscanf(dfile, "%s", dword) != EOF)
    {
        //For each word create a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, dword);
        //Call hash function on the particular word
        hash_value = hash(dword);
        //Insert node into a hash table
        n->next = table[hash_value];
        table[hash_value] = n;
        //Keep track of number of words
        word_count++;

    }


    fclose(dfile);
    return true;

}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (word_count > 0)
    {
        return word_count;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
       
        if (i == N - 1 && cursor == NULL)
        {
            return true; 
        }
    }
    return false;
}
