#include <iostream>
using namespace std;

int fibo_recursion(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int a = fibo_recursion(n - 1);
    int b = fibo_recursion(n - 2);

    return a + b;
}

int fibo_memoization_helper(int n, int *arr)
{
    if (n <= 1)
    {
        return n;
    }

    //check if output already exists
    if (arr[n] != -1)
    {
        return arr[n];
    }

    int a = fibo_memoization_helper(n - 1, arr);
    int b = fibo_memoization_helper(n - 2, arr);

    //saving values for future use
    arr[n] = a + b;

    return a + b;
}

int fibo_memoization(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    return fibo_memoization_helper(n, arr);
}

int fibo_dp(int n)
{
    int *arr = new int[n + 1];

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}

int main()
{
    int n;
    cin >> n;

    cout << fibo_recursion(n) << endl;
    cout << fibo_memoization(n) << endl;
    cout << fibo_dp(n) << endl;
}