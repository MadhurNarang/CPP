#include <iostream>
using namespace std;

int multiplication(int m, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int stepaddition = m + multiplication(m, n - 1);
    return stepaddition;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int ans = multiplication(m, n);
    cout << ans << endl;
}