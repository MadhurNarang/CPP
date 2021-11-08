#include<iostream>
using namespace std;
#include<stack>
#include<string>

bool redundantbrackets(string q)
{
    int i=0;
    stack<char> s;
    while(q[i]!='\0')
    {
        if(q[i]=='('||q[i]=='+'||q[i]=='-'||q[i]=='*'||q[i]=='/')
        {
            s.push(q[i]);
        }
        if(q[i]==')')
        {
            if(s.top()=='(')
            {
                return true;
            }
            else
            {
                while(s.top()!='(')
                {
                    s.pop();
                }
                s.pop();
            }
        }
        i++;
    }
    return false;
}

int main()
{
    int t;
    string q;
    cin>>t;
    while(t>0)
    {
        cin>>q;
        cout<<redundantbrackets(q);
        t--;
    }
}


/*  in this method we need to skip next to ")" after coming from recursion call.......but i have not done it 
#include<iostream>
using namespace std;
#include<stack>
#include<string>

bool redundantbrackets(string q)
{
    int i=0,count=0;
    bool smallans=0;
    while(q[i]!='\0')
    {
        if(q[i]=='(')
        {
            smallans = redundantbrackets(q.substr(i+1));
        }
        if((q[i]=='+')||(q[i]=='-')||(q[i]=='*')||(q[i]=='/'))
        {
            count++;
        }
        if(q[i]==')')
        {
            cout<<"hello";
            if(smallans==1)
                return true;
            else if(count==0)
            {
                return true;
            }
            else
            {
                return false;
            }   
        }
        i++;
    }

    if(smallans==1)
        return true;
    else 
        if(count==0)
        {
            return true;
        }
        else
        {
            return false;
        }
}

int main()
{
    int t;
    string q;
    cin>>t;
    while(t>0)
    {
        cin>>q;
        cout<<redundantbrackets(q);
        t--;
    }
}
*/