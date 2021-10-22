#include <iostream>
#include <cstring>
using namespace std;

// REPACING IN THE SAME CHARACTER ARRAY
void removex(char s[], int size)
{
    if (size < 1)
        return;
    removex(s + 1, size - 1);
    if (s[0] == 'x')
    {
        int i;
        for (i = 0; s[i] != '\0'; i++)
        {
            s[i] = s[i + 1];
        }
        s[i] = '\0';
    }
}

int main()
{
    char s[1000];
    cin >> s;
    int size = strlen(s);
    removex(s, size);
    for (int i = 0; s[i] != '\0'; i++)
        cout << s[i];
    cout << endl;
}