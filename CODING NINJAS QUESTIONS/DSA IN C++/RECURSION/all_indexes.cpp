#include <iostream>
using namespace std;
/*
//RECURSIVE + ITERATION METHOD
int singleindex(int arr[], int n, int x)
{
    if (n <= 0)
    {
        return -1;
    }
    if (arr[0] == x)
    {
        return 0;
    }
    int smallans = singleindex(arr + 1, n - 1, x);
    if (smallans != -1)
        return smallans + 1;
    else
        return smallans;
}

void allindex(int arr[], int n, int x)
{
    int i = 0, index = 0, update;
    int *ans = new int[n];
    index = singleindex(arr, n, x);
    ans[0] = index;
    for (i = 1; i < n; i++)
    {
        if (index == -1)
            break;
        update = ans[i - 1] + 1;
        index = singleindex(arr + update, n - update, x);
        if (index != -1)
        {
            ans[i] = index + ans[i - 1] + 1;
        }
        else
            break;
    }
    for (int size = 0; size < i; size++)
    {
        cout << ans[size] << " ";
    }
}
*/
//ONLY RECURSIVE METHOD
int allindex(int arr1[], int n, int x, int arr2[])
{
    if (n <= 0)
    {
        return 0;
    }
    int size = allindex(arr1, n - 1, x, arr2);
    if (arr1[n - 1] == x)
    {
        arr2[size] = n - 1;
        size++;
    }
    return size;
}
void printarray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n, x;
    cin >> n;
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cin >> x;
    int anssize = allindex(arr1, n, x, arr2);
    printarray(arr2, anssize);
    return 0;
}
