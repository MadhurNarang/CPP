#include <iostream>
#include <cmath>
using namespace std;

int nobalanced_recursion(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    int x = nobalanced_recursion(n - 1);
    int y = nobalanced_recursion(n - 2);

    int mod = (int)(pow(10, 9)) + 7;

    int temp1 = (int)((long)(x)*x) % mod;
    int temp2 = (int)(2 * (long)(x)*y) % mod;

    int nobalanced = (temp1 + temp2) % mod;

    return nobalanced;
}

int nobalanced_memoization(int n, int *arr)
{
    if (n <= 1)
    {
        return 1;
    }

    if (arr[n] != -1)
    {
        return arr[n];
    }

    int x = nobalanced_recursion(n - 1);
    int y = nobalanced_recursion(n - 2);

    int mod = (int)(pow(10, 9)) + 7;

    int temp1 = (int)((long)(x)*x) % mod;
    int temp2 = (int)(2 * (long)(x)*y) % mod;

    int nobalanced = (temp1 + temp2) % mod;

    arr[n] = nobalanced;

    return nobalanced;
}

int nobalanced_memoization_helper(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    return nobalanced_memoization(n, arr);
}

int nobalanced_dp(int n)
{
    int *arr = new int[n + 1];

    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int x = arr[i - 1];
        int y = arr[i - 2];

        int mod = (int)(pow(10, 9)) + 7;

        int temp1 = (int)((long)(x)*x) % mod;
        int temp2 = (int)(2 * (long)(x)*y) % mod;

        int nobalanced = (temp1 + temp2) % mod;
        arr[i] = nobalanced;
    }

    return arr[n];
}

int main()
{
    int n;
    cin >> n;

    cout << nobalanced_recursion(n) << endl;
    cout << nobalanced_memoization_helper(n) << endl;
    cout << nobalanced_dp(n) << endl;
}
