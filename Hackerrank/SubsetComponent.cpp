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
#define sz(v) ((int)(v.size()))

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// change ull to ll for negative
// ull gcd(ull a,ull b){return (b==0)?a:gcd(b,a%b);}
// ull pwrm(ull a,ull p,ull m){
//     ull res = 1;
//     a = a%m;
//     while(p > 0){
//         if(p&1)
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
int main()
{
    // clock_t tStart = clock();
    FASTIO;
#ifdef NAVONIL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll ar[30];
    int n;
    cin >> n;
    loop(i, n)
    {
        cin >> ar[i];
    }
    int pos = (1 << n) - 1;
    ll sum = 64;
    map<ll, ll> comp;
    from(i, 1, pos)
    {
        ll cur = 64;
        ll fuck = 0;
        loop(j, n)
        {
            if ((i >> j) & 1)
            {
                fuck = fuck | ar[j];
            //     int kc = setbits(ar[j]);
            //     fuck += kc;
            //     // cout << ar[j] << " ";
            //     continue;

            //     if (comp.find(ar[j]) != comp.end())
            //     {
            //         cur -= comp[ar[j]];
            //     }
            //     else
            //     {
            //         int c = setbits(ar[j]);
            //         // cout<<c<<endl;
            //         if (c == 1)
            //         {
            //             comp[ar[j]] = 0;
            //             continue;
            //         }
            //         else
            //         {
            //             int tmp = (c * (c - 1)) >> 1;
            //             comp[ar[j]] = tmp;
            //             cur -= tmp;
            //         }
            //     }
            }
        }
        cout<<setbits(fuck)<<endl;
        // cout<<fuck<<endl;
        // if(cur > 0)
        sum += (64 - setbits(fuck));
    }
    cout << sum << endl;
    return 0;
}