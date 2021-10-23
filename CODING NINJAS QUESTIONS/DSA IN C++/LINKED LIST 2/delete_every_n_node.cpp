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

bool nodecheck(node * head)
{
    if(head!=NULL)
    {
        return false;
    }
    else 
    {
        return true;
    }
}

node * deletennodes(node *head,int m,int n)
{
    if(m==0)
    {
        return NULL;
    }
    node * newhead=head,*newtail=head;
    while(nodecheck(head)==false)
    {
    for(int i=0;i<m;i++)
    {
        if(nodecheck(head))
        {
            newtail->next=NULL;
            return newhead;
        }
        newtail=head;
        head=head->next;
    }

    for(int i=0;i<n;i++)
    {
        if(nodecheck(head))
        {
            newtail->next=NULL;
            return newhead;
        }
        head=head->next;
    }
    newtail->next=head;
    }
    return newhead;
}

int main()
{
    int n1;
    cin>>n1;
    while(n1!=0)
    { 
        node * head = takeinput();
        int m,n;
        cin>>m>>n;
        head=deletennodes(head,m,n);
        printnode(head);
        n1--;
    }
    return 0;
}