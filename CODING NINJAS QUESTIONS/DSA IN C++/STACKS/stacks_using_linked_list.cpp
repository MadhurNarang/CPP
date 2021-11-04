#include<iostream>
#include<climits>
using namespace std;

class node
{
    public :

    int data;
    node *next;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

class stack
{
    private :
    node *head;
    int size;

    public :

    stack()
    {
        head==NULL;
        size=0;
    }

    int getsize()
    {
        return size;
    }

    int top()
    {
        if(head==NULL)
        {
            cout<<"STACK EMPTY"<<endl;
            return INT_MIN;
        }
        else
            return head->data;
    }

    bool isempty()
    {
        return head==NULL;
    }

    void push(int ele)
    {
        if(head==NULL)
        {
            head=new node(ele);
        }
        else
        {
            node *newnode = new node(ele);
            newnode->next=head;
            head=newnode;
        }
        size++;
    }

    int pop()
    {
        if(head==NULL)
        {
            cout<<"STACK EMPTY"<<endl;
            return INT_MIN;
        }
        else
        {
            int temp =head->data;
            node *tempnext=head->next;
            delete head;
            head=tempnext;
            size--;
            return temp;
        }
    }
};


int main()
{
    stack s;

    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    s.push(105);
    s.push(106);

    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.isempty()<<endl;
    cout<<s.getsize()<<endl;
    
    return 0;
}