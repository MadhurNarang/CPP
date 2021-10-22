#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

void minimumlengthword(char s[])
{
    int i, j, k, len, start, min = INT_MAX;
    char ans[100];
    len = strlen(s);

    for (i = 0, start = 0; i <= len; i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            if ((i - start) < min)
            {
                min = i - start;
                for (j = start, k = 0; j < i; j++)
                {
                    ans[k++] = s[j];
                }
                ans[k++] = '\0';
            }
            start = i + 1;
        }
    }
    cout << ans;
}

int main()
{
    char s[100];
    cin.getline(s, 100);
    minimumlengthword(s);
    return 0;
}