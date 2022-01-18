#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> p; // by default max-priority_queue

    p.push(100);
    p.push(10);
    p.push(15);
    p.push(4);
    p.push(17);
    p.push(21);
    p.push(67);

    cout << p.size() << endl;
    cout << p.top() << endl;

    while (!p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }
    cout << endl;
}