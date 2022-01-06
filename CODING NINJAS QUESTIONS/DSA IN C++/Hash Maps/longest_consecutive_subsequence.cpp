#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> longest_subsequence_1(int *arr, int n, unordered_map<int, bool> map)
{
    int anslength = 1, templength = 0;

    vector<int> ansvector;

    ansvector.push_back(arr[0]);

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (map.count(arr[i] + j) > 0)
        {
            templength++;
            j++;
        }

        if (templength > anslength)
        {
            while (ansvector.size() != 0)
            {
                ansvector.pop_back();
            }

            ansvector.push_back(arr[i]);
            ansvector.push_back(arr[i] + j - 1);

            anslength = templength;
        }

        templength = 0;
    }

    return ansvector;
}

vector<int> longest_subsequence_2(int *arr, int n, unordered_map<int, bool> map)
{
    int ansstart, tempstart, templength = 0, anslength = 0;

    vector<int> ansvector;

    unordered_map<int, bool>::iterator it = map.begin();

    while (it != map.end())
    {
        if (it->second == false)
        {
            int j = 0;
            while (map.count((it->first) - j) > 0)
            {
                templength++;
                tempstart = (it->first) - j;
                map[(it->first) - j] = true;
                j++;
            }

            j = 1;
            while (map.count((it->first) + j) > 0)
            {
                templength++;
                map[(it->first) + j] = true;
                j++;
            }

            if (templength > anslength)
            {
                anslength = templength;
                ansstart = tempstart;
            }
            templength = 0;
        }

        it++;
    }

    ansvector.push_back(ansstart);
    if (anslength == 1)
    {
        return ansvector;
    }
    ansvector.push_back(ansstart + anslength - 1);
    return ansvector;
}

int main()
{
    int n;
    unordered_map<int, bool> map;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        map[arr[i]] = false;
    }

    vector<int> ans = longest_subsequence_2(arr, n, map);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans.at(i) << " ";
    }
    cout << endl;
    return 0;
}
