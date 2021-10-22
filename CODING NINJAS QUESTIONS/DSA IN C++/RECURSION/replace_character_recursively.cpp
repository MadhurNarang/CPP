#include <iostream>
using namespace std;

void replace_character(char ch[], char c1, char c2)
{
    if (ch[0] == '\0')
    {
        return;
    }
    if (ch[0] == c1)
    {
        ch[0] = c2;
    }
    replace_character(ch + 1, c1, c2);
    return;
}

int main()
{
    char ch[1000000], c1, c2;
    cin >> ch >> c1 >> c2;
    replace_character(ch, c1, c2);
    cout << ch << endl;
}
