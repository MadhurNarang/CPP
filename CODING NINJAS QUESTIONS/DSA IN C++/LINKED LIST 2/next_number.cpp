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

node * nextnum(node * head,node * prevhead)
{
    if(head==NULL)
    {
        //return new node(0);
        return head;
    }
    
    int temp;
    if(head->next!=NULL)
        temp = head->next->data;
    //else temp=-1;

    node * nextnode = nextnum(head->next,prevhead);

    if((head->next==NULL)||(nextnode->data!=temp && nextnode->data == 0 ))    //HERE ORDER OF CONDITION MATTERS SINCE IF FIRST STATEMENT IS TRUE THEN SECOND WILL NOT BE TAKEN CARE OF .......SINCE FOR OR IF ONE IS TRUE THEN WHOLE CONDISTION IS AUTOMATICALLY TRUE
    {                                                                           // THIS IS DONE BECAUSE WE CANT DO nextnode->data when nextnode is NULL .....it will give segmentationfault
        if(head->data==9)
        {
            head->data=0;
            if(head==prevhead)
            {
                node * newnode=new node(1);
                newnode->next=head;
                head=newnode;
            }
        }
        else
            head->data+=1;
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
        head= nextnum(head,head);
        printnode(head);
        cout<<endl;
        t--;
    }
    return 0;
}