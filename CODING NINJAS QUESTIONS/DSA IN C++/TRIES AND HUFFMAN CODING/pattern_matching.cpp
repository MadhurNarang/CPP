#include <iostream>
using namespace std;
#include "trie_class.h"

int main()
{
    int n;
    cin >> n;

    string word;
    trie t;

    for (int i = 0; i < n; i++)
    {
        cin >> word;
        t.pattern_insertword(word);
    }

    cin >> word;

    cout << t.pattern_searchword(word);
}