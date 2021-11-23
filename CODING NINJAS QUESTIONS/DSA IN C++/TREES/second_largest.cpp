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

class secondlargestclass
{
public:
    treenode<int> *lar;
    treenode<int> *slar;
};

secondlargestclass *secondlargest(treenode<int> *root)
{
    secondlargestclass *ans = new secondlargestclass;

    ans->lar = root;
    ans->slar = new treenode<int>(INT_MIN);

    for (int i = 0; i < root->children.size(); i++)
    {
        secondlargestclass *smallans = secondlargest(root->children.at(i));

        if (smallans->lar->data > ans->lar->data)
        {
            if (ans->lar->data > smallans->slar->data)
            {
                ans->slar = ans->lar;
            }
            else
            {
                ans->slar = smallans->slar;
            }
            ans->lar = smallans->lar;
        }
        else
        {
            if (ans->lar->data == smallans->lar->data)
            {
                if (ans->slar->data < smallans->slar->data)
                {
                    ans->slar = smallans->slar;
                }
            }
            else if (ans->slar->data < smallans->lar->data && ans->lar->data != smallans->lar->data)
            {
                ans->slar = smallans->lar;
            }
        }
    }

    return ans;
}

treenode<int> *secondlargestclassreturn(treenode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (secondlargest(root)->slar->data == INT_MIN)
    {
        return NULL;
    }
    else
        return (secondlargest(root)->slar);
}

int main()
{
    treenode<int> *root = inputtree();

    if (secondlargestclassreturn(root) != NULL)
        cout << secondlargestclassreturn(root)->data << endl;
    else
        cout << "NULL" << endl;

    return 0;
}