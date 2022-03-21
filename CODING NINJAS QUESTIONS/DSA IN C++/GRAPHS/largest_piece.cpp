#include <iostream>
#include <string>
using namespace std;

int ones(int **input, int i, int j, int n, bool **visited)
{
    if (i < 0 || i > n - 1 || j < 0 || j > n - 1)
    {
        return 0;
    }

    if (visited[i][j])
    {
        return 0;
    }

    if (input[i][j] != 1)
    {
        return 0;
    }

    visited[i][j] = true;

    int smallans = 1;

    smallans += ones(input, i - 1, j, n, visited);

    smallans += ones(input, i, j + 1, n, visited);

    smallans += ones(input, i + 1, j, n, visited);

    smallans += ones(input, i, j - 1, n, visited);

    visited[i][j] = false;

    return smallans;
}

void checkmax(int **input, int n)
{
    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (input[i][j] == 1)
            {
                ans = max(ans, ones(input, i, j, n, visited));
            }
        }
    }

    cout << ans << endl;
    return;
}

int main()
{
    int n;
    cin >> n;

    int **input = new int *[n];
    for (int i = 0; i < n; i++)
    {
        input[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
    }

    checkmax(input, n);
}