#include <iostream>
#include <math.h>
using namespace std;

int subsequence(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    int smalllen = subsequence(input.substr(1), output);
    for (int i = 0; i < smalllen; i++)
    {
        output[i + smalllen] = input[0] + output[i];
    }
    return 2 * smalllen;
}

int main()
{
    string input;
    cin >> input;
    int size = pow(2, input.size());
    string *output = new string[size];
    int len = subsequence(input, output);
    for (int i = 0; i < len; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}