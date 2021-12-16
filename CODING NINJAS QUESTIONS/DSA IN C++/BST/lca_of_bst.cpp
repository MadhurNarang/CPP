#include <iostream>
#include <queue>
#include <stack>
#include <climits>
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

int lca(binarytreenode<int> *root, int n1, int n2)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root->data;
    }

        int llca = lca(root->left, n1, n2);
    int rlca = lca(root->right, n1, n2);

    if (llca == -1 && rlca == -1)
    {
        return -1;
    }
    else if (llca == -1)
    {
        return rlca;
    }
    else if (rlca == -1)
    {
        return llca;
    }
    else
    {
        return root->data;
    }
}

int main()
{
    binarytreenode<int> *root = inputbinarytree();
    int n1, n2;
    cin >> n1 >> n2;

    cout << lca(root, n1, n2);

    delete root;
}