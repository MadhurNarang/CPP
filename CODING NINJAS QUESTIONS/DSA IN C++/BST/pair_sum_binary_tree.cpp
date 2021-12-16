#include <iostream>
#include <queue>
#include <stack>
#include <climits>
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

bool checkdata(binarytreenode<int> *root, int data)
{
    if (root == NULL)
    {
        return false;
    }

    bool ans = false;
    if (root->data == data)
    {
        root->data = INT_MIN;
        return true;
    }
    else
    {
        ans = checkdata(root->left, data) || checkdata(root->right, data);
    }
    return ans;
}

void pairsum1(binarytreenode<int> *root, int s, binarytreenode<int> *node) // O(n^2) + tree gets altered with int_min
{
    if (root == NULL)
    {
        return;
    }

    int data = root->data;
    root->data = INT_MIN;
    if (data != INT_MIN)
    {
        bool ans = checkdata(node, (s - data));
        if (ans)
        {
            cout << min(data, s - data) << " " << max(data, s - data) << endl;
        }
    }
    pairsum1(root->left, s, node);
    pairsum1(root->right, s, node);
}

void binarytreetovector(binarytreenode<int> *root, vector<int> *v)
{
    if (root == NULL)
    {
        return;
    }

    v->push_back(root->data);
    binarytreetovector(root->left, v);
    binarytreetovector(root->right, v);
}

void vectorcopy(vector<int> *v1, vector<int> *v2, int si, int ei)
{
    int i = 0, j = si;
    for (; j <= ei;)
    {
        v1->at(j++) = v2->at(i++);
    }
    return;
}

void merge(vector<int> *v1, int si, int ei, int mid)
{
    vector<int> *v2 = new vector<int>;
    int i = si, j = mid + 1, k = 0;
    for (; i <= mid && j <= ei;)
    {
        if (v1->at(i) < v1->at(j))
        {
            v2->push_back(v1->at(i++));
            k++;
        }
        else
        {
            v2->push_back(v1->at(j++));
            k++;
        }
    }
    while (i <= mid)
    {
        v2->push_back(v1->at(i++));
        k++;
    }
    while (j <= ei)
    {
        v2->push_back(v1->at(j++));
        k++;
    }

    vectorcopy(v1, v2, si, ei);
    return;
}

void merge_sort(vector<int> *v, int si, int ei)
{
    if (si >= ei)
    {
        return;
    }

    int mid = (si + ei) / 2;

    merge_sort(v, si, mid);
    merge_sort(v, mid + 1, ei);

    merge(v, si, ei, mid);
    return;
}

void findpair(vector<int> *v, int s)
{
    for (int i = 0, j = v->size() - 1; i < j;)
    {
        if ((v->at(i) + v->at(j)) == s)
        {
            cout << v->at(i) << " " << v->at(j) << endl;
            i++;
            j--;
        }
        else if ((v->at(i) + v->at(j)) > s)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}

void pairsum2(binarytreenode<int> *root, int s) // O(nlogn)
{
    vector<int> *v = new vector<int>;

    binarytreetovector(root, v);

    merge_sort(v, 0, v->size() - 1);

    findpair(v, s);
}

int main()
{
    binarytreenode<int> *root = inputbinarytree();
    int s;
    cin >> s;

    pairsum2(root, s);
    cout << endl;
    pairsum1(root, s, root);

    delete root;
}