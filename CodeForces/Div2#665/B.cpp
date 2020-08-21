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
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)
#define from(i, a, b) for (int i = (a); i <= (b); ++i)
#define dloop(i, n) for (int i = n; ~i; --i)
#define debug(x1) cout << #x1 << ": " << x1 << endl;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v.size()))
#define pii pair<int, int>
#define pll pair<ll, ll>

// int cse = 1;
// #define google(a) cout << "Case #" << (cse++) << ": " << a << endl;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
    FASTIO;
#ifdef NAVONIL
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int zro1, zro2, on1, on2, tw1, tw2;
    till(t)
    {
        int ans = 0;
        cin >> zro1 >> on1 >> tw1;
        cin >> zro2 >> on2 >> tw2;

        int t = min(tw1, on2);
        tw1 -= t;
        on2 -= t;
        ans += t * 2;
        // 2 -> o's
        t = min(tw1, tw2);
        tw1 -= t;
        tw2 -= t;
        // 2-> 2's
        t = min(tw1, zro2);
        tw1 -= t;
        zro2 -= t;
        // By Now all 2 has been removed from one set
        t = min(on1, zro2);
        on1 -= t;
        zro2 -= t;
        t = min(on1, on2);
        on1 -= t;
        on2 -= t;
        // Remove all zeroes
        t = min(zro1, on2);
        zro1 -= t;
        on2 -= t;
        t = min(zro1, tw2);
        zro1 -= t;
        tw2 -= t;
        t = min(zro1, zro2);
        zro1 -= t;
        zro2 -= t;
        // By Now all zeroes are removed
        if (on1 && tw2)
        {
            ans -= 2 * on1;
        }
        cout << ans << endl;
        // cout << zro1 << " " << on1 << " " << tw1 << " " << ans << endl;
        // cout << zro2 << " " << on2 << " " << tw2 << endl;
    }

#ifdef NAVONIL
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
    return 0;
}