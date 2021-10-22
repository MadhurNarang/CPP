#include <iostream>
#include <cstring>
using namespace std;

void removecharacter(char s[], char ch)
{
    int i, j = 0, len;
    len = strlen(s);
    for (i = 0; i < len; i++)
    {
        if (s[i] != ch)
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

int main()
{
    char s[100], ch;
    cin >> s >> ch;
    removecharacter(s, ch);
    cout << s;
    return 0;
}