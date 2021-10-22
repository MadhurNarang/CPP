#include <iostream>
using namespace std;

int xpown(int x, int n)
{
    if (n == 1)
        return x;
    int smalloutput = xpown(x, n - 1);
    int ans = x * smalloutput;
    return ans;
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << xpown(x, n) << endl;
}