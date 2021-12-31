#include <iostream>
#include <unordered_map>
using namespace std;

void pair_0(int *arr, int n)
{
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
    {
        if (map.count(arr[i]) > 0)
        {
            map[arr[i]] += 1;
        }
        else
        {
            map[arr[i]] = 1;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (map.count(-1 * arr[i]) > 0)
        {
            if (map[arr[i]] == 1)
            {
                map.erase(arr[i]);
            }
            else
            {
                map[arr[i]] -= 1;
            }
            ans++;
        }
    }

    cout << ans;
}

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n;
        cin >> n;

        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        pair_0(arr, n);
        cout << endl;

        t--;
    }
}