// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"
int noOfWords = 0;
bool ifloaded;


//declare trie node
typedef struct Node
{
    //check if it is a word
    bool is_word;
    //children nodes to link with other alphabets
    struct Node *children[27];
} Node;

Node *root;
//function prototype
int clean(Node *);


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //set current node to root
    Node *current = root;

    //get size for for loop
    int size = strlen(word);

    for (int i = 0; i < size; i++)
    {
        //check for apostrophe case
        if (word[i] == '\'')
        {
            //if that place is null in trie it mean word is not allocated , hence return false
            if (current->children[26] == NULL)
            {
                return false;
            }
            else
            {
                //size - 1 is used because in the last iteration of loop
                //we have to decide if the word is in dictionary or not!
                if (i != size - 1)
                {
                    current = current->children[26];

                }
                else
                {
                    //return is_word as it is also in boolean form
                    current = current->children[26];
                    return current->is_word;
                }
            }
        }

        else
        {
            //check for alphabetical input
            int wordsize;
            //since it is const char we cannot change it, to make program case-insensitive
            //algorithm is used
            if (word[i] >= 'A' && word[i] <= 'Z')
            {
                wordsize = word[i] + 'a' - 'A';
            }
            else
            {
                wordsize = word[i];
            }
            //checking in the same way as in apostrophe
            if (current->children[wordsize - 'a'] == NULL)
            {
                return false;
            }
            else
            {
                if (i != size - 1)
                {
                    current = current->children[wordsize - 'a'];
                }
                else
                {
                    current = current->children[wordsize - 'a'];
                    return current->is_word;
                }
            }
        }



    }
    //if loop reaches here means word isn't in dictionary, so return false
    return false;
}










//Node Structure
struct Node *getnewnode()
{

    Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->is_word = false;
    for (int i = 0; i < 27; i++)
    {
        newnode->children[i] = NULL;

    }
    return newnode;
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    //get root node
    root = getnewnode();
    //open file

    FILE *infile = fopen(dictionary, "r");

    //check if file is opened correctly
    if (infile == NULL)
    {
        fclose(infile);
        fprintf(stderr, "Could not create ");
        return false;
    }

    //variable to store words
    char word[46];

    //scan word-by-word till EOF
    while (fscanf(infile, "%s\n", word) != EOF)
    {
        Node *current = root;

        for (int i = 0; word[i] != '\0'; i++)
        {
            if (word[i] == '\'')
            {
                if (current->children[26] == NULL)
                {
                    Node *ispresent = getnewnode();
                    current->children[26] = ispresent;
                    current = ispresent;
                }
                else
                {
                    current = current->children[26];
                }
            }
            else
            {
                word[i] = tolower(word[i]);
                if (current->children[word[i] - 'a'] == NULL)
                {
                    Node *ispresent = getnewnode();
                    current->children[word[i] - 'a'] = ispresent;
                    current = ispresent;
                }
                else
                {
                    current = current->children[word[i] - 'a'];
                }
            }

        }
        current->is_word = true;
        noOfWords++;

    }

    fclose(infile);
    ifloaded = true;
    return true;
}








// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (ifloaded == true)
    {
        return noOfWords;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if (clean(root))
    {
        return false;
    }

    return true;
}
int clean(Node *here)
{
    for (int i = 0; i < 27; i++)
    {
        if (here->children[i] != NULL)
        {
            clean(here->children[i]);
        }

    }
    free(here);
    return 0;
}
