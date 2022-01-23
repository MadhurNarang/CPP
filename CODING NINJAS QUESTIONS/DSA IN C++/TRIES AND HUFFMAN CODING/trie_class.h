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
        // base case
        if (word.size() == 0)
        {
            root->isterminal = true;
            return;
        }

        // small calculation
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

        // recursive call
        insertword(child, word.substr(1));
    }

    // helper funcion
    void insertword(string word)
    {
        insertword(this->root, word);
    }

    bool searchword(trienode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            return (root->isterminal == true);
        }

        // small calculations
        bool ans = true, smallans;
        int index = word[0] - 'a';
        trienode *child = root->children[index];

        if (child == NULL)
        {
            return false;
        }
        else
        {
            // recursive call
            smallans = searchword(child, word.substr(1));
        }

        return smallans && ans;
    }

    // helper function
    bool searchword(string word)
    {
        return searchword(this->root, word);
    }

    void removeword(trienode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            root->isterminal = false;
            return;
        }

        // small calculation
        int index = word[0] - 'a';
        trienode *child = root->children[index];
        if (child != NULL)
        {
            // recursive call
            removeword(child, word.substr(1));

            // remove child if it is useless
            if (child->isterminal == false)
            {
                for (int i = 0; i < 26; i++)
                {
                    if (child->children[i] != NULL)
                    {
                        return;
                    }
                }
                delete child;
                root->children[index] = NULL;
            }
        }
        else
        {
            return;
        }
    }

    // helper function
    void removeword(string word)
    {
        removeword(this->root, word);
    }

    void pattern_insertword(string word)
    {
        for (int i = 0; i < word.size(); i++)
        {
            insertword(word.substr(i));
        }
    }

    bool pattern_searchword(trienode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            return true;
        }

        // small calculations
        bool ans = true, smallans;
        int index = word[0] - 'a';
        trienode *child = root->children[index];

        if (child == NULL)
        {
            return false;
        }
        else
        {
            // recursive call
            smallans = pattern_searchword(child, word.substr(1));
        }

        return smallans && ans;
    }

    // helper function
    bool pattern_searchword(string word)
    {
        return pattern_searchword(this->root, word);
    }
};