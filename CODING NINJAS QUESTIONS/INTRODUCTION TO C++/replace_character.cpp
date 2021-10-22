#include <iostream>
#include <cstring>
using namespace std;

void replacecharacter(char s[], char c1, char c2)
{
    int i, len;
    len = strlen(s);
    for (i = 0; i < len; i++)
    {
        if (s[i] == c1)
            s[i] = c2;
    }
}

int main()
{
    char s[100], c1, c2;
    cin >> s;
    cin >> c1 >> c2;
    replacecharacter(s, c1, c2);
    cout << s;
    return 0;
}