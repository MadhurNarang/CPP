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

void print_nodes_at_depth(binarytreenode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    else
    {
        print_nodes_at_depth(root->left, k - 1);
        print_nodes_at_depth(root->right, k - 1);
    }
}

int distance_from_node(binarytreenode<int> *root, int node, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == node)
    {
        print_nodes_at_depth(root, k);
        return 0;
    }
    else
    {
        int ld = distance_from_node(root->left, node, k);
        if (ld != -1)
        {
            if (ld + 1 == k)
            {
                cout << root->data << " ";
            }
            else
            {
                print_nodes_at_depth(root->right, k - ld - 2);
            }
        }

        int rd = distance_from_node(root->right, node, k);
        if (rd != -1)
        {
            if (rd + 1 == k)
            {
                cout << root->data;
            }
            else
            {
                print_nodes_at_depth(root->left, k - rd - 2);
            }
        }

        if (ld == -1 && rd == -1)
        {
            return -1;
        }
        else if (ld != -1)
        {
            return ld + 1;
        }
        else
        {
            return rd + 1;
        }
    }
}

int main()
{
    binarytreenode<int> *root = inputbinarytree();
    int node, k;
    cin >> node >> k;

    distance_from_node(root, node, k);

    delete root;
}