#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    void print()
    {
        cout << this->numerator << " / " << denominator << endl;
    }

    void simplify()
    {
        int gcd = 1;
        int j = min(this->numerator, this->denominator);
        for (int i = 1; i <= j; i++)
        {
            if (this->numerator % i == 0 && this->denominator % i == 0)
            {
                gcd = i;
            }
        }
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }

    void add(Fraction const &f2)
    {
        int den = denominator * f2.denominator;
        int num = (f2.denominator * numerator) + (denominator * f2.numerator);

        numerator = num;
        denominator = den;

        simplify();
    }

    void multiply(Fraction const &f2)
    {
        numerator *= f2.numerator;
        denominator *= f2.denominator;
        simplify();
    }
};

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);
    f1.add(f2);
    f1.print();
    f2.print();
    f2.multiply(f1);
    f1.print();
    f2.print();
    return 0;
}