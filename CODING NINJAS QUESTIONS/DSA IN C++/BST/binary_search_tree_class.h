#include <iostream>
using namespace std;
#include <climits>
#include "binary_tree_node.h"

class bst
{
private:
    binarytreenode<int> *root;

    int minimumnodedata(binarytreenode<int> *node)
    {
        if (node == NULL)
        {
            return INT_MAX;
        }

        return min(node->data, minimumnodedata(node->left));
    }

    binarytreenode<int> *deletedata(int data, binarytreenode<int> *node)
    {
        if (node == NULL)
        {
            return NULL;
        }

        if (data == node->data)
        {
            if (node->left && node->right == NULL)
            {
                binarytreenode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else if (node->right && node->left == NULL)
            {
                binarytreenode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->left && node->right)
            {
                int minimumdata = minimumnodedata(node->right);
                node->data = minimumdata;
                node->right = deletedata(minimumdata, node->right);
                return node;
            }
            else if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
        }
        else if (data < node->data)
        {
            node->left = deletedata(data, node->left);
            return node;
        }
        else
        {
            node->right = deletedata(data, node->right);
            return node;
        }
    }

    binarytreenode<int> *insertdata(int data, binarytreenode<int> *node)
    {
        if (node == NULL)
        {
            binarytreenode<int> *insertnode = new binarytreenode<int>(data);
            return insertnode;
        }

        if (data < node->data)
        {
            node->left = insertdata(data, node->left);
        }
        else
        {
            node->right = insertdata(data, node->right);
        }
        return node;
    }

    bool hasdata(int data, binarytreenode<int> *node)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }
        else if (data < node->data)
        {
            return hasdata(data, node->left);
        }
        else
        {
            return hasdata(data, node->right);
        }
    }

    void printbst(binarytreenode<int> *node)
    {
        if (node == NULL)
        {
            return;
        }

        cout << node->data << " :";

        if (node->left)
        {
            cout << " L" << node->left->data;
        }
        if (node->right)
        {
            cout << " R" << node->right->data;
        }
        cout << endl;

        printbst(node->left);
        printbst(node->right);
    }

public:
    bst()
    {
        root = NULL;
    }

    ~bst()
    {
        delete root;
    }

    void deletedata(int data)
    {
        root = deletedata(data, root);
    }

    void insertdata(int data)
    {
        root = insertdata(data, root);
    }

    bool hasdata(int data)
    {
        return hasdata(data, root);
    }

    void printbst()
    {
        printbst(root);
    }
};