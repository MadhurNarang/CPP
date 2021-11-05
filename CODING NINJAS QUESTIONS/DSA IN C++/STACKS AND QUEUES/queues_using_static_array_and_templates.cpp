#include<iostream>
using namespace std;

template<typename T>
class queue
{
    private :
    T* data;
    int findex;
    int nindex;
    int size;
    int capacity;

    public :
    queue(int n)
    {
        data=new T[n];
        findex=-1;
        nindex=0;
        size=0;
        capacity=n;
    }

    bool isempty()
    {
        return size==0;
    }

    int getsize()
    {
        return size;
    }

    T front()
    {
        if(size==0)
        {
            cout<<"QUEUE EMPTY"<<endl;
            return 0;
        }
        return data[findex];
    }

    void enqueue(T ele)
    {
        if(size==capacity)
        {
            cout<<"QUEUE FULL"<<endl;
            return;
        }
        if(findex==-1)
        {
            findex=0;
        }
        data[nindex]=ele;
        nindex=(nindex+1)%capacity;
        size++;
    }

    T dequeue()
    {
        if(size==0)
        {
            cout<<"QUEUE EMPTY"<<endl;
            return 0;
        }
        T tempdata=data[findex];
        findex=(findex+1)%capacity;
        size--;
        if(size==0)       //THIS CAN ALSO BE THE CONDITION(findex==nindex)
        {
            findex=-1;
            nindex=0;
        }
        return tempdata;
    }
};

int main()
{
    queue<int> s(5);

    int q,t,ele;
    cin>>q;
    while(q>0)
    {
        cin>>t;
        switch(t)
        {
            case 1 :
                    cin>>ele;
                    s.enqueue(ele);
                    break;
            case 2 :
                    cout<<s.dequeue();
                    break;
            case 3 :
                    cout<<s.front();
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