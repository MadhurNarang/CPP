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

node* returntail (node *head,node*head2=NULL)
{
    while(head->next!=head2)
    {
        head=head->next;
    }
    return head;
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

node * mergesort(node*head)
{
    if(head->next==NULL)
    {
        return head;
    }

    node *temp=midpointnode(head);
    node *midhead=temp->next;
    temp->next=NULL;

    node * p1 = mergesort(head);
    node * p2 = mergesort(midhead);

    node *mergedhead=mergelistswithoutspace(p1,p2);
    return mergedhead;
}

int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {
        int N;
        node * head = takeinput();
        node * mergedhead = mergesort(head);
        printnode(mergedhead);
        cout<<endl;
        n--;
    }
    return 0;
}