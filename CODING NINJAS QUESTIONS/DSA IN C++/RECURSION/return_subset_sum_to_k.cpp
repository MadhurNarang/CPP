#include <iostream>
#include <math.h>
using namespace std;

int sumarr(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }

    int smallsum = sumarr(arr + 1, n - 1);
    return (smallsum + arr[0]);
}

void arrcpy(int arr1[], int n, int **arr, int no)
{
    arr[no][0] = n;
    for (int i = 0; i <= n; i++)
    {
        arr[no][1 + i] = arr1[i];
    }
    return;
}

void subsetprint(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= arr[i][0]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

void subsetsumk(int &no, int arr1[], int n, int arr2[], int k, int **arr3, int m = 0)
{
    if (n == 0)
    {
        int sum = sumarr(arr2, m);
        if (sum == k)
        {
            arrcpy(arr2, m, arr3, no);
            no++;
        }
        return;
    }

    subsetsumk(no, arr1 + 1, n - 1, arr2, k, arr3, m);
    int *arr4 = new int[m + 1];
    for (int i = 0; i < m; i++)
    {
        arr4[i] = arr2[i];
    }
    arr4[m] = arr1[0];
    subsetsumk(no, arr1 + 1, n - 1, arr4, k, arr3, m + 1);
    return;
}

void arrin(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return;
}

int main()
{
    int n, no = 0;
    cin >> n;
    int *arr1 = new int[n];
    int *arr2 = new int[n + 1];
    int size = pow(2, n);
    int **arr3 = new int *[size];
    for (int i = 0; i < size; i++)
    {
        arr3[i] = new int[n];
    }
    arrin(arr1, n);
    int k;
    cin >> k;
    subsetsumk(no, arr1, n, arr2, k, arr3);
    subsetprint(arr3, no);
    delete[] arr1;
    for (int i = 0; i < n; i++)
        delete[] arr3[i];
    delete[] arr3;
    delete[] arr2;
    return 0;
}