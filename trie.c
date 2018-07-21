#include <stdio.h>
#include <string.h>

typedef struct _trie
{
    char* word;
    struct _trie* path[59];
}trie;

int insert(char* key, trie* root)
{
    int keypos = 0;
    int keylen = strlen(key);
    
    trie* ptr = NULL;
    
    for (ptr = root; keypos < keylen; ptr = ptr->path[abs(key[keypos] - 'a')], keypos++)
    {
        trie* branch = malloc(sizeof(trie));
        ptr->path[abs(key[keypos] - 'a')] = branch;
    }
    
    ptr->word = malloc(strlen(key) + 1);
    ptr->word = strcpy(ptr->word, key);
    ptr->word[strlen(key)] = '\0';
    
    return 1;
}

int search(const char* key, const trie* root)
{
    int keypos = 0;
    int keylen = strlen(key);
    trie* ptr = NULL;

    for (ptr = root; keypos < keylen; ptr = ptr->path[abs(key[keypos] - 'a')], keypos++)
    {
        if (!ptr->path[abs(key[keypos] - 'a')])
           return 0;
    }
    
    if (ptr->word && strcmp(ptr->word, key) == 0)
        return 1;
    else
        return 0;
}
