#include <iostream>
using namespace std;

void sort012(int arr[], int n)
{
    int i, nz, nt, temp;
    for (i = 0, nz = 0, nt = n - 1; i < n;) //SINGLE SCAN MEANS IF WE MOVED TO NEXTINDEX THEN WE CANT GO BACK
    {                                       //SINGLE SCAN DOESNT MEAN THAT WE CAN ACCESS SPECIFIC INDEX ONLY ONCE
        if (arr[i] == 2)
        {
            if (nt <= i)
            {
                i++; //**** i++ and continue means a very good point ****
                continue;
            }                 //****VERY GOOD POINT****
            temp = arr[i];    //SPECIFYING arr[i]==2 above ==0
            arr[i] = arr[nt]; // is done intentionally
            arr[nt] = temp;
            nt--;
        }

        if (arr[i] == 0)
        {
            temp = arr[i];
            arr[i] = arr[nz];
            arr[nz] = temp;
            nz++;
            i++; //we are not giving i++ in for loop updation because we dont want to update value every time
        }

        if (arr[i] == 1) //WE ARE GIVING arr[i]==1 after == 0 for a certain reason
            i++;         //we are not giving i++ in for loop updation because we dont want to update value every time
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
    int arr[100], t, n, ans;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        arrin(arr, n);
        sort012(arr, n);
        arrout(arr, n);
    }
    return 0;
}
