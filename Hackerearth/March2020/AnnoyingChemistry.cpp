#include <bits/stdc++.h>
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define LL long long
using namespace std;
LL gcd(LL a, LL b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

LL lcm(LL a, LL b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    FASTIO;
    LL x, y, p, q, a, b, c, k;
    cin >> x >> y >> p >> q;

    LL tmp = gcd((p * y), (q * x));
    a = (p * y) / tmp;
    b = (q * x) / tmp;
    tmp = gcd(a * x, p);
    k = p / tmp;
    c = (a * x) / tmp;
    cout << (k * a) << " " << (k * b) << " " << c << endl;
    return 0;
}