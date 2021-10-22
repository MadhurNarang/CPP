#include <iostream>
using namespace std;

int main()
{
    int i, j, k, N;
    cout << "ENTER AN EVEN NUMBER\n";
    cin >> N;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i > N / 2)
                k = N - i - 1;
            else
                k = i;
            if ((j <= k) || j >= (N - k - 1))
            {
                cout << "*";
            }
            else
                cout << " ";
        }
        cout << endl;
    }
}