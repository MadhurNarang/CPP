#include <iostream>
using namespace std;

void upheapify(int i, int *arr)
{
    int childindex = i;

    while (childindex > 0)
    {
        int parentindex = (childindex - 1) / 2;
        if (arr[childindex] > arr[parentindex])
        {
            int temp = arr[childindex];
            arr[childindex] = arr[parentindex];
            arr[parentindex] = temp;
        }
        else
        {
            break;
        }

        childindex = parentindex;
    }
}

void downheapify(int i, int *arr)
{
    int ans = arr[0];
    arr[0] = arr[i];
    arr[i] = ans;

    int parentindex = 0;
    int lci = (2 * parentindex) + 1;
    int rci = (2 * parentindex) + 2;

    while (lci < i)
    {
        int maxindex = parentindex;

        if (arr[maxindex] < arr[lci])
        {
            maxindex = lci;
        }
        if (rci < i && arr[maxindex] < arr[rci])
        {
            maxindex = rci;
        }

        if (parentindex != maxindex)
        {
            int temp = arr[parentindex];
            arr[parentindex] = arr[maxindex];
            arr[maxindex] = temp;
        }
        else
        {
            break;
        }

        parentindex = maxindex;
        lci = (2 * parentindex) + 1;
        rci = (2 * parentindex) + 2;
    }
}

void inplace_heap_sort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        upheapify(i, arr);
    }

    for (int i = 0; i < n - 1; i++)
    {
        downheapify(n - 1 - i, arr);
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

    inplace_heap_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}