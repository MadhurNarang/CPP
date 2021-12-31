#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int max_frequency(int *a, int size)
{
    unordered_map<int, bool> freq;

    for (int i = 0; i < size; i++)
    {
        if (freq.count(a[i]) > 0)
        {
            freq[a[i]] = freq[a[i]] + 1;
        }
        else
        {
            freq[a[i]] = 1;
        }
    }

    int ans = a[0];
    for (int i = 0; i < size; i++)
    {
        if (freq.count(a[i]) > 0)
        {
            if (freq[a[i]] > freq[ans])
            {
                ans = a[i];
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << max_frequency(arr, n) << endl;
}