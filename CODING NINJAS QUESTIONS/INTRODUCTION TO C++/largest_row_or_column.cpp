#include <iostream>
#include <climits>
using namespace std;

void largestroworcolumn(int arr[][100], int m, int n)
{
    int i, j, sum, roworcol = 0, maxsum = INT_MIN;
    bool row = true;

    //row sum
    for (i = 0; i < m; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
        {
            sum += arr[i][j];
        }
        if (sum > maxsum)
        {
            maxsum = sum;
            roworcol = i;
        }
    }
    //column sum
    for (j = 0; j < n; j++)
    {
        sum = 0;
        for (i = 0; i < m; i++)
        {
            sum += arr[i][j];
        }
        if (sum > maxsum)
        {
            maxsum = sum;
            roworcol = j;
            row = false;
        }
    }

    if (row)
    {
        cout << "row " << roworcol << " " << maxsum;
    }
    else
    {
        cout << "column " << roworcol << " " << maxsum;
    }
}

void arrinp(int arr[][100], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void arrout(int arr[][100], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int m, n, arr[100][100], t, i;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        cin >> m;
        cin >> n;
        arrinp(arr, m, n);
        largestroworcolumn(arr, m, n);
    }
    return 0;
}