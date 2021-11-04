#include<iostream>
using namespace std;

template<typename Q>
class node
{
    public :

    Q data;
    node<Q> *next;

    node(Q data)
    {
        this->data=data;
        this->next=NULL;
    }
};
template<typename Q>
class stack
{
    private :
    node<Q> *head;
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

    Q top()
    {
        if(head==NULL)
        {
            cout<<"STACK EMPTY"<<endl;
            return 0;
        }
        else
            return head->data;
    }

    bool isempty()
    {
        return head==NULL;
    }

    void push(Q ele)
    {
        if(head==NULL)
        {
            head=new node<Q>(ele);
        }
        else
        {
            node<Q> *newnode = new node<Q>(ele);
            newnode->next=head;
            head=newnode;
        }
        size++;
    }

    Q pop()
    {
        if(head==NULL)
        {
            cout<<"STACK EMPTY"<<endl;
            return 0;
        }
        else
        {
            Q temp =head->data;
            node<Q> *tempnext=head->next;
            delete head;
            head=tempnext;
            size--;
            return temp;
        }
    }
};


int main()
{
    stack<char> s;

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