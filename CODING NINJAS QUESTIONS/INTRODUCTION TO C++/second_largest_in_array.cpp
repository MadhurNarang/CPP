#include <iostream>
#include <climits>
using namespace std;

int secondlargest(int arr[], int n)
{
    int i, j, max = INT_MIN, smax = INT_MIN;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            smax = max; //WE CAN ALSO DO SORTING AND RETURN SECOND LAST (***DISTINCT***) ELEMENT
            max = arr[i];
        }
        else if (arr[i] > smax && arr[i] != max)
        {
            smax = arr[i];
        }
    }
    return smax;
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
        ans = secondlargest(arr, n);
        cout << ans << endl;
    }
    return 0;
}
