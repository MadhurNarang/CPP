#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

void leadersinarray(int arr[], int size)
{
    int i, j;
    bool leader;
    for (i = 0; i < size; i++)
    {
        leader = true;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[i])
                leader = false;
        }
        if (leader)
            cout << arr[i] << " ";
    }
}

void arrinp(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    int arr[100], size;
    cin >> size;
    arrinp(arr, size);
    leadersinarray(arr, size);
    return 0;
}