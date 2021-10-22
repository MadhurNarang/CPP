#include <iostream>
using namespace std;

int binarysearch(int arr[], int start, int end, int x)
{
    if (start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == x)
    {
        return mid;
    }
    else if (arr[mid] > x)
    {
        int index = binarysearch(arr, start, mid - 1, x);
        return index;
    }
    else
    {
        int index = binarysearch(arr, mid + 1, end, x);
        return index;
    }
}

void arrin(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return;
}

void arrout(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    arrin(arr, n);
    int x;
    cin >> x;
    int ans = binarysearch(arr, 0, n, x);
    cout << ans << endl;
    return 0;
}