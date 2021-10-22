//hollow diamond inside rectangle

#include <iostream>
using namespace std;

int main()
{
    int n, i, j;
    cout << "ENTER EVEN NUMBER OF ROWS   ";
    cin >> n;
    cout << endl
         << endl;
    for (i = 0; i <= n; i++)
    {
        if (i == n / 2)
            continue;
        for (j = 0; j < n - 1; j++)
        {
            if (i < n / 2)

                if ((j < ((n - (2 * i)) / 2)) || (j >= ((n + (2 * i) - 2) / 2)))
                    cout << "*";
                else
                    cout << " ";

            else if ((j < abs((n - (2 * i)) / 2)) || (j >= abs((n + (2 * (n - i)) - 2) / 2)))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}