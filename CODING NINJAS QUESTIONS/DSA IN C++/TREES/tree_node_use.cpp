#include <iostream>
#include "tree_node.h"

int main()
{
    treenode<int> *root = new treenode<int>(1);
    treenode<int> *node1 = new treenode<int>(2);
    treenode<int> *node2 = new treenode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);

    return 0;
}