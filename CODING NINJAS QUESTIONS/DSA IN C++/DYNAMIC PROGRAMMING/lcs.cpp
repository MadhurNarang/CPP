#include <iostream>
#include <string>
using namespace std;

int lcs_recursion(string s1, string s2)
{
    if (s1.size() == 0 || s2.size() == 0)
    {
        return 0;
    }

    int ans;
    if (s1[0] == s2[0])
    {
        ans = lcs_recursion(s1.substr(1), s2.substr(1)) + 1;
    }
    else
    {
        int x = lcs_recursion(s1, s2.substr(1));
        int y = lcs_recursion(s1.substr(1), s2);
        ans = max(x, y);
    }

    return ans;
}

int lcs_memoisation(string s1, string s2, int **arr)
{
    if (s1.size() == 0 || s2.size() == 0)
    {
        return 0;
    }

    int m = s1.size();
    int n = s2.size();

    if (arr[m][n] != -1)
    {
        return arr[m][n];
    }

    int ans;
    if (s1[0] == s2[0])
    {
        ans = lcs_memoisation(s1.substr(1), s2.substr(1), arr) + 1;
    }
    else
    {
        int x = lcs_memoisation(s1, s2.substr(1), arr);
        int y = lcs_memoisation(s1.substr(1), s2, arr);
        ans = max(x, y);
    }

    arr[m][n] = ans;

    return ans;
}

int lcs_memoisation_helper(string s1, string s2)
{
    int **arr = new int *[s1.size() + 1];
    for (int i = 0; i < s1.size() + 1; i++)
    {
        arr[i] = new int[s2.size() + 1];
        for (int j = 0; j < s2.size() + 1; j++)
        {
            arr[i][j] = -1;
        }
    }

    return lcs_memoisation(s1, s2, arr);
}

int lcs_dp(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    int **arr = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        arr[i] = new int[n + 1];
    }

    // filling first column with 0
    for (int i = 0; i < m + 1; i++)
    {
        arr[i][0] = 0;
    }

    // filling first rows with 0
    for (int j = 0; j < n + 1; j++)
    {
        arr[0][j] = 0;
    }

    // filling rest cells
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            // check if first char matches
            if (s1[m - i] == s2[n - j]) // THIS CONDITION IS IMPORTANT AS SIZE IS TAKEN FROM LAST ELEMENT
            {
                arr[i][j] = 1 + arr[i - 1][j - 1];
            }
            else
            {
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }
    return arr[m][n];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << lcs_recursion(s1, s2) << endl;
    cout << lcs_memoisation_helper(s1, s2) << endl;
    cout << lcs_dp(s1, s2) << endl;
    return 0;
}