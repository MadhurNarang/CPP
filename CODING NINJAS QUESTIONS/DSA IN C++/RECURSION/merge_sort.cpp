#include <iostream>
using namespace std;

void arrcopy(int arr[], int arr2[], int si, int ei)
{
    int i = 0, j = si;
    for (; j <= ei;)
    {
        arr[j++] = arr2[i++];
    }
    return;
}

void merge(int arr[], int si, int ei, int mid)
{
    int *arr2 = new int[ei - si + 1];
    int i = si, j = mid + 1, k = 0;
    for (; i <= mid && j <= ei;)
    {
        if (arr[i] < arr[j])
        {
            arr2[k++] = arr[i++];
        }
        else
        {
            arr2[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        arr2[k++] = arr[i++];
    }
    while (j <= ei)
    {
        arr2[k++] = arr[j++];
    }

    arrcopy(arr, arr2, si, ei);
    return;
}

void merge_sort(int arr[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }

    int mid = (si + ei) / 2;

    merge_sort(arr, si, mid);
    merge_sort(arr, mid + 1, ei);

    merge(arr, si, ei, mid);
    return;
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
    int n;
    cin >> n;
    int *arr = new int[n];
    arrin(arr, n);
    merge_sort(arr, 0, n - 1);
    arrout(arr, n);
    return 0;
}
