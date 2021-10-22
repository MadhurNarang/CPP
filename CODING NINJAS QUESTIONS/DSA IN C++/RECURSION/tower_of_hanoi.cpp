#include <iostream>
using namespace std;

void hanoi(int n, char src = 'a', char aux = 'b', char dstn = 'c')
{
    if (n == 0)
        return;
    if (n == 1)
    {
        cout << src << " " << dstn << endl;
        return;
    }
    hanoi(n - 1, src, dstn, aux);
    cout << src << " " << dstn << endl;
    hanoi(n - 1, aux, src, dstn);
    return;
}

int main()
{
    int n;
    cin >> n;
    hanoi(n);
    cout << endl;
}