#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

void compressstring(char ch[])
{
    int i, j = 0, start = 0, len, reps, n, digits;
    len = strlen(ch);
    for (i = 0; i <= len; i++)
    {
        if (ch[i] != ch[j])
        {
            reps = i - start;
            if (reps > 1)
            {
                //for reps<10 :  ch[++j]='0'+reps;
                digits = int(log10(reps)); //****THIS IS THE METHOD TO STORE A NUMBER FROM LEFT TO RIGHT
                while (digits >= 0)        //THAT IS WE DONT DO REMAINDERS AND DIVISION STUFF
                {
                    n = (reps / int(pow(10, digits)));
                    reps = reps % (int(pow(10, digits)));
                    ch[++j] = '0' + n;
                    digits--;
                }
                ch[++j] = ch[i];
            }
            else
            {
                ch[++j] = ch[i];
            }
            start = i;
        }
    }
    ch[++j] = '\0';
}

int main()
{
    char ch[100];
    cin >> ch;
    compressstring(ch);
    cout << ch;
    return 0;
}