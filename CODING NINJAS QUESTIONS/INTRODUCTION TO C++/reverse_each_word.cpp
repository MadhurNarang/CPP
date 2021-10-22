#include <iostream>
#include <cstring>
using namespace std;

void reverseeachword(char s[])
{
    int i, j, k, len, temp, start;
    len = strlen(s);

    //reverse each word
    for (i = 0, start = 0; i <= len; i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            for (j = start, k = i - 1; j < k; j++, k--)
            {
                temp = s[j];
                s[j] = s[k];
                s[k] = temp;
            }
            start = i + 1;
        }
    }
}

int main()
{
    char s[100];
    cin.getline(s, 100);
    reverseeachword(s);
    cout << s;
    return 0;
}