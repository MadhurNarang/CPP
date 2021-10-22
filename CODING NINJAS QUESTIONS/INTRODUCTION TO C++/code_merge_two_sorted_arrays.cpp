#include <iostream>
using namespace std;

void mergesortedarrays(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i, j, k, temp;
    for (i = 0, j = 0, k = 0; i < n && j < m;)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i];
            i++;
        }
        else
        {
            arr3[k++] = arr2[j];
            j++;
        }
    }
    for (; i < n;)
    {
        arr3[k++] = arr1[i];
        i++;
    }
    for (; j < m;)
    {
        arr3[k++] = arr2[j];
        j++;
    }
}

void arrin(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void arrout(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr1[100], arr2[100], arr3[200], t, n, m;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        arrin(arr1, n);
        cin >> m;
        arrin(arr2, m);
        mergesortedarrays(arr1, n, arr2, m, arr3);
        arrout(arr3, m + n);
        cout << endl;
    }
    return 0;
}