#include<iostream>
#include <vector>
#include<queue>
using namespace std;

template <typename T>
class treenode
{
public:
    T data;
    vector<treenode<T> *> children;

    treenode(T data)
    {
        this->data = data;
    }

    ~treenode(T data)
    {
        for (int i = 0; i < root->children.size(); i++)
        {
            delete root->children.at(i);
        }
    }
};

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

int main()
{
    treenode<int> *root = inputtree();

    delete root;
    cout<<"TREE DELETED"<<endl;

    return 0;
}