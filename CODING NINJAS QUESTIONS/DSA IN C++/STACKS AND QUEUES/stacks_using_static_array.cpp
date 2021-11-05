#include<iostream>
#include<climits>
using namespace std;

class stack
{
    private :

    int * data;
    int nextele;
    int capacity;


    public :

    stack(int totalsize)
    {
        data=new int[totalsize];
        nextele=0;
        capacity=totalsize;
    }

    int size()
    {
        return nextele;
    }

    bool isempty()
    {
        return nextele==0;
    }

    int top()
    {
        if(isempty())
        {
            cout<<"STACK EMPTY"<<endl;
            return INT_MIN;
        }
        return data[nextele-1];
    }

    void push(int ele)
    {
        if(nextele==capacity)
        {
            cout<<"STACK FULL"<<endl;
            return;
        }
        data[nextele]=ele;
        nextele++;
    }

    int pop()
    {
        if(isempty())
        {
            cout<<"STACK EMPTY"<<endl;
            return INT_MIN;        
        }
        nextele--;
        return data[nextele];
    }
};

int main()
{
    stack s(5);

    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();

    cout<<s.top()<<endl;
    cout<<s.isempty()<<endl;
    cout<<s.size()<<endl;
}