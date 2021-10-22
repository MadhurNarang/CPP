#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
    char x;
    cin >> x;
    if (isalpha(x))
        cout << "alphabet" << endl;
    else
        cout << "not alphabet" << endl;
    /*
    if ((x >= 65 && x <= 90) || (x >= 97 && x <= 122))
        cout << "alphabet" << endl;
    else
        cout << "not alphabet" << endl;
    */
    return 0;
}