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

node *insertnode(node *head, int i, int data)
{
    if (i == 0)
    {
        node *newnode = new node(data);
        newnode->next = head;
        head = newnode;
        return head;
    }

    if (head == NULL)
    {
        return head;
    }
    node *x = insertnode(head->next, i - 1, data);
    head->next = x;
    return head;
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
        cin >> i >> data;
        head = insertnode(head, i, data);
        printnode(head);
        delete head; // I think loop is required to delete all nodes
        n--;
    }
}