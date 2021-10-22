#include <iostream>
#include <cstring>
using namespace std;
/*
//CHANGING IN ANOTHER ARRAY
int replacepi(char s[], char t[], int size)
{
    if (size < 2)
        return 0;
    int smallindex = replacepi(s + 1, t, size - 1);
    if (s[0] == 'p' && s[1] == 'i')
    {
        t[smallindex++] = '3';
        t[smallindex++] = '.';
        t[smallindex++] = '1';
        t[smallindex++] = '4';
    }
    else
        t[smallindex++] = s[0];
    return smallindex;
}
*/

// REPACING IN THE SAME CHARACTER ARRAY
void replacepi(char s[], int size)
{
    if (size < 2)
        return;
    replacepi(s + 1, size - 1);
    if (s[0] == 'p' && s[1] == 'i')
    {
        int i = 2;
        while (s[i] != 0)
        {
            i++; //string length
        }
        for (i = i + 2; i >= 4; i--)
        {
            s[i] = s[i - 2];
        }
        s[0] = '3';
        s[1] = '.';
        s[2] = '1';
        s[3] = '4';
    }
    return;
}

int main()
{
    char s[1000], t[1000];
    cin >> s;
    int size = strlen(s);
    replacepi(s, size);
    for (int i = 0; s[i] != '\0'; i++)
        cout << s[i];
    /*
    int anssize = replacepi(s, t, size);
    for (int i = 0; i < anssize; i++)
        cout << t[i];
    */
    cout << endl;
}