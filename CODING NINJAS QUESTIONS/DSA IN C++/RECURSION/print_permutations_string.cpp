#include <iostream>
#include <fstream>
using namespace std;

void printpermutations(string input, string output)
{
    if (input.size() == 0)
    {
        cout << output << endl;
        return;
    }

    for (int i = 0; i <= output.size(); i++)
    {
        string str1;
        string str2;
        if (i == 0)
        {
            str1 = "";
            str2 = output;
        }
        else if (output.size() - i == 0)
        {
            str1 = output;
            str2 = "";
        }
        else
        {
            str1 = output.substr(0, i);
            str2 = output.substr(i);
        }
        printpermutations(input.substr(1), str1 + input[0] + str2);
    }
    return;
}

int main()
{
    string input, output = "";
    cin >> input;
    printpermutations(input, output);
    return 0;
}