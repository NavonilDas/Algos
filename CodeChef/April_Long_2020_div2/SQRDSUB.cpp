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
const int MAX = 100000;
ll ar[MAX + 5], pre[MAX + 5];
ull fortwo(ll *pre,int n)
{
    int l = 0, r = 0;
    ll ans = 0;
    while (r < n)
    {
        int cur = pre[r] - ((l == 0) ? 0 : pre[l - 1]);
        if (cur >= 2)
        {
            ans += n - r;
            ++l;
        }
        else
        {
            ++r;
        }
    }
    return ans;
}

int main()
{
    FASTIO;
#ifdef NAVONIL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    ull odd = 0, ocnt = 0;
    till(t)
    {
        cin >> n;
        odd = 0, ocnt = 0;
        memset(pre, 0, sizeof(pre));
        loop(i, n)
        {
            cin >> ar[i];

            int tmp = (ar[i] % 4 == 0) ? 2 : ((ar[i] % 2 == 0) ? 1 : 0);
            if (i == 0)
                pre[i] = tmp;
            else
                pre[i] = tmp + pre[i - 1];

            if (ar[i] & 1)
                ++odd;
            else
            {
                ocnt += (odd * (odd + 1)) >> 1;
                odd = 0;
            }
        }
        // debug(odd);
        if (odd != 0)
            ocnt += (odd * (odd + 1)) >> 1;
        ull two = fortwo(pre,n);
        cout << (ocnt+two) << endl;
    }
    return 0;
}