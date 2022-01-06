#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longest_subarray(int *arr, int n)
{
    int ans = 0, sum = 0, tempans;
    unordered_map<int, int> summap;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            tempans = i + 1;
            ans = max(ans, tempans);
        }
        else if (summap.count(sum) > 0)
        {
            tempans = i - summap[sum];
            ans = max(ans, tempans);
        }
        else
        {
            summap[sum] = i;
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

    cout << longest_subarray(arr, n) << endl;

    return 0;
}
