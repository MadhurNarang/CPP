#include <iostream>
#include <cstring>
using namespace std;

void reversewordwise(char s[])
{
    int i, j, k, len, temp, start;
    len = strlen(s);

    //reverse whole array
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

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
    reversewordwise(s);
    cout << s;
    return 0;
}