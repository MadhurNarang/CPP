#include <iostream>
using namespace std;

void arrange(int arr[], int n)
{
    for (int i = 0, start = 0, end = n - 1; i < n; i++)
    {
        if ((i + 1) % 2 != 0)
        {
            arr[start] = i + 1;
            start++;
        }
        else
        {
            arr[end] = i + 1;
            end--;
        }
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
        ;
        arrange(arr, n);
        arrout(arr, n);
        cout << endl;
    }
    return 0;
}