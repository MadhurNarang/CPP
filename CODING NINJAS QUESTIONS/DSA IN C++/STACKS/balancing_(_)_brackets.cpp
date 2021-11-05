#include<iostream>
using namespace std;
#include<stack>
#include<string>

bool checkbrackets(string q)
{
    int i=0;
    stack<char> s;
    while(q[i]!='\0')
    {
        if(q[i]=='(')
        {
            s.push('(');
        }
        if(q[i]==')')
        {
            if(!s.empty())
            {
                char ch=s.top();
                if(ch=='(')
                {
                    s.pop();
                }
            }
            else
            {
                return false;
            }
        }
        i++;
    }
    if(!s.empty())
    {
        return false;
    }
    return true;
}

int main()
{
    int t;
    string q;
    cin>>t;
    while(t>0)
    {
        cin>>q;
        cout<<checkbrackets(q);
        t--;
    }
}