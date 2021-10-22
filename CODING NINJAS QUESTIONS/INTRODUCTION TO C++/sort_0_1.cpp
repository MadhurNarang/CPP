#include <iostream>
using namespace std;
/*  //WRONG APPROACH BECAUSE IT SCANS THE ARRAY TWO TIMES
void sort(int arr[], int n)
{
    int nofzero = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] == 0)
        {
            nofzero++;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (j < nofzero)
            arr[j] = 0;
        else
            arr[j] = 1;
    }
}
*/
void sort(int arr[], int n)
{

    for (int i = 0, j = n - 1; i < j;)
    {
        if (arr[i] == 1 && arr[j] == 0)
        {
            arr[i] = 0;
            arr[j] = 1;
        }
        if (arr[i] != 1)
        {
            i++;
        }
        if (arr[j] != 0)
        {
            j--;
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
    int arr[100], t, n, x;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        arrin(arr, n);
        cout << endl;
        sort(arr, n);
        arrout(arr, n);
    }
    return 0;
}