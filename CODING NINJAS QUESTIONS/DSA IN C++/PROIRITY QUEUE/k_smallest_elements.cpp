#include <iostream>
#include <queue>
using namespace std;

vector<int> *k_smallest_elements(int *arr, int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    vector<int> *v;

    while (!pq.empty())
    {
        v->push_back(pq.top());
        pq.pop();
    }
    return v;
}

int main()
{
    int n, k;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;

    vector<int> *ans = k_smallest_elements(arr, n, k);

    for (int i = 0; i < ans->size(); i++)
    {
        cout << ans->at(i) << " ";
    }
}