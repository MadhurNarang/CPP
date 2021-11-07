#include <iostream>
#include <stack>
using namespace std;

/*  ANOTHER METHOD
void stackreverse(stack<int> *s1, stack<int> *s2)
{
    if (s1->size() == 0)
    {
        return;
    }

    int smalltop = s1->top();
    s1->pop();
    stackreverse(s1, s2);
    s2->push(smalltop);
    return;
}

int main()
{
    stack<int> s1, s2;
    int n, ele;
    cin >> n;
    while (n > 0)
    {
        cin >> ele;
        s1.push(ele);
        n--;
    }
    stackreverse(&s1, &s2);

    while (s2.empty() == 0)
    {
        s1.push(s2.top());
        s2.pop();
    }

    while (s1.empty() == 0)
    {
        cout << s1.top() << " ";
        s1.pop();
    }

    return 0;
}
*/

void stackreverse(stack<int> *s1, stack<int> *s2)
{
    if (s1->size() == 0 || s1->size() == 1)
    {
        return;
    }

    int smalltop = s1->top();
    s1->pop();

    stackreverse(s1, s2);

    while (s1->empty() == 0)
    {
        s2->push(s1->top());
        s1->pop();
    }
    s1->push(smalltop);
    while (s2->empty() == 0)
    {
        s1->push(s2->top());
        s2->pop();
    }

    return;
}

int main()
{
    stack<int> s1, s2;
    int n, ele;
    cin >> n;
    while (n > 0)
    {
        cin >> ele;
        s1.push(ele);
        n--;
    }
    stackreverse(&s1, &s2);

    while (s1.empty() == 0)
    {
        cout << s1.top() << " ";
        s1.pop();
    }

    return 0;
}