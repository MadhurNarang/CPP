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

    stack()
    {
        data=new int[5];
        nextele=0;
        capacity=5;
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
            int *newdata=new int[2*capacity];
            for(int i=0;i<capacity;i++)
            {
                newdata[i]=data[i];
            }
            delete []data;
            capacity=capacity*2;
            data=newdata;
        }
        data[nextele]=ele;
        nextele++;
        return;
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
    stack s;

    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.pop();

    cout<<s.top()<<endl;
    cout<<s.isempty()<<endl;
    cout<<s.size()<<endl;
}