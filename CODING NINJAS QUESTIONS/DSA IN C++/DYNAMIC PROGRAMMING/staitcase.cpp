#include <iostream>
using namespace std;

int staircase_recursion(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    int ways = 0, a, b, c;

    ways += staircase_recursion(n - 1);
    ways += staircase_recursion(n - 2);
    ways += staircase_recursion(n - 3);

    return ways + 3;
}

int main()
{
    int n;
    cin >> n;

    cout << staircase_recursion(n) << endl;
}
