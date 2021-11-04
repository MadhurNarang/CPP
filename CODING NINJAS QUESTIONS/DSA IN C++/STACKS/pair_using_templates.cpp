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
    Pair <int,double> p1;
    p1.setfirst(20.12);
    p1.setsecond(20.12);

    cout<<p1.getfirst()<<endl<<p1.getsecond()<<endl;
    return 0;
}