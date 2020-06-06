// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *remove_node(node *ptr);
node *add_node(node *ptr, char *word);

//size of each word
const unsigned int M = 100;

// Number of buckets in hash table
const unsigned int N = 200000;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Declare an array for word
    char term[M];

    // Copy word and convert to lowercase
    strcpy(term, word);
    for (int i = 0; word[i]; i++)
    {
        term[i] = tolower(word[i]);
    }

    // Get the hash value for word
    int hash_value = hash((const char *) term) % N;

    // Sets list to point that `hash_value` element of table
    node *list = table[hash_value];

    // Iterate over linked list
    while (list != NULL)
    {
        // If word found return
        if (strcmp(list->word, term) == 0)
        {
            return true;
        }

        // Set pointer to next element
        list = list->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash = 5381;
    int c;

    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //open dictionary
    FILE *dict = fopen(dictionary, "r");

    //checks if dictionary is empty or not
    if (dict == NULL)
    {
        return false;
    }

    //allocate memory for each word
    char *word = malloc(sizeof(char) * M);      //M is length of word
    if (word == NULL)
    {
        fclose(dict);
        return false;
    }
    // Iterate over dictionary
    while (fscanf(dict, "%s", word) != EOF)
    {
        // Add word to hash table
        int hash_value = hash((const char *) word) % N;
        table[hash_value] = add_node(table[hash_value], word);
    }
    // Free allocated memory
    free(word);

    // Close dictionary
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // Initialize counter and declare pointer to node
    int counter = 0;
    node *list = NULL;

    // Iterate over the hash table
    for (int i = 0; i < N; i++)
    {
        // Set list as pointer to the linked list
        list = table[i];

        // Iterate over the linked list
        while (list != NULL)
        {
            counter++;
            list = list->next;
        }
    }
    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Iterate over hash table
    for (int i = 0; i < N; i++)
    {
        // Remove linked list connected to the pointer
        while (table[i] != NULL)
        {
            table[i] = remove_node(table[i]);
        }
    }

    return true;
}

// Add new node to the linked list
node *add_node(node *ptr, char *word)
{
    // Allocate memory for new node
    node *new = malloc(sizeof(node));
    if (new == NULL)
    {
        return NULL;
    }

    // Copy word into new node
    strcpy(new->word, word);

    // Update pointer
    new->next = ptr;

    // Return pointer to new node
    return new;
}

// Remove node from the linked list
node *remove_node(node *ptr)
{
    // Temporary pointer to store the next pointer
    node *temp = ptr->next;

    // Free the allocated memory for node
    free(ptr);

    // Return the next pointer
    return temp;
}
