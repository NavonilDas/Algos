#include <iostream>

using namespace std;

// n^e
long long pwr(long long n, long long e)
{
    long long ans = 1;
    while (e > 0)
    {
        if (e & 1)
            ans *= n;
        e >>= 1;
        n = n * n;
    }
    return ans;
}

long long modpwr(long long n, long long e, long long m)
{
    long long ret = 1;
    n = n % m;
    while (e > 0)
    {
        if (e & 1)
        {
            ret = (ret * n) % m;
        }
        e >>= 1;
        n = (n * n) % m;
    }
    return ret;
}


int main()
{
    // cout<<pwr(2,10)<<endl;
    // cout<<modpwr(2,5,13)<<endl;
    return 0;
}