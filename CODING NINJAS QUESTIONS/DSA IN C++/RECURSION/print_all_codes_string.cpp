#include <iostream>
using namespace std;

void printcodes(string input, string output)
{
    if (input.size() == 0)
    {
        cout << output << endl;
        return;
    }
    printcodes(input.substr(1), (output + char((input[0] + 48))));
    if (input.size() >= 2)
    {
        int digitsum = ((((int)input[0]) - 48) * 10) + ((((int)input[1]) - 48));
        if (digitsum <= 26)
        {
            string tempoutput = output + ((char)(digitsum + 96));
            if (input.size() == 2)
            {

                printcodes("", tempoutput);
            }
            else
            {
                printcodes(input.substr(2), tempoutput);
            }
        }
    }
    return;
}

int main()
{
    string input, output;
    cin >> input;
    printcodes(input, output);
    return 0;
}