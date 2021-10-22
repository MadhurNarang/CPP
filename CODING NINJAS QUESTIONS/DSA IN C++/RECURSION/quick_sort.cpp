#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei)
{
    int count = 0, temp = 0;
    for (int i = si + 1; i <= ei; i++)
    {
        if (arr[i] <= arr[si])
        {
            count++;
        }
    }

    temp = arr[si];
    arr[si] = arr[si + count];
    arr[si + count] = temp;

    for (int i = si, j = ei; (i < si + count) && (j > si + count);)
    {
        if (arr[i] <= arr[si + count])
        {
            i++;
        }
        else
        {
            if (arr[j] > arr[si + count])
            {
                j--;
            }
            else
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    return (si + count);
}

void quick_sort(int arr[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }

    int posn = partition(arr, si, ei);

    quick_sort(arr, si, posn - 1);
    quick_sort(arr, posn + 1, ei);

    return;
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
    int n;
    cin >> n;
    int *arr = new int[n];
    arrin(arr, n);
    quick_sort(arr, 0, n - 1);
    arrout(arr, n);
    return 0;
}
