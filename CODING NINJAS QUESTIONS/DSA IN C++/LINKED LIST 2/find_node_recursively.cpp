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

int findnode(node *head,int n)
{
    if(head->data==n)
    {
        return 0;
    }
    if(head->next==NULL)
    {
        return -1;
    }

    int smallpos=findnode(head->next,n);

    if(smallpos==-1)
    {
        return -1;
    }
    else
    {
        return ++smallpos;
    }
}

int main()
{
    int n;
    cin>>n;
    while(n!=0)
    { 
        node * head = takeinput();
        int N;
        cin>>N;
        cout<<findnode(head,N);
        cout<<endl;
        n--;
    }
    return 0;
}