#include <iostream>
using namespace std;

int sum()
{
    int a, b;
    cout << "Enter two numbers: \n";
    cin >> a >> b;
    int result = a + b;
}
int main()
{
    cout << "The sum of two numbers is "<<sum();     //it will print last line of sum function only if it is mentioned in cout
    return 0;                                        //related to pointers
}