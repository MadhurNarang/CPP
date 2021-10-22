#include <iostream>
using namespace std;

void sumpairs(int arr[], int n,int x)
{
    int pairs=0;
    for (int i = 0; i < n; i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==x)
                pairs++;
        }
    }
    cout<<pairs;
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
    int arr[100], t, n,x;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        arrin(arr, n);
        cin>>x;
        cout << endl;
        sumpairs(arr, n,x);
    }
    return 0;
}