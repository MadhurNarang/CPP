#include <iostream>
using namespace std;
#include <vector>

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.pop_back();
    v[0] = 100;
    cout << v.size();
    cout << v.capacity();
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i);
    }
    return 0;
}