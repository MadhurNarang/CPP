#include <iostream>
using namespace std;

void reverse(int arr[], int n)
{
    for (int i = 0, j = n - 1, temp; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    return;
}

//O(n)
void rotatearray(int arr[], int n, int rotate)
{
    reverse(arr, n);
    reverse(arr, n - rotate);
    reverse(arr + n - rotate, rotate);
    return;
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
        int n, m, rotate;
        cin >> n;
        int *arr1 = new int[n];
        arrin(arr1, n);
        cin >> rotate;
        rotatearray(arr1, n, rotate);
        arrout(arr1, n);
        cout << endl;
        t--;
    }
    return 0;
}