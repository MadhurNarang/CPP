#include <iostream>
using namespace std;

template <typename T>
class node
{
public:
    T data;
    node<T> *next;

    node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class queue
{
private:
    node<T> *head;
    node<T> *tail;
    int size;

public:
    queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    bool isempty()
    {
        return size == 0;
    }

    int getsize()
    {
        return size;
    }

    T front()
    {
        if (size == 0)
        {
            cout << "QUEUE EMPTY" << endl;
            return 0;
        }
        return head->data;
    }

    void enqueue(T ele)
    {
        if (head == NULL)
        {
            head = new node<T>(ele);
            tail = head;
        }
        else
        {
            tail->next = new node<T>(ele);
            tail = tail->next;
        }
        size++;
        return;
    }

    T dequeue()
    {
        if (head == NULL)
        {
            cout << "QUEUE EMPTY" << endl;
            return 0;
        }
        T temp = head->data;
        node<T> *temphead = head;
        head = head->next;
        delete temphead;
        size--;
        return temp;
    }
};

int main()
{
    queue<int> s;

    int q, t, ele;
    cin >> q;
    while (q > 0)
    {
        cin >> t;
        switch (t)
        {
        case 1:
            cin >> ele;
            s.enqueue(ele);
            break;
        case 2:
            cout << s.dequeue();
            break;
        case 3:
            cout << s.front();
            break;
        case 4:
            cout << s.getsize();
            break;
        case 5:
            if (s.isempty())
                cout << "TRUE";
            else
                cout << "FALSE";
            break;
        }
        q--;
    }
    return 0;
}