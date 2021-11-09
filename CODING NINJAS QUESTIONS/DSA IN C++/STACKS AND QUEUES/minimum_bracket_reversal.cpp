#include <iostream>
using namespace std;
#include <stack>
#include <string>

int reversebrackets(string q)
{
    int i = 0,rev=0;
    stack<char> s;
    while (q[i] != '\0')
    {
        if (q[i] == '{')
        {
            s.push(q[i]);
        }
        if (q[i] == '}')
        {
            if (!s.empty())
            {
                char ch = s.top();
                if (ch == '{')
                {
                    s.pop();
                }
            }
            else
            {
                s.push('{');
                rev++;
            }
        }
        i++;
    }

    while(s.size()>1)
    {
        if(s.top()=='{')
        {
            s.pop();
            if(s.top()=='{')
            {
                s.pop();
            }
            rev++;
        }
    }

    if (!s.empty())
    {
        return -1;
    }
    else
    {
        return rev;
    }
}

int main()
{
    int t;
    string q;
    cin >> t;
    while (t > 0)
    {
        cin >> q;
        cout << reversebrackets(q)<<endl;
        t--;
    }
}