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

int diameter(binarytreenode<int> *root) // here time complexity is O(n*h)
{
    if (root == NULL)
    {
        return 0;
    }

    int option1 = treeheight(root->left) + treeheight(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

class hei_dia_pair // WE CAN USE INBUILT PAIR ALSO...IT HAS FIRST AND SECOND
{
public:
    int height;
    int diameter;

    hei_dia_pair(int height, int diameter)
    {
        this->height = height;
        this->diameter = diameter;
    }
};

hei_dia_pair diameter_better(binarytreenode<int> *root) // here time complexity is O(n)
{
    if (root == NULL)
    {
        hei_dia_pair basecase(0, 0);
        return basecase;
    }

    hei_dia_pair smallpair1 = diameter_better(root->left);
    hei_dia_pair smallpair2 = diameter_better(root->right);

    int maxdia = max(max(smallpair1.diameter, smallpair2.diameter), smallpair1.height + smallpair2.height);
    int height = 1 + max(smallpair1.height, smallpair2.height); // THIS IS NOT USING TREE HEIGHT FUNCTION
    hei_dia_pair smallans(height, maxdia);

    return smallans;
}

int main()
{
    binarytreenode<int> *root = inputbinarytree();

    cout << diameter(root) << endl;
    cout << treeheight(root) << endl;
    cout << diameter_better(root).diameter << endl;
    cout << diameter_better(root).height << endl;

    delete root;
}