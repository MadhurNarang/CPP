#include <iostream>
using namespace std;

int zeros(int n)
{
    if (n == 0)
    {
        return 1; //this is done because of INPUT CASE "0"
    }
    int smallans = zeros(n / 10);
    if (n % 10 == 0)
        smallans += 1;
    if (n < 10) //this line is very important for correct ans due to INPUT CASE OF "0"
        smallans--;
    return smallans;
}

int main()
{
    int n;
    cin >> n;
    int ans = zeros(n);
    cout << ans << endl;
}