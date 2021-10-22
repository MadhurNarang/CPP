#include <iostream>
using namespace std;

/*
//O(n^2)
int findunique(int arr[], int n)
{
    for (int i = 0, j; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[j] == arr[i] && i != j)
            {
                break;
            }
        }
        if (arr[j] != arr[i])
        {
            return arr[i];
        }
    }
}
*/

/*
//O(nlogn) : First sort using merge sort....then traverse the whole array to find the unique
*/

//O(n)
int findunique(int arr[], int n)
{
    int ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        ans = arr[i] ^ ans;
    }
    return ans;
}

void arrin(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
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
        int *arr = new int[n];
        arrin(arr, n);
        cout << findunique(arr, n) << endl;
        delete[] arr;
        t--;
    }
    return 0;
}