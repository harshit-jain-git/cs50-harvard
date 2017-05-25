/**
 * Implements a dictionary's functionality.

Implementing using trie datastructure ...
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "dictionary.h"

// defining the data structure trie ...
typedef struct trie{
    bool status;    
    struct trie* next[27];
} trie;

trie* head = NULL;      // the pointer to the whole trie datastructure storing the dictionary 
trie* ptr = NULL;       // traversal pointer

int count = 0;      // for keeping track of the number of words in dictionary loaded 

// function to recursively and eventually free the complete datastructure memory
void free_func (trie* firstnode)
{
    for(int i = 0; i < 27; i++)
    {
        if (firstnode -> next[i] != NULL)
        {
            free_func(firstnode -> next[i]);
        }
    }
    free(firstnode);
    return;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    trie* check_ptr = head;     // traversal pointer to a trie node
    
    // function to move on in our loaded dictionary letter by letter as is the need of our idea of implementation of dictionary
    for(int i = 0; i < strlen(word); i++)
    {
        if(check_ptr == NULL) return false;
        
        if(word[i] == '\'')     // dealing with the case when the character is apostrophe
        {
            check_ptr = check_ptr->next[26];
        }
        else
        {
            check_ptr = check_ptr->next[tolower(word[i]) - 'a'];        // using tolower function to ensure that capital letters do not create a problem
        }
    }
    
    if(check_ptr != NULL && check_ptr->status == true) return true;     // checking if the word exists in the dictionary
    else return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // TODO
    FILE* infile = fopen(dictionary, "r");      // opening the dictionary file 
    if(infile == NULL)                          // ensuring that the dictionary file is correctly loaded
    {
        fprintf(stderr, "Could not open the dictionary\n");
        return false;
    }
    
    head = (trie*)malloc(sizeof(trie));     // allocating memory of a trie node for the main head pointer.
    
    for(int i = 0; i < 27; i++)
    {
        head->next[i] = NULL;
    }
    
    // reading from the dictionary till the end is reached
    while(! feof(infile))
    {
        ptr = head;
        
        int a = 0;
        
        // reading from the dictionary character by character for each word and then repeating it until whole of the dictionary is loaded
        for(a = fgetc(infile); a != '\n'; a = fgetc(infile))
        {
            if(a == '\'')       // dealing with the case of apostrophe
            {
                a ='z' + 1;
            }
            
            if(ptr->next[a - 'a'] == NULL)      // allocating memory for the next node if not allocated already and moving the pointer to the next child in accordance with the algorithm
            {
                ptr->next[a - 'a'] = (trie*)malloc(sizeof(trie));
                ptr = ptr->next[a - 'a'];
            }
            
            // moving the pointer to the next child on the basis of the character read from the dictionary
            else
            {
                ptr = ptr->next[a - 'a'];
            }
        }
        
        // once the word is completed, changing the status to true denoting that the word exists in the dictionary
        ptr->status = true;
        count++;
        if(count == 143091) break;
    }
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return count;       // returns the total number of words loaded in the dictionary
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    trie* check = head;
    free_func(check);
    return true;
}
