#include <iostream>
#include <queue>
#include <stack>
#include <climits>
#include <string>
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

bool isleaf(binarytreenode<int> *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void path_root_to_leaf(binarytreenode<int> *root, int k, vector<int> v = {})
{
    if (root == NULL)
    {
        return;
    }

    if (k < 0)
    {
        return;
    }

    v.push_back(root->data);

    if (isleaf(root) && root->data == k)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v.at(i) << " ";
        }
        cout << endl;
        return;
    }
    else
    {
        path_root_to_leaf(root->left, k - root->data, v);
        path_root_to_leaf(root->right, k - root->data, v);
    }
    return;
}

int main()
{
    binarytreenode<int> *root = inputbinarytree();
    int k;
    cin >> k;

    path_root_to_leaf(root, k);

    delete root;
}