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

binarytreenode<int> *inputbinarytree()
{
    int rootdata;
    cout << "ENTER DATA : ";
    cin >> rootdata;

    if (rootdata == -1)
    {
        return NULL;
    }

    binarytreenode<int> *root = new binarytreenode<int>(rootdata);

    binarytreenode<int> *leftchild = inputbinarytree();
    binarytreenode<int> *rightchild = inputbinarytree();

    root->left = leftchild;
    root->right = rightchild;

    return root;
}

int main()
{
    binarytreenode<int> *root = inputbinarytree();

    printbinarytree(root);

    delete root;
}