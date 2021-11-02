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

int length(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    head = head->next;
    int smalllen = length(head);
    smalllen++;
    return smalllen;
}

node *bubblesort(node*head,int n)
{
    node*temp=head;
    int val;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++,temp=temp->next)
        {
            if(temp->data>(temp->next)->data)
            {
                val=temp->data;
                temp->data=(temp->next)->data;
                (temp->next)->data=val;
            }
        }
        temp=head;
    }
    
    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        node *head = takeinput();
        int listsize=length(head);
        head = bubblesort(head,listsize);
        printnode(head);
        cout<<endl;
        t--;
    }
    return 0;
}