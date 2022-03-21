#include <iostream>
#include <string>
using namespace std;

bool cycles(char **input, int i, int j, int n, int m, bool **visited, int k, char c, int si, int sj)
{
    if (si == i && sj == j && k >= 4)
    {
        return true;
    }

    if (i < 0 || i > n - 1 || j < 0 || j > m - 1)
    {
        return false;
    }

    if (visited[i][j])
    {
        return false;
    }

    if (input[i][j] != c)
    {
        return false;
    }

    visited[i][j] = true;

    bool smallans = false;

    smallans = smallans || cycles(input, i - 1, j, n, m, visited, k + 1, c, si, sj);

    smallans = smallans || cycles(input, i, j + 1, n, m, visited, k + 1, c, si, sj);

    smallans = smallans || cycles(input, i + 1, j, n, m, visited, k + 1, c, si, sj);

    smallans = smallans || cycles(input, i, j - 1, n, m, visited, k + 1, c, si, sj);

    visited[i][j] = false;

    return smallans;
}

void checkcycle(char **input, int n, int m)
{
    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool smallans = cycles(input, i, j, n, m, visited, 0, input[i][j], i, j);
            if (smallans)
            {
                cout << "true" << endl;
                return;
            }
        }
    }

    cout << "false" << endl;
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;

    char **input = new char *[n];
    for (int i = 0; i < n; i++)
    {
        input[i] = new char[m];
        for (int j = 0; j < m; j++)
        {
            cin >> input[i][j];
        }
    }
    checkcycle(input, n, m);
}