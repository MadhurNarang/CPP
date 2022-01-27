#include <iostream>
using namespace std;

int staircase_recursion(int n)
{
    if (n <= 2)
    {
        return n;
    }

    if (n == 3)
    {
        return 4;
    }

    int ways = staircase_recursion(n - 1) + staircase_recursion(n - 2) + staircase_recursion(n - 3);

    return ways;
}

int staircase_memoization_helper(int n, int *arr)
{
    if (n <= 2)
    {
        return n;
    }

    if (n == 3)
    {
        return 4;
    }

    if (arr[n] != -1)
    {
        return arr[n];
    }

    int ways = staircase_memoization_helper(n - 1, arr) + staircase_memoization_helper(n - 2, arr) + staircase_memoization_helper(n - 3, arr);
    arr[n] = ways;

    return ways;
}

int staircase_memoization(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    return staircase_memoization_helper(n, arr);
}

int staircase_dp(int n)
{
    int *arr = new int[n + 1];

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for (int i = 4; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }

    return arr[n];
}

int main()
{
    int n;
    cin >> n;

    cout << staircase_recursion(n) << endl;
    cout << staircase_memoization(n) << endl;
    cout << staircase_dp(n) << endl;
}