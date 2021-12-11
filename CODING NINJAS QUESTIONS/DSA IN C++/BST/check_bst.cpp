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

int maximum(binarytreenode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(binarytreenode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool checkbst1(binarytreenode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    int lmax = maximum(root->left);
    int rmin = minimum(root->right);

    bool ans = (root->data > lmax) && (root->data <= rmin) && checkbst1(root->left) && checkbst1(root->right);

    return ans;
}

pair<bool, pair<int, int>> checkbst2(binarytreenode<int> *root)
{
    if (root == NULL)
    {
        pair<bool, pair<int, int>> basecase;
        basecase.first = true;
        basecase.second.first = INT_MAX;
        basecase.second.second = INT_MIN;
        return basecase;
    }

    pair<bool, pair<int, int>> leftans, rightans;

    leftans = checkbst2(root->left);
    rightans = checkbst2(root->right);

    bool ansbool = (root->data > leftans.second.second) && (root->data <= rightans.second.first) && (leftans.first) && (rightans.first);
    int ansmax = max(root->data, max(leftans.second.second, rightans.second.second));
    int ansmin = min(root->data, min(leftans.second.first, rightans.second.first));

    pair<bool, pair<int, int>> ans;
    ans.first = ansbool;
    ans.second.first = ansmin;
    ans.second.second = ansmax;

    return ans;
}

bool checkbst3(binarytreenode<int> *root, int minlimit = INT_MIN, int maxlimit = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data < minlimit || root->data > maxlimit)
    {
        return false;
    }

    bool leftans = checkbst3(root->left, minlimit, root->data - 1);
    bool rightans = checkbst3(root->right, root->data, maxlimit);

    return (leftans && rightans);
}

int main()
{
    binarytreenode<int> *root = inputbinarytree();

    cout << checkbst1(root) << endl;
    cout << checkbst2(root).first << endl;
    cout << checkbst3(root) << endl;

    delete root;
}