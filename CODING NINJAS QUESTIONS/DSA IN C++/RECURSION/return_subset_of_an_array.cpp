#include <iostream>
#include <math.h>
using namespace std;

int subsets(int arr1[], int n, int **arr2)
{
    if (n <= 0)
    {
        arr2[0][0] = 0;
        return 1;
    }

    int smalllen = subsets(arr1 + 1, n - 1, arr2);

    for (int i = 0; i < smalllen; i++)
    {
        arr2[i + smalllen][0] = arr2[i][0] + 1;
        arr2[i + smalllen][1] = arr1[0];
        for (int j = 1; j <= arr2[i][0]; j++)
        {
            arr2[i + smalllen][j + 1] = arr2[i][j];
        }
    }
    return (2 * smalllen);
}

void arrin(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return;
}

void subsetprint(int **arr, int n)
{
    cout << "[]" << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= arr[i][0]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    int *arr1 = new int[n];
    int size = pow(2, n);
    int **arr2 = new int *[size];
    for (int i = 0; i < size; i++)
    {
        arr2[i] = new int[n];
    }
    arrin(arr1, n);
    subsets(arr1, n, arr2);
    subsetprint(arr2, size);
    delete[] arr1;
    for (int i = 0; i < n; i++)
        delete[] arr2[i];
    delete[] arr2;
    return 0;
}