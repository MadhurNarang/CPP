#include <iostream>
#include "tree_node.h"
#include <queue>

treenode<int> *inputtree()
{
    int rootdata;
    cout << "ENTER ROOTDATA : ";
    cin >> rootdata;

    treenode<int> *root = new treenode<int>(rootdata);

    queue<treenode<int> *> pendingnodes;

    pendingnodes.push(root);

    while (pendingnodes.size() != 0)
    {
        treenode<int> *front = pendingnodes.front();
        pendingnodes.pop();

        cout << "ENTER NUMBER OF CHILDREN  OF " << front->data << " : ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int childdata;
            cout << "ENTER " << i + 1 << "th child of " << front->data << " : ";
            cin >> childdata;

            treenode<int> *child = new treenode<int>(childdata);
            front->children.push_back(child);

            pendingnodes.push(child);
        }
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