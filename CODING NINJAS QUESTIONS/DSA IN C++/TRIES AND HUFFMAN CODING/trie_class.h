#include "trie_node.h"
#include <string>

class trie
{
    trienode *root;

public:
    trie()
    {
        root = new trienode('\0');
    }

    void insertword(trienode *root, string word)
    {
        //base case
        if (word.size() == 0)
        {
            root->isterminal = true;
            return;
        }

        //small calculation
        int index = word[0] - 'a';
        trienode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new trienode(word[0]);
            root->children[index] = child;
        }

        //recursive call
        insertword(child, word.substr(1));
    }

    // helper funcion
    void insertpord(string word)
    {
        insertword(this->root, word);
    }
};