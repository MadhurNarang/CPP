#include <iostream>
#include <cstring>
using namespace std;

void remove_duplicates(char ch[])
{
    if (ch[0] == '\0')
    {
        return;
    }

    remove_duplicates(ch + 1);

    if (ch[0] == ch[1])
    {
        int len = strlen(ch);
        for (int i = 1; i <= len; i++)
        {
            ch[i - 1] = ch[i];
        }
    }
    return;
}

int main()
{
    char ch[1000];
    cin >> ch;
    remove_duplicates(ch);
    cout << ch << endl;
}
