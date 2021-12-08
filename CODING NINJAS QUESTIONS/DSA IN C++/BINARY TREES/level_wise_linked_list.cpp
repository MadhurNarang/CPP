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

    node()
    {
        this->data = NULL;
        next = NULL;
    }

    node(binarytreenode<int> *data)
    {
        this->data = data;
        next = NULL;
    }
};

void printlinkedlist(node *head)
{
    while (head != NULL)
    {
        cout << head->data->data << " ";
        head = head->next;
    }
}

vector<node *> levelwiselinkedlist(binarytreenode<int> *root)
{
    if (root == NULL)
    {
        vector<node *> basecase;
        return basecase;
    }

    queue<binarytreenode<int> *> pendingnodes;
    vector<node *> v;
    node *head = NULL;
    node *tail = NULL;

    pendingnodes.push(root);
    pendingnodes.push(NULL);

    while (!pendingnodes.empty())
    {
        binarytreenode<int> *front = pendingnodes.front();
        pendingnodes.pop();

        node *temp = new node(front);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }

        if (front == NULL)
        {
            v.push_back(head);
            head = NULL;
            tail = NULL;

            if (pendingnodes.empty())
            {
                break;
            }
            else
            {
                pendingnodes.push(NULL);
            }
        }
        else
        {
            if (front->left)
            {
                pendingnodes.push(front->left);
            }
            if (front->right)
            {
                pendingnodes.push(front->right);
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        printlinkedlist(v.at(i));
        cout << endl;
    }

    return v;
}

int main()
{
    binarytreenode<int> *root = inputbinarytree();

    vector<node *> ans = levelwiselinkedlist(root);

    for (int i = 0; i < ans.size(); i++)
    {
        printlinkedlist(ans.at(i));
        cout << endl;
    }

    delete root;
}