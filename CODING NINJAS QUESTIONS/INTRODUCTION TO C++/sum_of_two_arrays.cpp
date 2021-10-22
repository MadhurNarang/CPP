#include <iostream>
using namespace std;

void reversearr(int arr[], int n)
{
    for (int i = 0, j = n - 1; i < n / 2; i++, j--)
    {
        arr[i] = arr[i] + arr[j];
        arr[j] = arr[i] - arr[j];
        arr[i] = arr[i] - arr[j];
    }
}

void arrout(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

/*
//THIS METHOD CANT STORE THE VALUES OF INTEGER OR EVEN LONG IF WE PUT N OR M AS GREATER NUMBER
void sumtwoarrays(int arr1[], int n, int arr2[], int m, int arrans[])
{
    int ar1 = 0, ar2 = 0, arans = 0, i;
    for (i = 0; i < n; i++)     
    {
        ar1 = (ar1 * 10) + arr1[i];
    }
    for (i = 0; i < m; i++)
    {
        ar2 = (ar2 * 10) + arr2[i];
    }
    arans = ar1 + ar2;
    i = 0;
    while (arans != 0)
    {
        arrans[i] = arans % 10;
        arans = arans / 10;
        i++;
    }
    reversearr(arrans, i);
    if (i == 0)
        i = 1;
    arrout(arrans, i);
}*/

void arrin(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void sumtwoarrays(int arr1[], int n, int arr2[], int m, int arrans[])
{
    int i, j, k, carry = 0, digit, num2;
    for (i = n - 1, j = m - 1, k = n; i >= 0; i--, j--)
    {
        if (j < 0)
            num2 = 0;
        else
            num2 = arr2[j];
        digit = arr1[i] + num2 + carry;
        if (digit > 9)
            carry = 1;
        else
            carry = 0;
        arrans[k--] = digit % 10;
    }
    arrans[k] = carry;
}

int main()
{
    int arr1[100], arr2[100], arrans[101] = {0}, t, n, m, l, ans, i;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        cin >> n;
        arrin(arr1, n);
        cin >> m;
        arrin(arr2, m);
        if (n > m)
        {
            sumtwoarrays(arr1, n, arr2, m, arrans);
            arrout(arrans, n + 1);
        }
        else
        {
            sumtwoarrays(arr2, m, arr1, n, arrans);
            arrout(arrans, m + 1);
        }
        cout << endl;
    }
    return 0;
}
