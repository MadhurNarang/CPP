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

binarytreenode<int> *construct_inorder_preorder(int prearr[], int inarr[], int n, int prs, int pre, int ins, int ine)
// this function only works for NON REPEATING CHARACTERS
{
    if (n == 0 || ins > ine || prs > pre) // ins>ine || prs>pre can alone do th work of all......
    {
        return NULL;
    }

    binarytreenode<int> *smallroot = new binarytreenode<int>(prearr[prs]);

    int rootindex = -1;
    for (int i = ins; i <= ine; i++)
    {
        if (inarr[i] == prearr[prs])
        {
            rootindex = i;
            break;
        }
    }
    // root index can never be equal to -1 if input is correct

    binarytreenode<int> *smallleft = construct_inorder_preorder(prearr, inarr, n, prs + 1, rootindex - ins + prs, ins, rootindex - 1);

    binarytreenode<int> *smallright = construct_inorder_preorder(prearr, inarr, n, rootindex - ins + prs + 1, pre, rootindex + 1, ine);

    smallroot->left = smallleft;
    smallroot->right = smallright;

    return smallroot;
}

int main()
{
    int n;
    cin >> n;

    int *prearr = new int[n];
    int *inarr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> prearr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> inarr[i];
    }

    binarytreenode<int> *root = construct_inorder_preorder(prearr, inarr, n, 0, n - 1, 0, n - 1);

    printbinarytree(root);

    delete root;
}