#include <iostream>
using namespace std;

int main()
{
    int x, y, ans = 1;
    cin >> x >> y;
    for (int i = 0; i < y; i++)
    {
        ans *= x;
    }
    cout << ans << endl;
    return 0;
}