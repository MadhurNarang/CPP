#include <iostream>
#include <math.h>
using namespace std;

double gp(int k)
{
    if (k < 0)
    {
        return 0;
    }
    double smallans = ((1 / (pow(2, k))) + gp(k - 1));
    return smallans;
}

int main()
{
    int k;
    cin >> k;
    double ans = gp(k);
    cout << ans << endl;
}