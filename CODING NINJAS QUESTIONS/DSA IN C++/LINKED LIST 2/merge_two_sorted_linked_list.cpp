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

node* midpointnode(node *head)
{
    node*slow=head;
    node*fast =head-> next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node * mergelistswithspace(node*head1,node*head2)
{
    node *finalhead=NULL,*finaltail=NULL;
    if(head1->data<head2->data)
    {
        finalhead=new node(head1->data);
        head1=head1->next;
    }
    else
    {
        finalhead=new node(head2->data);
        head2=head2->next;
    }
    finaltail=finalhead;
    
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            finaltail->next=new node(head1->data);
            finaltail=finaltail->next;
            head1=head1->next;
        }
        else
        {
            finaltail->next=new node(head2->data);
            finaltail=finaltail->next;
            head2=head2->next;
        }
    }
    while(head1!= NULL)
    {
        finaltail->next=new node(head1->data);
        finaltail=finaltail->next;
        head1=head1->next;
    }
    while(head2!= NULL)
    {
        finaltail->next=new node(head2->data);
        finaltail=finaltail->next;
        head2=head2->next;
    }
    return finalhead;
}

node * mergelistswithoutspace(node*head1,node*head2)
{
    node *finalhead=NULL,*finaltail=NULL;
    if(head1->data<head2->data)
    {
        finalhead=head1;
        head1=head1->next;
    }
    else
    {
        finalhead=head2;
        head2=head2->next;
    }
    finaltail=finalhead;
    
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            finaltail->next=head1;
            finaltail=finaltail->next;
            head1=head1->next;
        }
        else
        {
            finaltail->next=head2;
            finaltail=finaltail->next;
            head2=head2->next;
        }
    }
    while(head1!= NULL)
    {
        finaltail->next=head1;
        finaltail=finaltail->next;
        head1=head1->next;
    }
    while(head2!= NULL)
    {
        finaltail->next=head2;
        finaltail=finaltail->next;
        head2=head2->next;
    }
    return finalhead;
}

int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {
        int N;
        node * head1 = takeinput();
        node *head2=takeinput();
        node *head3 =mergelistswithspace(head1,head2);
        node *head4 =mergelistswithspace(head1,head2);
        printnode(head3);
        cout<<endl;
        printnode(head4);
        cout<<endl;
        n--;
    }
    return 0;
}