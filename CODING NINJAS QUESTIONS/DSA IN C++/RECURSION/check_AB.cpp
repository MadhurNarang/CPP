#include <iostream>
#include <cstring>
using namespace std;

bool checkab(char s[], int len)
{
    if (len <= 0)
    {
        return true;
    }

    bool smallans1, smallans2;

    if (s[0] == 'b')
    {
        if (s[1] == 'b')
        {
            if (s[2] != 'b')
            {
                smallans1 = checkab(s + 2, len - 2);
                smallans2 = true;
            }
        }
    }
    else
    {
        if (s[0] == 'a')
        {
            smallans1 = checkab(s + 1, len - 1);
            smallans2 = true;
        }
        else
        {
            smallans2 = false;
        }
    }
    return (smallans1 && smallans2);
}

int main()
{
    char s[1000];
    cin >> s;
    if (s[0] != 'a')
    {
        cout << "FALSE";
        exit(0);
    }
    int len = strlen(s);
    bool ans = checkab(s + 1, len - 1);
    if (ans)
        cout << "TRUE";
    else
        cout << "FALSE";
    return 0;
}