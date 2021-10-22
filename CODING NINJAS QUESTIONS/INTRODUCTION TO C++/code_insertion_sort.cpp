#include <iostream>
using namespace std;

void insertionsort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        for (j = i, temp = arr[i]; j > 0 && arr[j - 1] > temp; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}

void arrin(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void arrout(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[100], t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        arrin(arr, n);
        insertionsort(arr, n);
        arrout(arr, n);
    }
    return 0;
}