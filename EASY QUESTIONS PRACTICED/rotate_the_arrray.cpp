#include <iostream>
using namespace std;

int main()
{
    int N, K, i, j, temp;
    cin >> N;
    int *arr1 = new int[N];
    for (i = 0; i < N; i++)
    {
        cin >> arr1[i];
    }
    cin >> K;
    for (i = 0; i < K; i++)
    {
        temp = arr1[0];
        for (j = 0; j < N - 1; j++)
        {
            arr1[j] = arr1[j + 1];
        }
        arr1[N - 1] = temp;
    }
    for (i = 0; i < N; i++)
    {
        cout << arr1[i] << " ";
    }
    return 0;
}