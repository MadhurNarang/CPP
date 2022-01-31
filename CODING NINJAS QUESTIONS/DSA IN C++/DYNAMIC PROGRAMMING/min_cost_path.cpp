#include <iostream>
#include <climits>
using namespace std;

int mincost_recursion(int **arr, int m, int n, int i = 0, int j = 0)
{
    if (i == m - 1 && j == n - 1)
    {
        return arr[i][j];
    }
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }

    int step1 = mincost_recursion(arr, m, n, i + 1, j + 1);

    int step2 = mincost_recursion(arr, m, n, i + 1, j);

    int step3 = mincost_recursion(arr, m, n, i, j + 1);

    int mincount = min(step1, min(step2, step3));

    return mincount + arr[i][j];
}

int mincost_memoization(int **arr, int m, int n, int i, int j, int **ans)
{
    if (i == m - 1 && j == n - 1)
    {
        return arr[i][j];
    }
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }

    if (ans[i][j] != -1)
    {
        return ans[i][j];
    }

    int step1 = mincost_memoization(arr, m, n, i + 1, j + 1, ans);

    int step2 = mincost_memoization(arr, m, n, i + 1, j, ans);

    int step3 = mincost_memoization(arr, m, n, i, j + 1, ans);

    int mincount = min(step1, min(step2, step3));

    ans[i][j] = mincount + arr[i][j];

    return mincount + arr[i][j];
}

int mincost_memoization_helper(int **arr, int m, int n)
{
    int **ans = new int *[m];

    for (int i = 0; i < m; i++)
    {
        int *arrin = new int[n];
        for (int j = 0; j < n; j++)
        {
            arrin[j] = -1;
        }
        ans[i] = arrin;
    }

    return mincost_memoization(arr, m, n, 0, 0, ans);
}

int mincost_dp(int *arr, int m, int n)
{
}

int main()
{
    int m, n;
    cin >> m >> n;
    int **arr = new int *[m];

    for (int i = 0; i < m; i++)
    {
        int *arrin = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arrin[j];
        }
        arr[i] = arrin;
    }

    cout << mincost_recursion(arr, m, n) << endl;
    cout << mincost_memoization_helper(arr, m, n) << endl;
}