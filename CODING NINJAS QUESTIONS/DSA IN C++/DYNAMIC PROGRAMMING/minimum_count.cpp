#include <iostream>
#include <climits>
#include <math.h>
using namespace std;

int mincount_recursion(int n)
{
    if (n <= 3)
    {
        return n;
    }

    int mincount = INT_MAX;
    for (int i = 1; i <= sqrt(n); i++)
    {
        mincount = min(mincount, mincount_recursion(n - (i * i)) + 1);
    }

    return mincount;
}

int mincount_memoization(int n, int *arr)
{
    if (n <= 3)
    {
        return n;
    }

    if (arr[n] != -1)
    {
        return arr[n];
    }

    int mincount = INT_MAX;
    for (int i = 1; i <= sqrt(n); i++)
    {
        mincount = min(mincount, mincount_recursion(n - (i * i)) + 1);
    }

    arr[n] = mincount;

    return mincount;
}

int mincount_memoization_helper(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    return mincount_memoization(n, arr);
}

int mincount_dp(int n)
{
    int *arr = new int[n + 1];

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int mincount = INT_MAX;
        for (int j = 1; j <= sqrt(i); j++)
        {
            mincount = min(mincount, arr[i - (j * j)] + 1);
        }

        arr[i] = mincount;
    }

    return arr[n];
}

int main()
{
    int n;
    cin >> n;

    cout << mincount_recursion(n) << endl;
    cout << mincount_memoization_helper(n) << endl;
    cout << mincount_dp(n) << endl;
}