#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kth_largest_element(int *arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}

int main()
{
    int no, k;
    cin >> no;
    int *n = new int[no];
    for (int i = 0; i < no; i++)
    {
        cin >> n[i];
    }
    cin >> k;

    cout << kth_largest_element(arr, n, k);
}