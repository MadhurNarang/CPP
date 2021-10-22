#include <iostream>
using namespace std;

//O(n)
int checkrotate(int arr[], int n)
{
    int rotate = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            rotate = i + 1;
            break;
        }
    }
    return rotate;
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
    int t;
    cin >> t;
    while (t > 0)
    {
        int n;
        cin >> n;
        int *arr1 = new int[n];
        arrin(arr1, n);
        cout << checkrotate(arr1, n);
        cout << endl;
        t--;
    }
    return 0;
}