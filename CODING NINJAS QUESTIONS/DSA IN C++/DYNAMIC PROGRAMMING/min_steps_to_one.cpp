#include <iostream>
#include <climits>
using namespace std;

int min_steps_recursion(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    int steps = 1, a = INT_MAX, b = INT_MAX, c = INT_MAX;

    if (n % 3 == 0)
    {
        a = min_steps_recursion(n / 3);
    }

    if (n % 2 == 0)
    {
        b = min_steps_recursion(n / 2);
    }

    c = min_steps_recursion(n - 1);

    steps += min(a, min(b, c));

    return steps;
}

int min_steps_memoization_helper(int n, int *arr)
{
    if (n <= 1)
    {
        return 0;
    }

    if (arr[n] != -1)
    {
        return arr[n];
    }

    int steps = 1, a = INT_MAX, b = INT_MAX, c = INT_MAX;

    if (n % 3 == 0)
    {
        a = min_steps_recursion(n / 3);
    }

    if (n % 2 == 0)
    {
        b = min_steps_recursion(n / 2);
    }

    c = min_steps_recursion(n - 1);

    steps += min(a, min(b, c));

    arr[n] = steps;

    return steps;
}

int min_steps_memoization(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    return min_steps_memoization_helper(n, arr);
}

int min_steps_dp(int n)
{
    int *arr = new int[n + 1];

    arr[0] = 0;
    arr[1] = 0;
    int minsteps;

    for (int i = 2; i <= n; i++)
    {
        minsteps = arr[i - 1];

        if (i % 3 == 0)
        {
            minsteps = min(minsteps, arr[i / 3]);
        }
        if (i % 2 == 0)
        {
            minsteps = min(minsteps, arr[i / 2]);
        }

        arr[i] = minsteps + 1;
    }

    return arr[n];
}

int main()
{
    int n;
    cin >> n;

    cout << min_steps_recursion(n) << endl;
    cout << min_steps_memoization(n) << endl;
    cout << min_steps_dp(n) << endl;
}