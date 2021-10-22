#include <iostream>
using namespace std;

//O(nlogn)
int tripletsum(int arr[], int n, int sum)
{
    int pairs = 0;
    for (int i = 0, j = n - 1; i < j;)
    {
        if (arr[i] + arr[j] == sum)
        {
            pairs++;
            cout << arr[i] << " & " << arr[j] << endl;
            int k = 1;
            while (arr[k + i] == arr[i] && k + i != j)
            {
                pairs++;
                cout << arr[k + i] << " & " << arr[j] << endl;
                k++;
            }
            j--;
        }
        else if (arr[i] + arr[j] < sum)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return pairs;
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
        int n, m, sum;
        cin >> n;
        int *arr1 = new int[n];
        arrin(arr1, n);
        cin >> sum;
        merge_sort(arr1, 0, n - 1);
        cout << tripletsum(arr1, n, sum);
        cout << endl;
        t--;
    }
    return 0;
}