#include <iostream>
using namespace std;
#include "binary_search_tree_class.h"

int main()
{
    bst b;
    b.insertdata(10);
    b.insertdata(5);
    b.insertdata(20);
    b.insertdata(7);
    b.insertdata(3);
    b.insertdata(15);
    b.printbst();
    cout << endl;
    b.deletedata(10);
    b.deletedata(100);
    b.printbst();
    cout << endl;
}