#include <iostream>
using namespace std;

void columnwisesum(int arr[][100], int m, int n)
{
    int i, j, sum;
    for (j = 0; j < n; j++)
    {
        sum = 0;
        for (i = 0; i < m; i++)
        {
            sum += arr[i][j];
        }
        cout << sum << " ";
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
    int m, n, arr[100][100];
    cin >> m;
    cin >> n;
    arrinp(arr, m, n);
    columnwisesum(arr, m, n);
    return 0;
}