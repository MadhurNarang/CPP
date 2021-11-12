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

node * nextnum(node * head,node * prevhead)
{
    if(head==NULL)
    {
        return new node(0);
    }
    
    int temp;
    if(head->next!=NULL)
        temp = head->next->data;
    else temp=-1;

    node * nextnode = nextnum(head->next,prevhead);

    if(nextnode->data!=temp && nextnode->data == 0)
    {
        if(head->data==9)
        {
            head->data=0;
            if(head==prevhead)
            {
                node * newnode=new node(1);
                newnode->next=head;
                head=newnode;
            }
        }
        else
            head->data+=1;
    }
    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        node *head = takeinput();
        head= nextnum(head,head);
        printnode(head);
        t--;
    }
    return 0;
}