#include<iostream>
using namespace std;

class node
{
    public :
    int data;
    node * next;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

node* takeinput()
{
    int data;
    node *head  = NULL,*tail = NULL;
    cin>>data;
    while(data!=-1)
    {
        node *newnode = new node(data);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}

void printnode(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}

node * evenafterodd(node*head)
{
    node *evenhead=NULL,*oddhead=NULL,*eventail=NULL,*oddtail=NULL,*nextadd=NULL;
    while(head!=NULL)
    {
        nextadd=head->next;
        if(head->data %2==0)
        {
            if(evenhead==NULL)
            {
                evenhead=head;
                eventail=head;
            }
            else
            {
                eventail->next=head;
                eventail=head;
            }
        }
        else
        {
            if(oddhead==NULL)
            {
                oddhead=head;
                oddtail=head;
            }
            else
            {
                oddtail->next=head;
                oddtail=head;
            }
        }
        head=nextadd;
    }
    if(oddhead!=NULL)
        oddtail->next=NULL;
    if(evenhead!=NULL)
        eventail->next=NULL;
    if(oddhead!=NULL)
        oddtail->next=evenhead;
    if(oddhead!=NULL)
        return oddhead;
    else
        return evenhead;
}

int main()
{
    int n;
    cin>>n;
    while(n!=0)
    { 
        node * head = takeinput();
        head=evenafterodd(head);
        printnode(head);
        cout<<endl;
        n--;
    }
    return 0;
}