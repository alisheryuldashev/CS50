/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

#define HTSIZE 65535 //proposed size of the hashtable as per unicode char table

/*initialize the node structure (linked list) for our hash table*/
typedef struct node {
        char word[LENGTH + 1];
        struct node *next;
}node;

/*initialize hash table - which is an array of linked lists*/
node *hashtable[HTSIZE];

//determine the hash function (hash function taken from CS50 course example)
int hash_function(const char *key)
{
    int hash = key[0] - 'a';
    return hash % HTSIZE;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{

    //create a new variable to hold the same length word + nul terminator. reason: we can't change const char* which is in stack and not in heap
    char word_copy[LENGTH+1];
    int length = strlen(word);

    //load the word's characters in lower case to new variable
    for (int i=0; i<length; i++) {
        int lowercaseword = tolower(word[i]);
        word_copy[i] = (char)lowercaseword;
    }

    //after the new variable filled with matching lowercase letters we add the nul terminator at the end
    word_copy[length] = '\0';

    //printf("%s", word_copy); //lowercase letters test passed

    //use hash function to ensure we look in the same place the word would appear in loaded dict
    int idx = hash_function(word_copy);
    //pointing head to hashtable's array location where we start looking for the current word
    node* head = hashtable[idx];
    if (head) {//if exists
        //traverse to check if word from speller is in loaded hashtable
        while (head) {
            if (strcmp(head->word, word_copy)==0) { //compare if word is the same as our new lowercase version of speller's word
                return true; //we tell speller we found the word
                head = head->next;
            }
         head = head->next;
        }

    }
    return false; //in case the word not found
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */

 /*counter to track number of loaded words*/
 int words = 0;

bool load(const char *dictionary)
{
    // TODO
    //empty your hashtable
    for(int i = 0; i < HTSIZE; i++)
    {
        hashtable[i] = NULL;
    }
    //read the dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("No %s found \n", dictionary);
        return false;
    }
    //create a new node for each word and read words from file
    while(!feof(dict))
    {
        node* new_node = malloc(sizeof(node));
        fscanf(dict,"%s", new_node -> word);

        //last node should point to NULL
        new_node->next = NULL;

        if(feof(dict)) {
            free(new_node);//free new node that we malloc'ed above
            break;
        }
        words++;
        //calling the hash function on new_node->word to get an index of a bucket
        int hash = hash_function(new_node -> word);
        node* head = hashtable[hash];

        if (head == NULL)  {
            hashtable[hash] = new_node;
        }
        else {
            new_node -> next = hashtable[hash];
            hashtable[hash] = new_node;
        }
    }
    fclose(dict); //close dictionary file
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return words;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // loop through each node in your table
    for (int i = 0; i < HTSIZE; i++) {
        //check for a node at the cursor
        node* cursor = hashtable[i];
        //if exists
        if (cursor != NULL) {
            //create a temp node to that position and move the cursor to next
            node* temp = cursor;
            cursor = cursor->next;
            //free current node
            free(temp);
        }
    }

    return true;
}
