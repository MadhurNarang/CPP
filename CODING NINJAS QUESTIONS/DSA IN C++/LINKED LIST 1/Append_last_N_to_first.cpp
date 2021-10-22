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

node *appendN(node *head, int N)
{
    node *temp = head;
    int n = nodesize(head) - N;
    node *tail = returntail(head);
    tail->next = head;
    for (int i = 0; i < n - 1; i++)
    {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}

int main()
{
    int n;
    cin >> n;
    while (n != 0)
    {
        int N;
        node *head = takeinput();
        cin >> N;
        head = appendN(head, N);
        printnode(head);
        n--;
    }
    return 0;
}