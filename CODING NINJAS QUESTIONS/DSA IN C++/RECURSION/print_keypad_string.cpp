#include <iostream>
using namespace std;

char dialchar(int n, int count)
{
    char c;
    switch (n)
    {
    case 0:
        if (count == 1)
            c = '0';
        break;
    case 1:
        if (count == 1)
            c = '1';
        break;
    case 2:
        if (count == 1)
            c = 'a';
        if (count == 2)
            c = 'b';
        if (count == 3)
            c = 'c';
        break;
    case 3:
        if (count == 1)
            c = 'd';
        if (count == 2)
            c = 'e';
        if (count == 3)
            c = 'f';
        break;
    case 4:
        if (count == 1)
            c = 'g';
        if (count == 2)
            c = 'h';
        if (count == 3)
            c = 'i';
        break;
    case 5:
        if (count == 1)
            c = 'j';
        if (count == 2)
            c = 'k';
        if (count == 3)
            c = 'l';
        break;
    case 6:
        if (count == 1)
            c = 'm';
        if (count == 2)
            c = 'n';
        if (count == 3)
            return 'o';
        break;
    case 7:
        if (count == 1)
            c = 'p';
        if (count == 2)
            c = 'q';
        if (count == 3)
            c = 'r';
        if (count == 4)
            c = 's';
        break;
    case 8:
        if (count == 1)
            c = 't';
        if (count == 2)
            c = 'u';
        if (count == 3)
            c = 'v';
        break;
    case 9:
        if (count == 1)
            c = 'w';
        if (count == 2)
            c = 'x';
        if (count == 3)
            c = 'y';
        if (count == 4)
            c = 'z';
        break;
    }
    return c;
}

void keypadstring(int n, string output)
{
    if (n == 0)
    {
        cout << output << endl;
        return;
    }

    int count;
    if (n % 10 == 7 || n % 10 == 9)
        count = 4;
    else if (n % 10 == 0 || n % 10 == 1)
        count = 1;
    else
        count = 3;

    for (int i = 1; i <= count; i++)
        keypadstring(n / 10, dialchar(n % 10, i) + output);

    return;
}

int main()
{
    int n;
    cin >> n;
    string output = "";
    if (n == 0 || n == 1)
        cout << n << endl;
    else
        keypadstring(n, output);
    return 0;
}