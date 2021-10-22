#include <iostream>
using namespace std;

int firstindex(int arr[], int n, int x)
{
    if (n <= 0)
    {
        return -1;
    }
    if (arr[0] == x)
    {
        return 0;
    }
    int smallans = firstindex(arr + 1, n - 1, x);
    if (smallans != -1)
        return smallans + 1;
    else
        return smallans;
}

int main()
{
    int n, x;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> x;
    int ans = firstindex(arr, n, x);
    cout << ans;
    return 0;
}
