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

vector<int> *findnodepath(binarytreenode<int> *root, int k)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == k)
    {
        vector<int> *ans = new vector<int>;
        ans->push_back(root->data);
        return ans;
    }

    vector<int> *leftans = findnodepath(root->left, k);
    if (leftans != NULL)
    {
        leftans->push_back(root->data);
        return leftans;
    }

    vector<int> *rightans = findnodepath(root->right, k);
    if (rightans != NULL)
    {
        rightans->push_back(root->data);
        return rightans;
    }

    return NULL;
}

int main()
{
    binarytreenode<int> *root = inputbinarytree();
    int k;
    cin >> k;

    vector<int> *ans = findnodepath(root, k);

    if (ans != NULL)
        for (int i = 0; i < ans->size(); i++)
        {
            cout << ans->at(i) << " ";
        }

    delete ans;
    delete root;
}