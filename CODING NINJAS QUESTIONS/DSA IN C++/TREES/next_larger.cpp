#include <iostream>
#include "tree_node.h"
#include <queue>
#include <climits>

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

treenode<int> * nextlarger(treenode<int>*root,int n)
{
    if(root==NULL)
    {
        return 0;
    }

    treenode<int> * ans;

    if(root->data>n)
    {
        ans=root;
    }
    else
    {
        ans=NULL;
    }

    for(int i=0;i<root->children.size();i++)
    {
        treenode<int> * smallans = nextlarger(root->children.at(i),n);
        
        if(root->children.at(i)->data>n)  //root
        {
            if(smallans==NULL || root->children.at(i)->data<smallans->data)
            {
                ans=root->children.at(i);
            }
        }
        else
        {
            ans=smallans;
        }
    }

    return ans;
}

int main()
{
    treenode<int> *root = inputtree();

    int n;
    cin>>n;
    if(nextlarger(root,n)!=NULL)
        cout << nextlarger(root,n)->data << endl;
    else
        cout<<"NULL"<<endl;

    return 0;
}