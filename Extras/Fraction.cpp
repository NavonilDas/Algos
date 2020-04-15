#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

class Fraction
{
public:
    ull nr;          // numerator
    unsigned int dr; // Power of 4 Denominator
    Fraction(int a, int b) : nr(a), dr(b)
    {
    }
    // Fraction operator/(Fraction &b)
    // {
    //     // TODO: May be Later
    //     return *this;
    // }
    Fraction operator*(Fraction b)
    {
        int a = (this->dr + b.dr);
        int k = (this->nr * b.nr);
        return Fraction(k, a);
    }
    Fraction operator*(int a)
    {
        return Fraction(this->nr * a, this->dr);
    }
    Fraction operator+(Fraction b)
    {
        if (b.dr == this->dr)
        {
            return Fraction((this->nr + b.nr), b.dr);
        }
        if (b.dr > this->dr)
        {
            int diff = b.dr - this->dr;
            ull tmp = pow(4, diff) * this->nr;
            tmp += b.nr;
            return Fraction(tmp, b.dr);
        }
        if (b.dr < this->dr)
        {
            int diff = this->dr - b.dr;
            ull tmp = pow(4, diff) * b.nr;
            tmp += this->nr;
            return Fraction(tmp, b.dr);
        }
        return *this;
    }
    Fraction operator-()
    {
        return Fraction(-1 * this->nr, this->dr);
    }
    Fraction operator-(Fraction b)
    {
        Fraction tmp = -b;
        return this->operator+(tmp);
    }
    Fraction operator%(ull modulus)
    {
        return Fraction(this->nr % modulus, this->dr);
    }
    void print()
    {
        cout << this->nr << "/(4^" << this->dr << ")" << endl;
    }
};



int main()
{
    ll xxx = 998244353;
    // cout<<xxx<<endl;
    // cout<<modInverse(4,xxx);
    // cout<<(
        modDivide(4,16,xxx);
        // )<<endl;
    // cout<<modInverse(4,7)<<endl;
    /*
    // Fraction pz(1, 1), po(1, 1), pa(1, 1), pA(1, 1);
    //(op1[0] * 4) + (op2[0] * 4) - (op1[0] * op2[0]) + (op1[2] * op2[3]) + (op1[3] * op2[2])
    // (pz - po).print();
    // (po[1]*4).print();
    freopen("input.txt", "w", stdout);
    cout << 1 << endl;
    list<char> lst = {'(', '#', '&', '#', ')'};
    while (lst.size() < 1000000)
    {
        lst.insert(lst.begin(), '(');
        lst.push_back('&');
        lst.push_back('#');
        lst.push_back(')');
        // break;
    }
    for (auto it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it;
    cout << endl;*/
    return 0;
}