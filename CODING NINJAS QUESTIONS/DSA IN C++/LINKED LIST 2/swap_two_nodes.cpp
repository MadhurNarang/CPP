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

node *swapnodes(node *head,int i,int j)
{
    node *prevnode1,*prevnode2,*currnode1,*currnode2,*temp=head,*newhead=head,*tempcurrnodenext;
    int diff = j-i;
    if(i==j)
    {
        return head;
    }
    if(i==0)
    {
        prevnode1=NULL;
        currnode1=head;
    }
    if(j==0)
    {
        prevnode2=NULL;
        currnode2=head;
    }
    while((i!=0||j!=0)&&(temp->next!=NULL))
    {
        if(i!=0)
        {
            currnode1=temp->next;
            prevnode1=temp;
            i--;
        }
        if(j!=0)
        {
            currnode2=temp->next;
            prevnode2=temp;
            j--;
        }
        temp=temp->next;
    }
    if(i!=0||j!=0)
    {
        return head;
    }
    else
    {
        if(prevnode1!=NULL)
        {
            prevnode1->next=currnode2;
        }
        tempcurrnodenext=currnode2->next;
        if(diff==1)
        {
            currnode2->next=currnode1;
        }
        else
            currnode2->next=currnode1->next;

        if(prevnode2!=NULL)
        {
            prevnode2->next=currnode1;
        }
        currnode1->next=tempcurrnodenext;
    }
    if(prevnode1==NULL)
    {
        newhead=currnode2;
    }
    else if(prevnode2==NULL)
    {
        newhead=currnode1;
    }

    return newhead;
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
        if(i<j)
            head = swapnodes(head, i, j);
        else 
            head=swapnodes(head,j,i);
        printnode(head);
        t--;
    }
    return 0;
}