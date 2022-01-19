#include <iostream>
using namespace std;

bool check_max_heap(int *arr, int n)
{
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        int lci = (2 * i) + 1;
        int rci = (2 * i) + 2;

        if (lci > n - 1)
        {
            return ans;
        }
        if (rci > n - 1)
        {
            rci = i;
        }

        if (arr[i] != max(arr[i], max(arr[lci], arr[rci])))
        {
            return false;
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

    if (check_max_heap(arr, n) == 1)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}