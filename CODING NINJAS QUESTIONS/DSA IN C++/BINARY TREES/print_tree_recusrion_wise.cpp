#include <iostream>
using namespace std;
#include "binary_tree_node.h"

void printbinarytree(binarytreenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " :";

    if (root->left) //(root->left!=NULL)
    {
        cout << " L" << root->left->data;
    }
    if (root->right) //(root->right!=NULL)
    {
        cout << " R" << root->right->data;
    }
    cout << endl;

    printbinarytree(root->left);
    printbinarytree(root->right);
}

int main()
{
    binarytreenode<int> *root = new binarytreenode<int>(1);
    binarytreenode<int> *node1 = new binarytreenode<int>(2);
    binarytreenode<int> *node2 = new binarytreenode<int>(3);

    root->left = node1;
    root->right = node2;

    printbinarytree(root);
}