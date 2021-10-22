#include <iostream>
#include <cstring>
using namespace std;

void removeconsecutiveduplicates(char ch[])
{
    int i, j = 0, len;
    len = strlen(ch);
    for (i = 1; i < len; i++) //we dont need to compare 0th index
    {
        if (ch[i] != ch[j])
        {
            ch[++j] = ch[i];
        }
    }
    ch[++j] = '\0';
}

int main()
{
    char ch[100];
    cin >> ch;
    removeconsecutiveduplicates(ch);
    cout << ch;
    return 0;
}