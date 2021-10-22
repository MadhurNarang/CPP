#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int previous = fibonacci(n - 1);
    int preprevious = fibonacci(n - 2);
    return previous + preprevious;
}

int main()
{
    int n;
    cin >> n;
    int ans = fibonacci(n);
    cout << ans << endl;
}
