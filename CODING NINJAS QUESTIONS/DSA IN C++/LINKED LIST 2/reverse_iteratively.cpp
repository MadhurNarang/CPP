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

int main()
{
    int n;
    cin>>n;
    while(n!=0)
    { 
        node * head = takeinput();
        head=reverselist(head);
        printnode(head);
        cout<<endl;
        n--;
    }
    return 0;
}