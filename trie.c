#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct _trie
{
    bool _is_word;
    struct _trie* path[59];
}trie;

trie* DICT;

unsigned int WERDS = 0;
unsigned int BRANCHCOUNT = 0;
unsigned int PATHCOUNT = 0;

int insert(char* key, trie* root)
{
    int keypos = 0;
    int keylen = strlen(key);

    trie* ptr = NULL;

    for (ptr = root; keypos < keylen; ptr = ptr->path[abs(key[keypos] - 'a')], keypos++)
    {
        if (!ptr->path[abs(key[keypos] - 'a')])
        {
            trie* branch = calloc(1, sizeof(trie));
            BRANCHCOUNT++;
            if (!branch)
                return 0;

            ptr->path[abs(key[keypos] - 'a')] = branch;
        }
    }

    if (!ptr->_is_word)
    {
        ptr->_is_word = true;
        return 1;
    }
    else
        return 0;
}

int search(const char* key, trie* root)
{
    int keypos = 0;
    int keylen = strlen(key);

    trie* ptr = NULL;

    for (ptr = root; keypos < keylen; ptr = ptr->path[abs(tolower(key[keypos]) - 'a')], keypos++)
    {
        if (!ptr->path[abs(tolower(key[keypos]) - 'a')])
            return 0;
    }

    if (ptr->_is_word == 1)
        return 1;
    else
        return 0;
}

int clear(trie* root)
{
    for (int i = 0; i < 59; i++)
    {
        if (root->path[i] != NULL)
            clear(root->path[i]);
    }
    free(root);

    PATHCOUNT++;
    return 0;
}
