#include <iostream>
#include <math.h>
using namespace std;

void subsetprint(int arr[], int n)
{
    if (n == 0)
    {
        cout << "[]" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

//IN THIS METHOD WE ARE CREATING NEW ARRAY AND COPYING ELEMENTS .....SO WE ARE NOT CHANGING THE OUTPUT ARRAY...THEREFORE THERE WILL NOT BE PROBLEM OF ARRAY SIZE
//HERE THE SIZE OF THE ARRAY IS STORED IN A DIFFERENT VARIABLE
void subsets(int arr1[], int n, int arr2[], int m = 0)
{
    if (n == 0)
    {
        subsetprint(arr2, m);
        return;
    }

    subsets(arr1 + 1, n - 1, arr2, m);
    int *arr3 = new int[m + 1];
    for (int i = 0; i < m; i++)
    {
        arr3[i] = arr2[i];
    }
    arr3[m] = arr1[0];
    subsets(arr1 + 1, n - 1, arr3, m + 1);
    return;
}
/*
//THIS METHOD SENDS SAME OUTPUT ARRAY TO BOTH THE WAYS AND HENCE ITS SIZE MODULATION IS REQUIRED
//HERE THE SIZE OF ARRAY IS STORED IN ITS FIRST ELEMET ONLY
void subsets(int arr1[], int n, int arr2[])
{
    if (n == 0)
    {
        subsetprint(arr2 + 1, arr2[0]);
        return;
    }

    subsets(arr1 + 1, n - 1, arr2);
    arr2[arr2[0] + 1] = arr1[0];
    arr2[0]++;
    subsets(arr1 + 1, n - 1, arr2);
    arr2[0]--;
    return;
}
*/
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
    int n;
    cin >> n;
    int *arr1 = new int[n];
    int *arr2 = new int[n + 1];
    arr2[0] = 0;
    arrin(arr1, n);
    subsets(arr1, n, arr2);
    delete[] arr1;
    delete[] arr2;
    return 0;
}