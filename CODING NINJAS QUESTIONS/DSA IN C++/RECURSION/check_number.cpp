#include <iostream>
using namespace std;

bool checknumber(int arr[], int n, int x)
{
    if (n <= 0)
        return false;
    bool ans = checknumber(arr + 1, n - 1, x);
    if ((arr[0] == x) || ans)
        return true;
    else
        return false;
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
    bool ans = checknumber(arr, n, x);
    if (ans)
        cout << "TRUE";
    else
        cout << "FALSE";
    return 0;
}
