#include <iostream>
#include <cstring>
using namespace std;

//REPLACING IN THE SAME CHARACTER ARRAY
void pairstar(char s[], int size)
{
    if (size <= 1)
        return;
    pairstar(s + 1, size - 1);
    if (s[0] == s[1])
    {
        int i = strlen(s) + 1;
        for (; i > 1; i--)
        {
            s[i] = s[i - 1];
        }
        s[i] = '*';
    }
}

int main()
{
    char s[1000];
    cin >> s;
    int size = strlen(s);
    pairstar(s, size);
    for (int i = 0; s[i] != '\0'; i++)
        cout << s[i];
    cout << endl;
}