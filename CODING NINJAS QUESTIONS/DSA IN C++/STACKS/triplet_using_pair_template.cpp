#include<iostream>
using namespace std;
template <typename Q, typename W>

class Pair
{
    private :
    Q first;
    W second;

    public :
    
    void setfirst(Q first)
    {
        this->first=first;
    }

    Q getfirst()
    {
        return this->first;
    }

    void setsecond(W second)
    {
        this->second=second;
    }

    W getsecond()
    {
        return this->second;
    }
};


int main()
{
    Pair <Pair<int,char>,double> p1;
    Pair <int,char> p2;
    p2.setfirst(20);
    p2.setsecond('a');
    p1.setfirst(p2);
    p1.setsecond(20.12);

    cout<<p1.getfirst().getfirst()<<endl<<p1.getfirst().getsecond()<<endl<<p1.getsecond()<<endl;
    return 0;
}