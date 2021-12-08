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

pair<vector<node *>, int> levelwiselinkedlist(binarytreenode<int> *root)
{
    if (root == NULL)
    {
        pair<vector<node *> ,int> basecase(0,0);
        return basecase;
    }

    queue<binarytreenode<int> *> pendingnodes;
    vector<node *> v;
    node *head;
    node *temp;

    pendingnodes.push(root);
    pendingnodes.push(NULL);

    head=new node(root);
    temp=head;

    while (!pendingnodes.empty())
    {
        binarytreenode<int> *front = pendingnodes.front();
        temp->next=new node(front);
        temp=temp->next;
        pendingnodes.pop();

        if (front == NULL)
        {
            v.push_back(head);
            head=new node(pendingnodes.front());
            temp=head;

            if (pendingnodes.empty())
            {
                head=NULL;
                v.push_back(head);
                break;
            }
            else
                pendingnodes.push(NULL);
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

    pair<vector<node *>,int> ans(v,v.size());
    
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

    pair<vector<node *>, int> ans = levelwiselinkedlist(root);

    for (int i = 0; i < ans.second; i++)
    {
        printlinkedlist(ans.first[i]);
        cout << endl;
    }

    delete root;
}