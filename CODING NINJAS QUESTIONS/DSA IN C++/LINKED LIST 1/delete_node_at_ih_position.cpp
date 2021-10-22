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
    int count = 0;
    node *temp = head;
    node *newnode = new node(data);
    if (i == 0)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    while (count < i - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}

node *deletenode(node *head, int i)
{
    int count = 0;
    node *temp = head;
    node *delnode;
    if (i == 0)
    {
        delnode = head;
        head = head->next;
        delete delnode;
        return head;
    }
    while (count < i - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        delnode = temp->next;
        temp->next = delnode->next;
        delete delnode;
    }
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
    int n, i;
    cin >> n;
    while (n > 0)
    {
        node *head = takeinput();
        cin >> i;
        head = deletenode(head, i);
        printnode(head);
        delete head; //I think loop is required to delete all nodes
        n--;
    }
}