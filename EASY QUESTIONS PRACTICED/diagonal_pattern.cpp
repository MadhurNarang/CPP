#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int i, j, k, N;
    cout << "ENTER AN ODD NUMBER\n";
    cin >> N;
    for (i = 0; i < N; i++)
    {
        for (k = 0; k < abs((N - 2 * i - 1) / 2); k++)
            cout << " ";
        for (j = 0; j < N - 2 * (abs((N - 2 * i - 1) / 2)); j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}