#include <iostream>
using namespace std;

void findunique(int arr[], int n)
{
    bool unique;
    for (int i = 0; i < n; i++)
    {
        unique = true;
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            if (arr[i] == arr[j])
            {
                unique = false;
                break;
            }
        }
        if (unique)
        {
            cout << arr[i];
            break;
        }
    }
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
    int arr[100], t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        arrin(arr, n);
        cout << endl;
        findunique(arr, n);
    }
    return 0;
}