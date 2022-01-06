#include <iostream>
#include <unordered_map>
using namespace std;

int pair_with_diff_k(int *arr, int n, int k, unordered_map<int, int> map)
{
    int ans = 0;

    unordered_map<int, int>::iterator it = map.begin();

    while (it != map.end())
    {
        if (k == 0)
        {
            ans += (it->second * (it->second - 1) / 2);
        }
    }
}

int main()
{
    int n, k;
    unordered_map<int, int> map;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (map.count(arr[i]) > 0)
        {
            map[arr[i]] += 1;
        }
        map[arr[i]] = 1;
    }
    cin >> k;

    cout << pair_with_diff_k(arr, n, k, map) << endl;

    return 0;
}
