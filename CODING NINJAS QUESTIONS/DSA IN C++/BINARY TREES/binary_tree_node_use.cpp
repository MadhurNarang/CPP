#include<iostream>
using namespace std;
#include"binary_tree_node.h"

int main()
{
    binarytreenode<int> * root = new binarytreenode<int>(1);
    binarytreenode<int> * left = new binarytreenode<int>(2);
    binarytreenode<int> * right = new binarytreenode<int>(3);

    root->left=left;
    root->right=right;
}