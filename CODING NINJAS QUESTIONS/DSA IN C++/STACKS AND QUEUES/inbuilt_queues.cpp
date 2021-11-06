#include <iostream>
using namespace std;
#include <queue>

int main()
{
    queue<int> s;

    int q, t, ele;
    cin >> q;
    while (q > 0)
    {
        cin >> t;
        switch (t)
        {
        case 1:
            cin >> ele;
            s.push(ele);
            break;
        case 2:
            cout << s.front();
            s.pop();
            break;
        case 3:
            cout << s.front();
            break;
        case 4:
            cout << s.size();
            break;
        case 5:
            if (s.empty())
                cout << "TRUE";
            else
                cout << "FALSE";
            break;
        }
        q--;
    }
    return 0;
}