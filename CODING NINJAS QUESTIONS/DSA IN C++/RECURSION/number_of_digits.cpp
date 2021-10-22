#include <iostream>
using namespace std;

int noofdigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = noofdigits(n / 10);
    ans++;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int ans = noofdigits(n);
    cout << ans;
    return 0;
}
