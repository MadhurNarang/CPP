#include <iostream>
using namespace std;

string inttostring(int n)
{
    if (n == 0)
    {
        return "";
    }

    string smallstring = inttostring(n / 10);

    char c = 48 + (n % 10);
    smallstring = smallstring + c;
    return smallstring;
}

int main()
{
    int n;
    string ans;
    cin >> n;
    if (n == 0)
        ans = "0";
    else
        sans = inttostring(n);
    cout << ans << endl;
}