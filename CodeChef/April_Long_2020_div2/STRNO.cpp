// Har Har Mahadev
#include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// #include <boost/multiprecision/cpp_int.hpp>
// using boost::multiprecision::cpp_int;

using namespace std;

#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define endl '\n'
#define ll long long
#define ull long long
#define vi vector<int>
#define vt(type) vector<type>
#define mat(type) vector<vector<type>>
#define pb push_back
#define mp make_pair
#define mii map<int, int>
#define setbits(a) __builtin_popcountll(a)
#define zrobits(a) __builtin_ctzll(a)
#define MOD 1000000007
#define INF 1e18
#define pqb priority_queue<int>
#define pqs priority_queue<int, greater<int>>
#define prec(a, b) fixed << setprecision(b) << a
#define till(a) \
    int a;      \
    cin >> a;   \
    while (a--)
#define loop(i, n) for (int i = 0; i < n; ++i)
#define from(i, a, b) for (int i = a; i <= b; ++i)
#define dloop(i, n) for (int i = n, ~i; --i)
#define debug(x1) cout << #x1 << ": " << x1 << endl;
#define all(v) (v).begin(), (v).end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// change ull to ll for negative
// ull gcd(ull a,ull b){return (b==0)?a:gcd(b,a%b);}
// ull pwrm(ull a,ull p,ull m){
//     ull res = 1;
//     a = a%m;
//     while(p > 0){
//         if(res&1)
//             res = (res*a)%m;
//         a = (a*a)%m;
//         p >>=1;
//     }
//     return res%m;
// }
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// fill,copy,lower_bound,upper_bound,max_element,min_element
// ull countd(ull n)
// {
//     ull c = 0;
//     for (ull i = 1; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//         {
//             // If divisors are equal, print only one
//             if (n / i == i)
//                 ++c;
//             // printf("%d ", i);

//             else // Otherwise print both
//                 // printf("%d %d ", i, n/i);
//                 c += 2;
//         }
//     }
//     return c;
// }
ull MAX = 1000000000;
// bool *primes;
vector<int> ps;
void s()
{
    return;
    // bool *primes = new ;
    bool primes[1000000001];

    fill(primes, primes + MAX, true);
    primes[0] = false;
    primes[1] = false;
    for (int p = 2; p * p <= MAX; p++)
    {
        if (primes[p] == true)
        {
            for (int i = p * p; i <= MAX; i += p)
                primes[i] = false;
        }
    }

    for (int i = 1; i <= MAX; ++i)
        if (primes[i])
            ps.pb(i);

    // delete primes;
}
bool Kfactors(ull n, ull k)
{
    ull c = 0;
    while (n % 2 == 0)
    {
        ++c;
        n /= 2;
    }

    for (int i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            n = n / i;
            ++c;
            // P.push_back(i);
        }
    }
    if (n > 2)
        ++c;
    return c >= k;
}
int main()
{
    // FASTIO;
#ifdef NAVONIL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // s();

    // cout << countd(405000) << endl;
    // return 0;
    ull x, k;
    till(t)
    {
        cin >> x >> k;

        if (x > k)
        {
            if (Kfactors(x, k))
            {
                cout << "1\n";
            }
            else
                cout << "0\n";

            // int i = 0;
            // ll c = 0, last = x;
            // while (ps[i] < last && x > 0)
            // {
            //     if (x % ps[i] == 0)
            //     {
            //         ++c;
            //         // cout<<ps[i]<<endl;
            //         x /= ps[i];
            //     }
            //     else
            //         ++i;
            // }
            // if (c >= k)
            //     cout << "1\n";
            // else
            // {
            //     cout << "0\n";
            // }

            // cout << c << endl;
        }
        // cout << "1\n";
        else if (x <= k)
        {
            cout << "0\n";
        }
    }
    return 0;
}