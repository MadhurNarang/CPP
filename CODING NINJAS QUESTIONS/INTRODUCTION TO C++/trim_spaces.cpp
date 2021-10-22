#include <iostream>
#include <cstring>
using namespace std;

void trimspaces(char s[])
{
    int i, j, len;
    len = strlen(s);
    for (i = 0; i < len; i++)
    {
        if (s[i] == ' ')
        {
            for (j = i; j < len; j++)
            {
                s[j] = s[j + 1];
            }
            s[j] = '\0';
            len--;
        }
    }
}

int main()
{
    char s[100];
    cin.getline(s, 100);
    trimspaces(s);
    cout << s;
    return 0;
}