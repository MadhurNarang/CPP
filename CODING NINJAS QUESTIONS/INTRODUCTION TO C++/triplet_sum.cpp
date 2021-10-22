#include <iostream>
using namespace std;

void tripletsum(int arr[], int n, int x)
{
    int triplets = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == x)
                {
                    triplets++;
                }
            }
        }
    }
    cout << triplets;
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
    int arr[100], t, n, x;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        arrin(arr, n);
        cin >> x;
        cout << endl;
        tripletsum(arr, n, x);
    }
    return 0;
}