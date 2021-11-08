#include <iostream>
#include <queue>
using namespace std;

void queuereverse(queue<int> *q1)
{
    if (q1->size() == 0 || q1->size() == 1)
    {
        return;
    }

    int smallfront = q1->front();
    q1->pop();

    queuereverse(q1);

    q1->push(smallfront);

    return;
}

int main()
{
    queue<int> q1;
    int n, ele;
    cin >> n;
    while (n > 0)
    {
        cin >> ele;
        q1.push(ele);
        n--;
    }
    queuereverse(&q1);

    while (q1.empty() == 0)
    {
        cout << q1.front() << " ";
        q1.pop();
    }

    return 0;
}