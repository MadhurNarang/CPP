#include <iostream>
using namespace std;

template <typename T>
class queue
{
private:
    T *data;
    int findex;
    int rindex;
    int size;
    int capacity;

public:
    queue(int n)
    {
        data = new T[n];
        findex = -1;
        rindex = -1;
        size = 0;
        capacity = n;
    }

    bool isempty()
    {
        return size == 0;
    }

    int getsize()
    {
        return size;
    }

    T getfront()
    {
        if (size == 0)
        {
            cout << "-1" << endl;
            return 0;
        }
        return data[(findex + 1) % capacity];
    }

    T getrear()
    {
        if (size == 0)
        {
            cout << "-1" << endl;
            return 0;
        }
        if (rindex - 1 == -1)
        {
            return data[capacity - 1];
        }
        else
            return data[rindex - 1];
    }

    void insertfront(T ele)
    {
        if (size == capacity)
        {
            cout << "-1" << endl;
            return;
        }
        if (size == 0)
        {
            findex = 0;
            rindex = 1;
        }
        data[findex] = ele;

        if (findex - 1 == -1)
        {
            findex = (capacity - 1);
        }
        else
            findex -= 1;

        size++;
    }

    void insertrear(T ele)
    {
        if (size == capacity)
        {
            cout << "-1" << endl;
            return;
        }
        if (size == 0)
        {
            rindex = 0;
            findex = capacity - 1;
        }
        data[rindex] = ele;
        rindex = (rindex + 1) % capacity;
        size++;
    }

    T deletefront()
    {
        if (size == 0)
        {
            cout << "-1" << endl;
            return 0;
        }
        findex = (findex + 1) % capacity;
        T tempdata = data[findex];
        size--;

        return tempdata;
    }

    T deleterear()
    {
        if (size == 0)
        {
            cout << "-1" << endl;
            return 0;
        }
        if (rindex - 1 == -1)
        {
            rindex = (capacity - 1);
        }
        else
            rindex -= 1;
        T tempdata = data[rindex];
        size--;

        return tempdata;
    }
};

int main()
{
    queue<int> s(10);

    int q, t, ele;
    cin >> q;
    while (q > 0)
    {
        cin >> t;
        switch (t)
        {
        case 1:
            cin >> ele;
            s.insertfront(ele);
            break;
        case 2:
            cin >> ele;
            s.insertrear(ele);
            break;
        case 3:
            cout << s.deletefront();
            break;
        case 4:
            cout << s.deleterear();
            break;
        case 5:
            cout << s.getfront();
            break;
        case 6:
            cout << s.getrear();
            break;
        case 7:
            cout << s.getsize();
            break;
        case 8:
            if (s.isempty())
                cout << "TRUE";
            else
                cout << "FALSE";
            break;
        }
        cout << endl;
        q--;
    }
    return 0;
}