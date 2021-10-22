#include <iostream>
using namespace std;

bool checksorted2(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    bool smallans = checksorted2(arr + 1, n - 1);
    if (!smallans)
    {
        return false;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
        return true;
}

bool checksorted1(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    bool ans = checksorted1(arr + 1, n - 1);
    return ans;
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
    bool ans = checksorted1(arr, n);
    if (ans)
        cout << "SORTED";
    else
        cout << "NOT SORTED";
    return 0;
}
