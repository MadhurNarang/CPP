#include <iostream>
#include <fstream>
using namespace std;

inline int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int returnpermutations(string input, string output[])
{
    if (input.size() == 1)
    {
        output[0] = input;
        return 1;
    }

    int smalllen = returnpermutations(input.substr(1), output);

    for (int i = 0; i < smalllen * output[0].size(); i++)
    {
        output[i + smalllen] = output[i];
    }
    int elementsize = output[0].size();
    for (int i = 0, k = 0; i <= elementsize; i++)
    {
        for (int j = 0; j < smalllen; j++)
        {
            string str1;
            string str2;
            if (i == 0)
            {
                str1 = "";
                str2 = output[k];
            }
            else if (output[k].size() - i == 0)
            {
                str1 = output[k];
                str2 = "";
            }
            else
            {
                str1 = output[k].substr(0, i);
                str2 = output[k].substr(i);
            }
            output[k++] = str1 + input[0] + str2;
        }
    }
    return (smalllen * (output[0].size()));
}

int main()
{
    string input;
    cin >> input;
    string *output = new string[factorial(input.size())];
    int size = returnpermutations(input, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << endl;
    }

    ofstream outfile;
    outfile.open("permutations.txt");
    for (int i = 0; i < size; i++)
    {
        outfile << output[i] << endl;
    }
    return 0;
}