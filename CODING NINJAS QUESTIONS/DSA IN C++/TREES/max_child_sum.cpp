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

/*
treenode<int> *  maxchildsum(treenode<int> * root)
{
    if(root==NULL)
    {
        return 0;
    }

    treenode<int> * ansmax = root;

    int sum=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        sum+=root->children.at(i)->data;
    }

    for(int i=0;i<root->children.size();i++)
    {
        treenode<int> * smallmax = maxchildsum(root->children.at(i));

        int smallsum=smallmax->data;
        for(int i=0;i<smallmax->children.size();i++)  //this is extra part...it is being done twice
        {
            smallsum+=smallmax->children.at(i)->data;
        }

        if(smallsum>sum)
        {
            ansmax=smallmax;
        }
    }
    return ansmax;
}
*/

class max_child_ans
{
public:
    int sum;
    treenode<int> *node;

    max_child_ans(treenode<int> *root, int sum)
    {
        node = root;
        this->sum = sum;
    }
};

max_child_ans maxchildsumclass(treenode<int> *root)
{
    treenode<int> *maxsumnode = root;
    int maxsum;

    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children.at(i)->data;
    }

    maxsum = sum;

    for (int i = 0; i < root->children.size(); i++)
    {
        max_child_ans smallansclass = maxchildsumclass(root->children.at(i));

        if (sum < smallansclass.sum)
        {
            maxsum = smallansclass.sum;
            maxsumnode = smallansclass.node;
        }
    }

    max_child_ans maxclass(maxsumnode, maxsum);

    return maxclass;
}

treenode<int> *maxchildsum(treenode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return maxchildsumclass(root).node;
}

int main()
{
    treenode<int> *root = inputtree();

    cout << maxchildsum(root)->data << endl;

    return 0;
}