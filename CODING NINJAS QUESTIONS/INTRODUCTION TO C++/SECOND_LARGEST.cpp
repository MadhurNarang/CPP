#include <iostream>
using namespace std;

int main()
{
    int pre, cur, i, n, smax = -2147483648, max = -2147483648;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> cur;

        if(cur==max)
            continue;
        else if(cur>max)
        {
            smax = max;
            max = cur;
        }
        else if(cur>smax)
            smax = cur;
    }
    cout << smax;
}