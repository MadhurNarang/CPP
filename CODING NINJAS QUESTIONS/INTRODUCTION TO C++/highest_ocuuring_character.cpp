#include <iostream>
#include <cstring>
using namespace std;

char highestoccur(char s[])
{
    int i, j, len, reps, max = 0, arr[100] = {0};
    char ch;
    len = strlen(s);
    for (i = 0; i < len; i++)
    {
        for (j = 0, reps = 0; j < len; j++)
        {
            if (s[i] == s[j])
                reps++;
        }
        arr[i] = reps;
        if (arr[i] > max)
        {
            max = arr[i];
            ch = s[i];
        }
    }
    return ch;
}

int main()
{
    char s[100];
    cin >> s;
    cout << highestoccur(s);
    return 0;
}