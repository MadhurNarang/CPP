#include<iostream>
using namespace std;

int main()
{
    int a =5;
    int &b=a;
    int *c=&a;
    cout<<sizeof(c);
    return 0;
}