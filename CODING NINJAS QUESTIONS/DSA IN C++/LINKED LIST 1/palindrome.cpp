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

node * reverselist(node *head)
{
    node * temp =head;
    node*prevadd=NULL,*currnext;
    while(temp!=NULL)
    {
        currnext=temp->next;
        temp->next=prevadd;
        prevadd=temp;
        temp=currnext;
    }
    return prevadd;
}

bool palindrome(node *head,node*halflist)
{
    while(head->next!=NULL && halflist->next!=NULL)
    {
        if(head->data!=halflist->data)
        {
            return false;
        }
        head=head->next;
        halflist=halflist->next;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {
        node * head = takeinput();
        node *halflist=midpointnode(head)->next;
        midpointnode(head)->next=NULL;
        halflist=reverselist(halflist);
        bool ans = palindrome(head,halflist);
        if(ans)
        {
            cout<<"PALINDROME";
        }
        else
        cout<<"NOT PALINDROME";
        n--;
    }
    return 0;
}