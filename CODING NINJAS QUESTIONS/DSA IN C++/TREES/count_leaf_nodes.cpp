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

    queue<treenode<int> *> pendingnodes;
    pendingnodes.push(root);

    while (pendingnodes.size() != 0)
    {
        treenode<int> *front = pendingnodes.front();
        pendingnodes.pop();

        cout << front->data << " : ";

        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children.at(i)->data << " , ";

            pendingnodes.push(front->children.at(i));
        }
        cout << endl;
    }
}

int treeheight(treenode<int> *root)
{
    int height = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int smallheight=treeheight(root->children.at(i));
        if (smallheight > height)
        {
            height = smallheight;
        }
    }
    height++;

    return height;
}

void printlevel(treenode<int>* root,int k)
{
    if(root==NULL)
    {
        return;
    }

    if(k==0)
    {
        cout<<root->data<<" , ";
        return;
    }

    for(int i=0;i<root->children.size();i++)
    {
        printlevel(root->children.at(i),k-1);
    }
}

int countleafnodes(treenode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }

    if(root->children.size()==0)
    {
        return 1;
    }

    int count=0;

    for(int i=0;i<root->children.size();i++)
    {
        count+=countleafnodes(root->children.at(i));
    }   
    return count;
}

int main()
{
    treenode<int> *root = inputtree();

    cout<<countleafnodes(root);

    return 0;
}