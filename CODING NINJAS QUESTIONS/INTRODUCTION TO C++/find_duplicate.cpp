
#include <iostream>
using namespace std;

void findduplicate(int arr[], int n)
{
    bool duplicate=false;
    for (int i = 0; i < n; i++)
    {
        duplicate = false;
        for (int j = i+1; j < n; j++)
        {
            
            if (arr[i] == arr[j])
            {
                duplicate=true;
                break;
            }
        }
        if (duplicate)
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

void findfromsum(int arr[], int n)
{
    int expsum,sum=0;
    expsum = ((n-2)*(n-1))/2;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    cout<<sum-expsum;
}

/*
int main()
{
    int arr[100], t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        arrin(arr, n);
        cout << endl;
        findduplicate(arr, n);
    }
    return 0;
}
*/



//2ND METHOD (ARRAY SUM METHOD)

int main()
{
    int arr[100], t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        arrin(arr, n);
        cout << endl;
        findfromsum(arr, n);
    }
    return 0;
}
