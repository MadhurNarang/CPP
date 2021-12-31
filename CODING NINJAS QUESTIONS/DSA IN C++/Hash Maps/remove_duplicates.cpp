#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> remove_duplicates(int *a, int size)
{
    vector<int> output;
    unordered_map<int, bool> status;

    for (int i = 0; i < size; i++)
    {
        if (status.count(a[i]) > 0)
        {
            continue;
        }
        status[a[i]] = true;
        output.push_back(a[i]);
    }
    return output;
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

    vector<int> output = remove_duplicates(arr, n);
    for (int i = 0; i < output.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}