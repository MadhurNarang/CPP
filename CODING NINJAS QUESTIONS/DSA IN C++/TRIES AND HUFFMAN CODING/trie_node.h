#include <iostream>
using namespace std;

class trienode
{
public:
    char data;
    bool isterminal;
    trienode **children;

    trienode(char data)
    {
        this->data = data;
        isterminal = false;

        children = new trienode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};