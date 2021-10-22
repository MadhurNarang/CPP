#include <iostream>
using namespace std;

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
    int i, j, k;
    for (i = 0; i < m; i++)
    {
        for (k = m - 1 - i; k >= 0; k--)
        {
            for (j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    int m, n, arr[100][100];
    cin >> m;
    cin >> n;
    arrinp(arr, m, n);
    arrout(arr, m, n);
    return 0;
}