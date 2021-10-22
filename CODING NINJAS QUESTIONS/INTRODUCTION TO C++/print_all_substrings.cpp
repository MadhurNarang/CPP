#include <iostream>
#include <cstring>
using namespace std;

void printallsubstrings(char s[])
{
    int i, j, k, len;
    len = strlen(s);

    for (i = 0; i < len; i++)
    {
        for (j = i; j < len; j++)
        {
            for (k = i; k <= j; k++)
            {
                cout << s[k];
            }
            cout << endl;
        }
    }
}

int main()
{
    char s[100];
    cin >> s;
    printallsubstrings(s);
    return 0;
}