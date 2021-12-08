#include <iostream>
#include <queue>
#include <math.h>
#include <stdlib.h>
using namespace std;
#include "binary_tree_node.h"

void printbinarytree(binarytreenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<binarytreenode<int> *> pendingnodes;

    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {
        binarytreenode<int> *front = pendingnodes.front();
        pendingnodes.pop();

        cout << front->data << " :";

        if (front->left) //(root->left!=NULL)
        {
            cout << " L" << front->left->data;
            pendingnodes.push(front->left);
        }
        if (front->right) //(root->right!=NULL)
        {
            cout << " R" << front->right->data;
            pendingnodes.push(front->right);
        }
        cout << endl;
    }
}

binarytreenode<int> *inputbinarytree()
{
    int rootdata;
    cout << "ENTER ROOT DATA : ";
    cin >> rootdata;

    if (rootdata == -1)
    {
        return NULL;
    }

    binarytreenode<int> *root = new binarytreenode<int>(rootdata);

    queue<binarytreenode<int> *> pendingnodes;

    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {
        binarytreenode<int> *front = pendingnodes.front();
        pendingnodes.pop();

        cout << "ENTER LEFT CHILD OF " << front->data << " : ";
        int leftchilddata;
        cin >> leftchilddata;
        if (leftchilddata != -1)
        {
            binarytreenode<int> *leftchild = new binarytreenode<int>(leftchilddata);
            pendingnodes.push(leftchild);
            front->left = leftchild;
        }

        cout << "ENTER RIGHT CHILD OF " << front->data << " : ";
        int rightchilddata;
        cin >> rightchilddata;
        if (rightchilddata != -1)
        {
            binarytreenode<int> *rightchild = new binarytreenode<int>(rightchilddata);
            pendingnodes.push(rightchild);
            front->right = rightchild;
        }
    }

    return root;
}

pair<bool, int> checkbalance(binarytreenode<int> *root)
{
    if (root == NULL)
    {
        pair<bool, int> basecase(true, 0);
        return basecase;
    }

    pair<bool, int> leftans = checkbalance(root->left);
    pair<bool, int> rightans = checkbalance(root->right);

    bool ans = true;
    int height;

    if (leftans.first == false || rightans.first == false)
    {
        ans = false;
    }
    else if (leftans.second - rightans.second < 2 && leftans.second - rightans.second > -2)
    {
        ans = false;
    }
    height = 1 + max(leftans.second, rightans.second);

    pair<bool, int> smallans(ans, height);
    return smallans;
}

int main()
{
    binarytreenode<int> *root = inputbinarytree();

    cout << checkbalance(root).first << endl;

    delete root;
}