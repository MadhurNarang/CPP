#include <iostream>
using namespace std;
#include "binary_tree_node.h"

int main()
{
    binarytreenode<int> *root = new binarytreenode<int>(1);
    binarytreenode<int> *node1 = new binarytreenode<int>(2);
    binarytreenode<int> *node2 = new binarytreenode<int>(3);

    root->left = node1;
    root->right = node2;
}