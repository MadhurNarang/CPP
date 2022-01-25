#include <iostream>
using namespace std;
#include "trie_class.h"

trienode *findword(trienode *root, string word)
{
    if (word.size() == 0)
    {
        return root;
    }

    trienode *ans;
    int index = word[0] - 'a';
    if (root->children[index] == NULL)
    {
        return NULL;
    }
    else
    {
        ans = findword(root->children[index], word.substr(1));
    }
    return ans;
}

void allpossiblewords(trienode *root, string word)
{
    if (root->isterminal == true)
    {
        cout << word << endl;
    }

    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
        {
            allpossiblewords(root->children[i], word + (char)(i + 'a'));
        }
    }
}

void autocomplete(trie t, string word)
{
    trienode *root = t.getroot();
    trienode *wordposition = findword(root, word);
    if (wordposition != NULL)
    {
        allpossiblewords(wordposition, word);
    }
}

int main()
{
    int n;
    cin >> n;
    trie t;
    string word;

    for (int i = 0; i < n; i++)
    {
        cin >> word;
        t.insertword(word);
    }

    cin >> word;

    autocomplete(t, word);
}