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

node *swapnodes(node *head, int i, int j)
{
    node *firstele = NULL, *secondele = NULL, *temp,*headtemp=head;
    if (i == 0)
    {
        firstele = head;
    }
    if(j==0)
    {
        secondele = head;
    }
    j--;
    i--;
    while(head!=NULL)
    {
        if(i==0&&firstele==NULL)
        {
            firstele = head->next;
        }
        if(j==0&&secondele==NULL)
        {
            secondele = head->next;
        }
        if(i==0 && j==0)
        {
            break;
        }
        i--;
        j--;
        head = head->next;
    }
    temp = firstele->next;
    firstele->next = secondele->next;
    secondele->next = temp;
    return 
}

int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        node *head = takeinput();
        int i, j;
        cin >> i >> j;
        head = swapnodes(head, i, j);
        printnode(head);
        t--;
    }
    return 0;
}