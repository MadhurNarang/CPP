#include <iostream>
using namespace std;
#include "trie_class.h"

int main()
{
    trie t;
    t.insertword("and");
    t.insertword("are");
    t.insertword("dot");

    cout << t.searchword("and") << endl;

    t.removeword("and");
    cout << t.searchword("and") << endl;
}
