#include <iostream>
#include <queue>
using namespace std;

int buyticket(int *arr, int n, int k)
{
    queue<int> q;
    priority_queue<int> pq;
    int T = 0;

    for (int i = 0; i < n; i++)
    {
        q.push(i);
        pq.push(arr[i]);
    }

    while (!pq.empty())
    {
        if (pq.top() == arr[q.front()])
        {
            pq.pop();
            T++;
            if (q.front() == k)
            {
                return T;
            }
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }

    return T;
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

    cout << buyticket(arr, n, k);
}