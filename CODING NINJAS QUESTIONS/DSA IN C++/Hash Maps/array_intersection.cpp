#include <iostream>
#include <unordered_map>
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

void array_intersection(int *arr1, int n, int *arr2, int m)
{
    unordered_map<int, int> map;

    for (int i = 0; i < m; i++)
    {
        if (map.count(arr2[i]) > 0)
        {
            map[arr2[i]] += 1;
        }
        else
        {
            map[arr2[i]] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (map.count(arr1[i]) > 0)
        {
            if (map[arr1[i]] == 1)
            {
                map.erase(arr1[i]);
            }
            else
            {
                map[arr1[i]] -= 1;
            }
            cout << arr1[i] << " ";
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n;
        cin >> n;

        int *arr1 = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        int m;
        cin >> m;

        int *arr2 = new int[m];
        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }

        if (m > n)
        {
            merge_sort(arr1, 0, n - 1);
            array_intersection(arr1, n, arr2, m);
        }
        else
        {
            merge_sort(arr2, 0, m - 1);
            array_intersection(arr2, m, arr1, n);
        }
        cout << endl;
        t--;
    }
}