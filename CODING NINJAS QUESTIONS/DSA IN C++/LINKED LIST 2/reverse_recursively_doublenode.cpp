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

class nodepair
{
    public:
    node * head;
    node *tail;
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

nodepair reverselist_better(node *head)
{
    if(head->next==NULL)
    {
        nodepair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }

    nodepair smallpair = reverselist_better(head->next);
    
    (smallpair.tail)->next=head;
    head->next=NULL;
    smallpair.tail=head;
    return smallpair;
}

node * returnreversehead(node*head)
{
    return reverselist_better(head).head;
}

int main()
{
    int n;
    cin>>n;
    while(n!=0)
    { 
        node * head = takeinput();
        head=returnreversehead(head);
        printnode(head);
        cout<<endl;
        n--;
    }
    return 0;
}