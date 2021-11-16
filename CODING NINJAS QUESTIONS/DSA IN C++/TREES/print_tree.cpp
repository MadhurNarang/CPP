#include <iostream>
#include "tree_node.h"

void printtree(treenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children.at(i)->data << " , ";
    }
    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printtree(root->children.at(i));
    }
}

int main()
{
    treenode<int> *root = new treenode<int>(1);
    treenode<int> *node1 = new treenode<int>(2);
    treenode<int> *node2 = new treenode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);

    printtree(root);

    return 0;
}