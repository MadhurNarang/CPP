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

class node
{
public:
    binarytreenode<int> *data;
    node *next;
    node(binarytreenode<int> *data)
    {
        this->data = data;
        next = NULL;
    }
};

pair<node *, node *> bsttoll(binarytreenode<int> *root)
{
    if (root == NULL)
    {
        pair<node *, node *> basecase;
        basecase.first = NULL;
        basecase.second = NULL;

        return basecase;
    }

    node *head = new node(root);
    pair<node *, node *> leftans = bsttoll(root->left);
    pair<node *, node *> rightans = bsttoll(root->right);

    if (leftans.first != NULL)
    {
        leftans.second->next = head;
    }
    else
    {
        leftans.first = head;
    }

    if (rightans.second != NULL)
    {
        head->next = rightans.first;
    }
    else
    {
        rightans.second = head;
    }

    pair<node *, node *> ans;
    ans.first = leftans.first;
    ans.second = rightans.second;

    return ans;
}

void printlinkedlist(node *head)
{
    while (head != NULL)
    {
        cout << head->data->data << " ";
        head = head->next;
    }
}

int main()
{
    binarytreenode<int> *root = inputbinarytree();

    pair<node *, node *> anspair = bsttoll(root);

    printlinkedlist(anspair.first);

    delete root;
}