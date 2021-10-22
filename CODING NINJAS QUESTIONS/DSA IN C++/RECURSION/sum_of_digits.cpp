#include <iostream>
using namespace std;

int sumofdigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int smallsum = (n % 10) + sumofdigits(n / 10);
    return smallsum;
}

int main()
{
    int n;
    cin >> n;
    int ans = sumofdigits(n);
    cout << ans;
    return 0;
}