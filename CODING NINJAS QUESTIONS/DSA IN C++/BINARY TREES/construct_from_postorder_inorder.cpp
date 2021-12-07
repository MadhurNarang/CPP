#include <iostream>
#include <queue>
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

binarytreenode<int> *construct_inorder_postorder(int posarr[], int inarr[], int n, int pos, int poe, int ins, int ine)
// this function only works for NON REPEATING CHARACTERS
{
    if (n == 0 || ins > ine || pos > poe) // ins>ine || pos>poe can alone do th work of all......
    {
        return NULL;
    }

    binarytreenode<int> *smallroot = new binarytreenode<int>(posarr[poe]);

    int rootindex = -1;
    for (int i = ins; i <= ine; i++)
    {
        if (inarr[i] == posarr[poe])
        {
            rootindex = i;
            break;
        }
    }
    // root index can never be equal to -1 if input is correct

    binarytreenode<int> *smallleft = construct_inorder_postorder(posarr, inarr, n, pos, pos + rootindex - 1 - ins, ins, rootindex - 1);
    // WE HAVE TO WRITE INDEXES WITH RESPECT TO RESPECTIVE ARRAY....
    // THAT IS.....ROOT INDEX IS INDEX OF INARR SO WE NEED TO FIND IT WITH RESPECT TO POSARR
    binarytreenode<int> *smallright = construct_inorder_postorder(posarr, inarr, n, pos + rootindex - ins, poe - 1, rootindex + 1, ine);

    smallroot->left = smallleft;
    smallroot->right = smallright;

    return smallroot;
}

int main()
{
    int n;
    cin >> n;

    int *posarr = new int[n];
    int *inarr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> posarr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> inarr[i];
    }

    binarytreenode<int> *root = construct_inorder_postorder(posarr, inarr, n, 0, n - 1, 0, n - 1);

    printbinarytree(root);

    delete root;
}