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

void arrout(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

void subsetsumk(int arr1[], int n, int arr2[], int k, int m = 0)
{
    if (n == 0)
    {
        int sum = sumarr(arr2, m);
        if (sum == k)
        {
            arrout(arr2, m);
        }
        return;
    }

    subsetsumk(arr1 + 1, n - 1, arr2, k, m);
    int *arr4 = new int[m + 1];
    for (int i = 0; i < m; i++)
    {
        arr4[i] = arr2[i];
    }
    arr4[m] = arr1[0];
    subsetsumk(arr1 + 1, n - 1, arr4, k, m + 1);
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
    int n;
    cin >> n;
    int *arr1 = new int[n];
    int *arr2 = new int[n + 1];
    arrin(arr1, n);
    int k;
    cin >> k;
    subsetsumk(arr1, n, arr2, k);
    delete[] arr1;
    delete[] arr2;
    return 0;
}