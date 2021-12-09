#include <iostream>
#include <queue>
#include <stack>
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

void zigzagorder_using_two_stacks(binarytreenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    int level = 1;
    stack<binarytreenode<int> *> rightleft;
    stack<binarytreenode<int> *> leftright;

    rightleft.push(root);

    while (!rightleft.empty() || !leftright.empty())
    {
        while (!rightleft.empty())
        {
            binarytreenode<int> *toprl = rightleft.top();
            rightleft.pop();

            cout << toprl->data << " ";

            if (toprl->left) //THESE STATEMENTS HELP US TO NOT CHECK NULL
            {
                leftright.push(toprl->left);
            }
            if (toprl->right) //THESE STATEMENTS HELP US TO NOT CHECK NULL
            {
                leftright.push(toprl->right);
            }
        }
        cout << endl;
        while (!leftright.empty())
        {
            binarytreenode<int> *toplr = leftright.top();
            leftright.pop();

            cout << toplr->data << " ";

            if (toplr->right) //THESE STATEMENTS HELP US TO NOT CHECK NULL
            {
                rightleft.push(toplr->right);
            }
            if (toplr->left) //THESE STATEMENTS HELP US TO NOT CHECK NULL
            {
                rightleft.push(toplr->left);
            }
        }
        cout << endl;
    }
}

void zigzagorder_using_one_stack_one_queue(binarytreenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    int order = 1;
    queue<binarytreenode<int> *> leftright;
    stack<binarytreenode<int> *> s;

    leftright.push(root);

    while (!s.empty() || !leftright.empty())
    {
        while (!leftright.empty())
        {
            binarytreenode<int> *frontlr = leftright.front();
            leftright.pop();

            s.push(frontlr);
        }

        while (!s.empty())
        {
            binarytreenode<int> *top = s.top();
            s.pop();

            cout << top->data << " ";

            if (order == -1)
            {
                if (top->right)
                {
                    leftright.push(top->right);
                }
            }
            if (top->left)
            {
                leftright.push(top->left);
            }
            if (order == 1)
            {
                if (top->right)
                {
                    leftright.push(top->right);
                }
            }
        }
        order *= -1;
        cout << endl;
    }
}

int main()
{
    binarytreenode<int> *root = inputbinarytree();

    zigzagorder_using_two_stacks(root);
    cout << endl;
    zigzagorder_using_one_stack_one_queue(root);

    delete root;
}