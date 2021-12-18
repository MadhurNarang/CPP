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

int treeheight(binarytreenode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int smallheight1 = treeheight(root->left);
    int smallheight2 = treeheight(root->right);

    if (smallheight1 > smallheight2)
    {
        return smallheight1 + 1;
    }
    else
    {
        return smallheight2 + 1;
    }
}

int largestbst1(binarytreenode<int> *root) //O(nh)
{
    if (root == NULL)
    {
        return 0;
    }

    int height = 0;

    if (checkbst3(root) == true)
    {
        height = treeheight(root);
        return height;
    }

    height = max(height, max(largestbst1(root->left), largestbst1(root->right)));

    return height;
}

pair<pair<bool, int>, pair<int, int>> largestbst2(binarytreenode<int> *root) //O(n)
{
    if (root == NULL)
    {
        pair<pair<bool, int>, pair<int, int>> basecase;
        basecase.first.first = true;
        basecase.first.second = 0;
        basecase.second.first = INT_MAX;
        basecase.second.second = INT_MIN;
        return basecase;
    }

    pair<pair<bool, int>, pair<int, int>> leftans, rightans;

    leftans = largestbst2(root->left);
    rightans = largestbst2(root->right);

    bool ansbool = (root->data > leftans.second.second) && (root->data <= rightans.second.first) && (leftans.first.first) && (rightans.first.first);
    int ansmax = max(root->data, max(leftans.second.second, rightans.second.second));
    int ansmin = min(root->data, min(leftans.second.first, rightans.second.first));

    pair<pair<bool, int>, pair<int, int>> ans;
    ans.first.first = ansbool;

    if (ansbool)
    {
        ans.first.second = max(leftans.first.second, rightans.first.second) + 1;
    }
    else
    {
        ans.first.second = max(leftans.first.second, rightans.first.second);
    }

    ans.second.first = ansmin;
    ans.second.second = ansmax;

    return ans;
}

int main()
{
    binarytreenode<int> *root = inputbinarytree();

    cout << largestbst1(root) << endl;
    cout << largestbst2(root).first.second;

    delete root;
}