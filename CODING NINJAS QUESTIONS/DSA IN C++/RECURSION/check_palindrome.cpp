#include <iostream>
#include <cstring>
using namespace std;

//USING RECURSION TO CHECK PALINDROME
bool palindrome(char s[], int start, int end)
{
    if (start >= end)
        return true;
    if (s[start] != s[end])
        return false;
    bool smallans = palindrome(s, start + 1, end - 1);
    return smallans;
}

/*
//  USING RECURSION TO ONLY REVERSE THE STRING AND THEN COMPARING THE STRINGS

void reversal(char s[], char t[], int size)
{
    if (size == 0)
        return;
    reversal(s + 1, t, size - 1);
    t[size - 1] = s[0];
}
*/

int main()
{
    char s[1000], t[1000];
    cin >> s;
    int size = strlen(s);
    bool ans = palindrome(s, 0, size - 1);
    cout << ans;
    /*reversal(s, t, size);
    if (strcmp(s, t) == 0)
        cout << "TRUE";
    else
        cout << "FALSE";*/
}