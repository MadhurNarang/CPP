#include <iostream>
using namespace std;

/*
//O(n^2)
int duplicate(int arr[], int n)
{
    for (int i = 0, j; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                return arr[i];
            }
        }
    }
}
*/

/*
//O(nlogn) : First sort using merge sort....then traverse the whole array to find the duplicate
*/

//O(n)
int duplicate(int arr[], int n)
{
    int requiredsum = ((n - 1) * (n - 2)) / 2;
    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        totalsum += arr[i];
    }
    return totalsum - requiredsum;
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
        cout << duplicate(arr, n) << endl;
        delete[] arr;
        t--;
    }
    return 0;
}