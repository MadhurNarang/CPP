#include<iostream>
#include<climits>
using namespace std;

template <typename Q>

class stack
{
    private :

    Q * data;
    int nextele;
    int capacity;


    public :

    stack()
    {
        data=new Q[5];
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

    Q top()
    {
        if(isempty())
        {
            cout<<"STACK EMPTY"<<endl;
            return 0;
        }
        return data[nextele-1];
    }

    void push(Q ele)
    {
        if(nextele==capacity)
        {
            Q *newdata=new Q[2*capacity];
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

    Q pop()
    {
        if(isempty())
        {
            cout<<"STACK EMPTY"<<endl;
            return 0;        
        }
        nextele--;
        return data[nextele];
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
    s.pop();

    cout<<s.top()<<endl;
    cout<<s.isempty()<<endl;
    cout<<s.size()<<endl;
}