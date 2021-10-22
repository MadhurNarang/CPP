#include <iostream>
#include <cstring>
using namespace std;

bool checkpalindrome(char ch[])
{
    int i, j, len;
    len = strlen(ch);
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        if (ch[i] != ch[j])
            return false;
    }
    return true;
}

int main()
{
    char ch[100];
    cin >> ch;
    bool ans = checkpalindrome(ch);
    if (ans)
        cout << "true";
    else
        cout << "false";
    return 0;
}