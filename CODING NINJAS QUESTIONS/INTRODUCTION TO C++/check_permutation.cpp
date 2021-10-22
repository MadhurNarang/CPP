#include <iostream>
#include <cstring>
using namespace std;

bool checkpermutation(char ch1[], char ch2[])
{
    int i, j, len1, len2, arr[100] = {0};
    bool found;
    len1 = strlen(ch1);
    len2 = strlen(ch2);
    if (len1 != len2)
        return false;
    for (i = 0; i < len1; i++)
    {
        found = false;
        for (j = 0; j < len1; j++)
        {
            if ((ch1[i] == ch2[j]) && (arr[j] == 0)) //DECLARING ARRAY FOR REPEATED ALPHABET WORDS
            {
                found = true;
                arr[j] = 1;
                break;
            }
        }
        if (!found)
            return false;
    }
    return true;
}

int main()
{
    char ch1[100], ch2[100];
    cin >> ch1 >> ch2;
    bool ans = checkpermutation(ch1, ch2);
    if (ans)
        cout << "true";
    else
        cout << "false";
    return 0;
}