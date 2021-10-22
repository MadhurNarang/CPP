#include <iostream>
using namespace std;

void pushzerostoend(int arr[], int n)
{
    int i = 0, k = 0;
    for (; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[k] = arr[i];        // ****GOOD POINT****
            if (k != i)             //OR WE CAN SWAP BOTH arr[i] and arr[k]
                arr[i] = 0;         //the we will not need to specify this condition
            k++;                    //since then swapping would not effect anything
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
        pushzerostoend(arr, n);
        arrout(arr, n);
        cout << endl;
    }
    return 0;
}