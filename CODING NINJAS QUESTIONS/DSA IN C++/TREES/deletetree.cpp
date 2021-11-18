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

void deletetree(treenode<int> *root)
{
    if (root == NULL)
    {
        cout<<"NO TREE EXISTS";
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        deletetree(root->children.at(i));
    }

    delete root;
}

int main()
{
    treenode<int> *root = inputtree();

    deletetree(root);
    root =NULL;
    deletetree(root);

    return 0;
}