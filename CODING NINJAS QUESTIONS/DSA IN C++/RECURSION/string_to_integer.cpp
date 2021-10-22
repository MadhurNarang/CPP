#include <iostream>
#include <cstring>
using namespace std;

int stringtoint(char s[], int size)
{
    if (size < 1)
        return 0;
    int smallnumber = stringtoint(s, size - 1);
    smallnumber *= 10;
    smallnumber += s[size - 1] - 48;
    return smallnumber;
}

int main()
{
    char s[1000];
    cin >> s;
    int size = strlen(s);
    int ans = stringtoint(s, size);
    cout << ans << endl;
}