#include <iostream>
using namespace std;

int returncodes(string input, string output[])
{

    if (input.size() == 1)
    {
        output[0] = char(input[0] + 48);
        return 1;
    }
    
    int smalllen = returncodes(input.substr(1), output);

    for (int i = 0; i < smalllen; i++)
    {
        output[i] = (char(input[0] + 48)) + output[i];
    }

    if (input.size() >= 2)
    {
        int digitsum = (int(input[0]) - 48) * 10 + (int(input[1]) - 48);
        if (digitsum <= 26)
        {
            if (input.size() == 2)
            {
                output[smalllen++] = (char(digitsum + 96));
            }
            else
            {
                string *output1 = new string[input.size() - 2];
                int smalllen2 = returncodes(input.substr(2), output1);
                for (int i = 0; i < smalllen2; i++)
                {
                    output[smalllen + i] = (char(digitsum + 96)) + output1[i];
                }
                delete[] output1;
                return smalllen + smalllen2;
            }
        }
    }
    return smalllen;
}

int main()
{
    string input, output[100];
    cin >> input;
    int len = returncodes(input, output);
    for (int i = 0; i < len; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
