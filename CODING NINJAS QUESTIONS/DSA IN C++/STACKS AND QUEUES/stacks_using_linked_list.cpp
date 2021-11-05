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

    int q,t,ele;
    cin>>q;
    while(q>0)
    {
        cin>>t;
        switch(t)
        {
            case 1 :
                    cin>>ele;
                    s.push(ele);
                    break;
            case 2 :
                    cout<<s.pop();
                    break;
            case 3 :
                    cout<<s.top();
                    break;
            case 4 :
                    cout<<s.getsize();
                    break;
            case 5 :
                    if(s.isempty())
                        cout<<"TRUE";
                    else
                        cout<<"FALSE";
                    break;
        }
        q--;
    }
    return 0;
}