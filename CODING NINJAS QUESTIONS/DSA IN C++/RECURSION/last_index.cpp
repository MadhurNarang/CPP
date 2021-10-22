#include <iostream>
using namespace std;

int lastindex(int arr[], int n, int x)
{
    if (n <= 0)
    {
        return -1;
    }
    int smallans = lastindex(arr + 1, n - 1, x);
    if (arr[0] == x && !(smallans >= 0))
    {
        return 0;
    }
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
    int ans = lastindex(arr, n, x);
    cout << ans;
    return 0;
}
