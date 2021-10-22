#include <iostream>
using namespace std;

int main()
{
    int days, years, weeks;
    cin >> days;
    cout << endl;
    years = days / 365;
    weeks = (days - (years * 365)) / 7;
    days -= ((years * 365) + (weeks * 7));
    cout << years << "  " << weeks << "  " << days << "  " << endl;
    return 0;
}