#include <iostream>
#include <string>
using namespace std;

bool checkstring(char **input, int i, int j, int n, int m, string s, bool **visited)
{
    if (s.size() == 0)
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

    if (input[i][j] != s[0])
    {
        return false;
    }

    visited[i][j] = true;

    bool ans = false;

    ans = ans || checkstring(input, i - 1, j - 1, n, m, s.substr(1), visited);
    ans = ans || checkstring(input, i - 1, j, n, m, s.substr(1), visited);
    ans = ans || checkstring(input, i - 1, j + 1, n, m, s.substr(1), visited);
    ans = ans || checkstring(input, i, j + 1, n, m, s.substr(1), visited);
    ans = ans || checkstring(input, i + 1, j + 1, n, m, s.substr(1), visited);
    ans = ans || checkstring(input, i + 1, j, n, m, s.substr(1), visited);
    ans = ans || checkstring(input, i + 1, j - 1, n, m, s.substr(1), visited);
    ans = ans || checkstring(input, i, j - 1, n, m, s.substr(1), visited);

    visited[i][j] = false;

    return ans;
}

void check(char **input, int n, int m)
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

    string s = "CODINGNINJA";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (input[i][j] == s[0])
            {
                bool ans = checkstring(input, i, j, n, m, s, visited);
                if (ans)
                {
                    cout << "1" << endl;
                    return;
                }
            }
        }
    }

    cout << "0" << endl;
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

    check(input, n, m);
}