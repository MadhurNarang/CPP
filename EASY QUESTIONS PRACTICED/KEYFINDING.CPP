#include <iostream>
using namespace std;

int main()
{
    int a[3], l, sl, lsum = 0, slsum = 0, i = 0;
    for (i = 0; i < 3; i++)
    {
        cin >> a[i];
    }

    for (i = 0; i < 3; i++)
    {
        l = 0;
        sl = -1;
        while (a[i] != 0)
        {
            if (a[i] % 10 >= l)
            {
                sl = l;
                l = a[i] % 10;
            }
            else
            {
                if (a[i] % 10 > sl)
                {
                    sl = a[i] % 10;
                }
            }
            a[i] /= 10;
        }
        if (sl == -1)
        {
            sl = l;
        }
        cout << "a[" << i << "]" << endl
             << "Largest : " << l << endl
             << "Second Largest : " << sl << endl;
        slsum += sl;
        lsum += l;
    }

    cout << "KEY : " << lsum - slsum << endl;
}