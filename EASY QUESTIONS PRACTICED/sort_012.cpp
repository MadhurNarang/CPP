#include <iostream>
using namespace std;
int main()
{
    int N, T, i = 0, j, arr;
    cin >> T;
    do
    {
        int n0 = 0, n1 = 0;
        cin >> N;
        int *arr = new int[N];
        for (j = 0; j < N; j++)
        {
            cin >> arr[j];

            if (arr[j] == 0)
                n0++;
            if (arr[j] == 0 || arr[j] == 1)
                n1++;
        }
        for (j = 0; j < N; j++)
        {
            if (j < n0)
                arr[j] = 0;
            else if (j < n1)
                arr[j] = 1;
            else
                arr[j] = 2;
        }
        for (j = 0; j < N; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
        i++;
    } while (i < T);
}