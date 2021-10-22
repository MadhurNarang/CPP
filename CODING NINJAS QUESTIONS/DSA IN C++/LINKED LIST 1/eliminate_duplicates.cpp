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
        this->next = NULL;
    }
};

node *takeinput()
{
    int data;
    node *head = NULL, *tail = NULL;
    cin >> data;
    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
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
    return;
}

int nodesize(node *head)
{
    int size = 0;
    while (head != NULL)
    {
        head = head->next;
        size++;
    }
    return size;
}

node *returntail(node *head)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    return head;
}

void remduplicates(node *head)
{
    int prev = head->data;
    node *prevnode = head;
    node *delnode = NULL;
    head = head->next;
    while (head != NULL)
    {
        if (head->data != prev)
        {
            prev = head->data;
            prevnode->next = head;
            prevnode = head;
        }
        else
        {
            delnode = head;
        }
        head = head->next;
        if (delnode != NULL)
        {
            delete delnode;
            delnode = NULL;
        }
    }
    prevnode->next = NULL;
}

int main()
{
    int n;
    cin >> n;
    while (n != 0)
    {
        node *head = takeinput();
        remduplicates(head);
        printnode(head);
        cout << endl;
        n--;
    }
    return 0;
}