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

// int cse = 1;
// #define google(a) cout << "Case #" << (cse++) << ": " << a << endl;

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
void transform(string &a, int i)
{
    for (int j = 0; j < i; ++j)
    {
        if (a[j] == '0')
            a[j] = '1';
        else
            a[j] = '0';
    }
    int l = i / 2;
    for (int j = 0; j <= l; ++j)
    {
        swap(a[j], a[i - j - 1]);
    }
}
int main()
{
    FASTIO;
#ifdef NAVONIL
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    till(t)
    {
        string a, b;
        int n;
        cin >> n >> a >> b;
        if (a.compare(b) == 0)
        {
            cout << 0 << endl;
            continue;
        }
        vector<int> ans;
        // cout << a << " " << b << endl;
        for (int i = 0; i < n - 1; ++i)
        {
            if (a[i] != a[i + 1])
            {
                // cout << "Till " << (i + 1) << endl;
                ans.pb(i + 1);
            }
        }
        if (a[n - 1] != '0')
            ans.pb(n);
        // cout << "Till " << (n) << endl;
        vector<int> tmp;
        for (int i = 0; i < n - 1; ++i)
        {
            if (b[i] != b[i + 1])
            {
                // cout << "Till2 " << (i + 1) << endl;
                tmp.pb(i + 1);
            }
        }
        if (b[n - 1] != '0')
            tmp.pb(n);
        
        for (int i = tmp.size() - 1; i >= 0; --i)
            ans.pb(tmp[i]);
        tmp.clear();
        // cout << "Till2 " << (n) << endl;
        cout << ans.size() << " ";
        // cout << a << endl;
        for (int &d : ans)
        {
            cout << d << " ";
            // transform(a, d);
            // cout << a << endl;
        }
        cout << endl;
    }

#ifdef NAVONIL
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
    return 0;
}