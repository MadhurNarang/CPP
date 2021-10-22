/*THERE ARE FOUR METHODS FOR THIS QUESTION
1.   STORE WHOLE VALUES IN ANOTHER ARRAY
2.   STORE D ELEMENTS IN A COMPARATIVELY SMALLER ARRAY
3.   DO A SINGLE SHIF WITH TEMP VARIABLE D TIMES
4.   REVERSING METHOD(****GOOD METHOD****)
*/
#include <iostream>
using namespace std;

void reverserotate(int arr[], int n, int d)
{
    int i, j, temp;
    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    for (i = 0, j = n - 1 - d; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    for (i = n - d, j = n - 1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
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
    int arr[100], t, n, d;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        arrin(arr, n);
        cin >> d;
        // wholestoreandrotate(arr, n, d);
        reverserotate(arr, n, d);
        arrout(arr, n);
        cout << endl;
    }
    return 0;
}

/*
//1ST METHOD
void arrcopy(int arr[], int n, int arr2[])
{
    int i = 0;
    for (; i < n; i++)
    {
        arr[i] = arr2[i];
    }
}

void wholestoreandrotate(int arr[], int n, int d)
{
    int i, j, temp, arr2[100];
    for (i = d, j = 0; i < n; i++, j++)
    {
        arr2[j] = arr[i];
    }
    for (i = 0; i < d; i++, j++)
    {
        arr2[j] = arr[i];
    }
    arrcopy(arr, n, arr2);
}

*/