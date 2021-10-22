#include <iostream>
#include <climits>
using namespace std;

void spiralprint(int arr[][100], int m, int n)
{
    int i, j, k, sr = 0, er = m - 1, sc = 0, ec = n - 1;

    for (k = 0; k < m * n;)
    {
        //top row
        for (j = sc, i = sr; j <= ec; j++)
        {
            cout << arr[i][j] << " ";
            k++;
            if (k == m * n)
                return;
        }
        sr++;

        //right column
        for (j = ec, i = sr; i <= er; i++)
        {
            cout << arr[i][j] << " ";
            k++;
            if (k == m * n)
                return;
        }
        ec--;

        //bottom row
        for (j = ec, i = er; j >= sc; j--)
        {
            cout << arr[i][j] << " ";
            k++;
            if (k == m * n)
                return;
        }
        er--;

        //left column
        for (j = sc, i = er; i >= sr; i--)
        {
            cout << arr[i][j] << " ";
            k++;
            if (k == m * n)
                return;
        }
        sc++;
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
        spiralprint(arr, m, n);
        cout << endl;
    }
    return 0;
}