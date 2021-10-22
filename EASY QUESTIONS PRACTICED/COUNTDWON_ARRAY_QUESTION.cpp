#include <iostream>
using namespace std;

int countdowncheck(int arr1[], int arr2[], int K, int k)
{
    int q, countdown = 0, status = 1, w, e;
    for (q = 0; q < k; q++)
    {
        for (w = arr2[q], e = 0; w <= arr2[q] + K - 1; w++, e++)
        {
            if (arr1[w] != K - e)
            {
                status = 0;
                break;
            }
        }
        if (status != 0)
            countdown++;
        status = 1;
    }
    return countdown;
}

int main()
{

    int T, i = 1, N, K, j, k, l, countdown, answer;
    cin >> T;

    do
    {
        k = 0;
        cin >> N >> K;
        int *arr1 = new int[N];
        int *arr2 = new int[N];

        for (j = 0; j < N; j++)
        {
            cin >> arr1[j];
            if (arr1[j] == K)
                arr2[k++] = j;
        }

        if (k == 0)
            answer = 0;
        else
            answer = countdowncheck(arr1, arr2, K, k);

        cout << "Case #" << i << ": " << answer << endl;
        i++;
        k = 0;
    } while (i <= T);
}
