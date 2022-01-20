#include <iostream>
#include <queue>
using namespace std;

void running_median(int *arr, int n)
{
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<>> min;

    max.push(arr[0]);
    cout << max.top() << " ";

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max.top())
        {
            min.push(arr[i]);
        }
        else
        {
            max.push(arr[i]);
        }

        if (max.size() - min.size() == 2)
        {
            min.push(max.top());
            max.pop();
        }
        if (min.size() - max.size() == 2)
        {
            max.push(min.top());
            min.pop();
        }

        if (i % 2 == 1)
        {
            cout << (max.top() + min.top()) / 2 << " ";
        }
        else
        {
            if (max.size() > min.size())
            {
                cout << max.top() << " ";
            }
            else if (max.size() < min.size())
            {
                cout << min.top() << " ";
            }
        }
    }
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
    running_median(arr, n);
}