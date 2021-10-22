#include <iostream>
using namespace std;

int binarysearch(int arr[], int n, int x)
{
    int start, mid, end;
    for (start = 0, end = n - 1; start <= end;)
    {
        mid = (start + end) / 2;
        if (arr[mid] == x)
            return (mid);
        else if (arr[mid] > x)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return (-1);
}

void arrin(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    int arr[100], t, n, x, ans;
    cin >> n;
    arrin(arr, n);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> x;
        ans = binarysearch(arr, n, x);
        cout << ans << endl;
    }
    return 0;
}