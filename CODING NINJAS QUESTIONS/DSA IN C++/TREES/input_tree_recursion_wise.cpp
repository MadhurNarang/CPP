#include <iostream>
#include "tree_node.h"

treenode<int> *inputtree()
{
    int rootdata, nochildren;
    cout << "ENTER DATA : ";
    cin >> rootdata;
    cout << "ENTER NUMBER OF CHILDREN  OF " << rootdata << " : ";
    cin >> nochildren;

    treenode<int> *root = new treenode<int>(rootdata);

    for (int i = 0; i < nochildren; i++)
    {
        treenode<int> *child = inputtree();
        root->children.push_back(child);
    }
    return root;
}

void printtree(treenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children.at(i)->data << " , ";
    }
    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printtree(root->children.at(i));
    }
}

int main()
{
    treenode<int> *root = inputtree();

    printtree(root);

    return 0;
}