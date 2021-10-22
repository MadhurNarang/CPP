#include <iostream>
using namespace std;

int sumofarray(int arr[], int n)
{
    if (n <= 0)
        return 0;
    int smallsum = sumofarray(arr + 1, n - 1);
    return smallsum + arr[0];
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = sumofarray(arr, n);
    cout << ans << endl;
    return 0;
}
