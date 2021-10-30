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

node * reverselist(node *head,node *tail = NULL)
{
    node * temp =head;
    node*prevadd=NULL,*currnext;
    while(temp!=tail)
    {
        currnext=temp->next;
        temp->next=prevadd;
        prevadd=temp;
        temp=currnext;
    }
    return prevadd;
}

bool nodecheck(node * temp)
{
    if(temp!=NULL)
    {
        return false;
    }
    else 
    {
        return true;
    }
}

node *k_rev(node *head,int k)
{
    node * swaphead=head,*swaptail=NULL,*newhead=NULL,*newtail=NULL;
    while(nodecheck(head)==false)
    {
        for(int i=1;i<k;i++)
        {
            if(nodecheck(head))
            {
                
            }
            head=head->next;
        }
        swaptail=head->next;
        newtail=head;
        if(newhead==NULL)
        {
            newhead=reverselist(swaphead,swaptail);
        }
        else
        {
            newtail->next=reverselist(swaphead,swaptail);
        }
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
        int k;
        cin>>k;
        head=k_rev(head,k);
        printnode(head);
        t--;
    }
    return 0;
}