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

bool checkdata(binarytreenode<int> *root, int data)
{
    if (root == NULL)
    {
        return false;
    }

    bool ans = false;
    if (root->data == data)
    {
        root->data = INT_MIN;
        return true;
    }
    else
    {
        ans = checkdata(root->left, data) || checkdata(root->right, data);
    }
    return ans;
}

void pairsum1(binarytreenode<int> *root, int s, binarytreenode<int> *node) //O(n^2)
{
    if (root == NULL)
    {
        return;
    }

    int data = root->data;
    root->data = INT_MIN;
    if (data != INT_MIN)
    {
        bool ans = checkdata(node, (s - data));
        if (ans)
        {
            cout << min(data, s - data) << " " << max(data, s - data) << endl;
        }
    }
    pairsum1(root->left, s, node);
    pairsum1(root->right, s, node);
}

void pairsum2(binarytreenode<int> *root, int s) //O(nlogn)
{
    vector<int> v = binarytreetovector(root);
    v = merge_sort(v);
    pairsum(v);
}

int main()
{
    binarytreenode<int> *root = inputbinarytree();
    int s;
    cin >> s;

    pairsum1(root, s, root);
    cout << endl
         << endl;
    pairsum2(root, s);

    delete root;
}