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
    FASTIO;
#ifdef NAVONIL
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, a, z = 0;
    cin >> n;
    vi dig;
    loop(i, n)
    {
        cin >> a;
        if (a == 0)
        {
            ++z;
        }
        else
            dig.pb(a);
    }

    if (z == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        n = dig.size();
        // cout << n << "\n\n\n";
        int start = 0, end = 0;
        sort(dig.begin(), dig.end(), greater<int>());
        ll sum = 0;
        loop(i, n)
        {
            // cout << dig[i] << ",";
            sum += dig[i];
            if (sum % 9 == 0)
            {
                end = i;
            }
        }

        if (end != 0)
        {
            string ans = "";
            for (int i = 0; i <= end; ++i)
            {
                ans += (dig[i] + '0');
            }
            if (ans.empty())
            {
                ans = "0";
            }
            else
            {
                while (z--)
                {
                    ans += '0';
                }
            }
            cout << ans << endl;
            // cout << ans.substr(ok) << endl;
        }
        else
        {
            end = n;
            start = n;
            loop(i, n)
            {
                sum -= dig[i];
                if (sum % 9 == 0)
                {
                    start = i + 1;
                    break;
                }
            }
            string ans = "";
            for (int i = start; i < end; ++i)
            {
                ans += '0' + dig[i];
            }

            if (ans.empty())
            {
                ans = "0";
            }
            else
            {
                while (z--)
                {
                    ans += '0';
                }
            }
            cout << ans << endl;
        }
    }
#ifdef NAVONIL
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
    return 0;
}