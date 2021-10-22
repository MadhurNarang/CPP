#include <iostream>
using namespace std;

int checkrotate(int arr[], int n)
{
    int ans = 0, i;
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1]) // CLOCKWISE ROTATION MEANS SHIFTING TOWARDS RIGHT
        {
            ans = i + 1;
            break;
        }
    }
    return ans;
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
    int arr[100], t, n, ans;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        arrin(arr, n);
        ans = checkrotate(arr, n);
        cout << ans << endl;
    }
    return 0;
}
