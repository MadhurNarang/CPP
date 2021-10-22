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

void printreversenode(node *head)
{
    if (head == NULL)
    {
        return;
    }
    printreversenode(head->next);
    cout << head->data << " ";
    return;
}

node * reverselist(node * head)
{
    if(head->next==NULL)
    {
        return head;
    }
    node *x = reverselist(head->next);
    head
}

int main()
{
    int n;
    cin >> n;
    while (n != 0)
    {
        node *head = takeinput();
        printnode(head);
        cout << endl;
        printreversenode(head);
        cout << endl;
        n--;
    }
    return 0;
}