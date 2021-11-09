#include <iostream>
using namespace std;
#include <stack>

void stockspan(int arr1[], int arr2[], int n) // O(n)
{
    stack<int> s1;
    arr2[0] = 1;
    s1.push(0);
    int temp;
    for (int i = 1; i < n; i++)
    {
        if (arr1[s1.top()] == arr1[i])
        {
            arr2[i] = i - s1.top();
            s1.pop();
            s1.push(i);
        }
        else if (arr1[s1.top()] > arr1[i])
        {
            arr2[i] = i - s1.top();
            s1.push(i);
        }
        else
        {
            while (arr1[s1.top()] < arr1[i])
            {
                s1.pop();
                if (s1.empty() == 1)
                {
                    break;
                }
            }
            if (s1.empty() == 1) // this method can be done without extra space
            {
                arr2[i] = i + 1;
            }
            else
            {
                arr2[i] = i - s1.top();
            }
            s1.push(i);

            /*
            //this method cant be done without extra array
            while (arr1[s1.top()] < arr1[i])
            {
                if (s1.empty() == 1)
                {
                    break;
                }
                temp = s1.top();
                s1.pop();
                if (s1.empty() == 1)
                {
                    break;
                }
            }
            s1.push(i);
            arr2[i] = i - temp + arr2[temp];
            */
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    stockspan(arr1, arr2, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}

/*
//O(n^2)
int main()
{
    int n;
    cin >> n;
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int count = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr1[j] < arr1[i])
            {
                count++;
            }
            else
                break;
        }
        arr2[i] = count;
        count = 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }
}
*/