#include <iostream>
using namespace std;

class Polynomial
{
    int *degcoeff;
    int capacity;

public:
    //DEFAULT CONSTRUCTOR
    Polynomial()
    {
        degcoeff = new int[5];
        capacity = 5;
    }
    //COPY CONSTRUCTOR
    Polynomial(Polynomial const &p2)
    {
        int *newarr = new int[p2.capacity];
        for (int i = 0; i < capacity; i++)
        {
            newarr[i] = p2.degcoeff[i];
        }
        delete[] degcoeff;
        degcoeff = newarr;
        capacity = p2.capacity;
    }

    //PRINT
    void print()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (degcoeff[i] != 0)
                cout << degcoeff[i] << "x" << i << " " << endl;
        }
    }
    //SETCOEFFICIENT
    void setcoefficient()
    {
        int terms, max;
        cin >> terms;
        int *termarr = new int[terms];
        for (int i = 0; i < terms; i++)
        {
            cin >> termarr[i];
        }
        max = termarr[0];
        for (int i = 0; i < terms; i++)
        {
            if (max < termarr[i])
            {
                max = termarr[i];
            }
        }
        /* while (capacity - 1 < max)            //We are not making size double since memory can be wasted there...moreover more iterations will be there
        {
            int *newarr = new int[capacity * 2];
            capacity *= 2;
            delete[] degcoeff;
            degcoeff = newarr;
        }
        */
        if (capacity - 1 < max)
        {
            int *newarr = new int[max + 1];
            capacity = max + 1;
            delete[] degcoeff;
            degcoeff = newarr;
        }

        for (int i = 0; i < capacity; i++)
        {
            degcoeff[i] = 0;
        }
        int coef;
        for (int i = 0; i < terms; i++)
        {
            cin >> coef;
            degcoeff[termarr[i]] = coef;
        }
        delete[] termarr;
    }

    //=
    void operator=(Polynomial const &p2)
    {
        int *newarr = new int[p2.capacity];
        for (int i = 0; i < p2.capacity; i++)
        {
            newarr[i] = p2.degcoeff[i];
        }
        delete[] degcoeff;
        degcoeff = newarr;
        capacity = p2.capacity;
    }
    //+
    Polynomial operator+(Polynomial const &p2)
    {
        int maxcapacity = max(capacity, p2.capacity);
        int v1, v2;
        int *newarr = new int[maxcapacity];
        for (int i = 0; i < maxcapacity; i++)
        {
            if (i >= p2.capacity)
                v2 = 0;
            else
                v2 = p2.degcoeff[i];
            if (i >= capacity)
                v1 = 0;
            else
                v1 = degcoeff[i];
            newarr[i] = v1 + v2;
        }
        Polynomial p3;
        delete[] p3.degcoeff;
        p3.degcoeff = newarr;
        p3.capacity = maxcapacity;
        return p3;
    }
    //-
    Polynomial operator-(Polynomial const &p2)
    {
        int maxcapacity = max(capacity, p2.capacity);
        int v1, v2;
        int *newarr = new int[maxcapacity];

        for (int i = 0; i < maxcapacity; i++)
        {
            if (i >= p2.capacity)
                v2 = 0;
            else
                v2 = p2.degcoeff[i];
            if (i >= capacity)
                v1 = 0;
            else
                v1 = degcoeff[i];
            newarr[i] = v1 - v2;
        }
        Polynomial p3;
        delete[] p3.degcoeff;
        p3.degcoeff = newarr;
        p3.capacity = maxcapacity;
        return p3;
    }
    //*
    Polynomial operator*(Polynomial const &p2)
    {
        int maxdeg1 = 0, maxdeg2 = 0;

        for (int i = capacity; i >= 0; i--)
        {
            if (degcoeff[i] != 0)
            {
                maxdeg1 = i;
                break;
            }
        }

        for (int i = p2.capacity; i >= 0; i--)
        {
            if (p2.degcoeff[i] != 0)
            {
                maxdeg2 = i;
                break;
            }
        }

        int maxcapacity = (maxdeg1 * maxdeg2) + 1;
        int *newarr = new int[maxcapacity];
        for (int i = 0; i < maxcapacity; i++)
        {
            newarr[i] = 0;
        }

        for (int i = 0; i < capacity; i++)
        {
            for (int j = 0; j < p2.capacity; j++)
            {
                newarr[i + j] += degcoeff[i] * p2.degcoeff[j];
            }
        }

        Polynomial p3;
        delete[] p3.degcoeff;
        p3.degcoeff = newarr;
        p3.capacity = maxcapacity;
        return p3;
    }
};

int main()
{
    Polynomial p1, p2, p3;
    p1.setcoefficient();
    p2.setcoefficient();
    p1.print();
    p2.print();
    int c;
    cin >> c;
    switch (c)
    {
    case 1:
        p3 = p1 + p2;
        p3.print();
        break;
    case 2:
        p3 = p1 - p2;
        p3.print();
        break;
    case 3:
        p3 = p1 * p2;
        p3.print();
        break;
    case 4:
        p3 = p1;
        p3.print();
        break;
    default:
        return 0;
    }
    return 0;
}