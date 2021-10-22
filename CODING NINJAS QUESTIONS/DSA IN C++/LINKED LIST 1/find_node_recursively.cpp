#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

node *takeinput()
{
    int data;
    cin >> data;
    node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        node *n = new node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
        cin >> data;
    }
    return head;
}

int findnode(node *head, int data)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == data)
    {
        return 0;
    }
    int smallans = findnode(head->next, data);
    if (smallans == -1)
    {
        return smallans;
    }
    else
        return smallans + 1;
}

void printnode(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    int n, i, data;
    cin >> n;
    while (n > 0)
    {
        node *head = takeinput();
        cin >> data;
        int ans = findnode(head, data);
        cout << ans << endl;
        delete head; // I think loop is required to delete all nodes
        n--;
    }
}