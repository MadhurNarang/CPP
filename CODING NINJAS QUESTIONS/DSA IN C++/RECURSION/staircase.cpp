#include <iostream>
using namespace std;

int staircase(int n, int output = 0)
{
    if (output > n)
        return 0;
    if (output == n)
        return 1;

    int ans1 = staircase(n, output + 1);
    int ans2 = staircase(n, output + 2);
    int ans3 = staircase(n, output + 3);

    return ans1 + ans2 + ans3;
}

int main()
{
    int n;
    cin >> n;
    int ans = staircase(n);
    cout << ans << endl;
    return 0;
}