#include <iostream>
using namespace std;

//THERE IS ANOTHER APPRAOCH WSING HASMAPS WHICH CAN MAKE COMPLEXITY O{n+m}

//O(nlogn + mlogm)
void intersection(int arr1[], int n, int arr2[], int m)
{
    for (int i = 0, j = 0; i < n && j < m;)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
}

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
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n, m;
        cin >> n;
        int *arr1 = new int[n];
        arrin(arr1, n);
        merge_sort(arr1, 0, n - 1);
        cin >> m;
        int *arr2 = new int[m];
        arrin(arr2, m);
        merge_sort(arr2, 0, m - 1);
        intersection(arr1, n, arr2, m);
        cout << endl;
        t--;
    }
    return 0;
}