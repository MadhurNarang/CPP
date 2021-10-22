#include <iostream>
#include <climits>
using namespace std;

void waveprint(int arr[][100], int m, int n)
{
    int i, j, k, waver = 1;
    //bool waver = true;

    for (j = 0; j < n; j++)
    {
        if (waver == 1)
            i = 0;
        else
            i = m - 1;
        for (k = 0; k < m; k++)
        {
            cout << arr[i][j] << " ";
            i += waver;
        }
        waver *= -1;
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
        waveprint(arr, m, n);
        cout << endl;
    }
    return 0;
}