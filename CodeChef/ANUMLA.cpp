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
int ar[65536];
// int sums[65536];
// int ans[16];

int main()
{
    FASTIO;
#ifdef NAVONIL
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    till(t)
    {
        cin >> n;
        int pw = 1 << n;
        loop(i, pw)
        {
            cin >> ar[i];
        }
        sort(ar, ar + pw);
        multiset<int> sumSet;
        vi ans;
        vi sums;
        // skip 0
        for (int i = 1; i < pw; ++i)
        {
            int expect = -1;
            if (!sumSet.empty())
            {
                expect = *sumSet.begin();
            }
            if (ar[i] == expect)
            {
                // just remove the first element
                sumSet.erase(sumSet.begin());
            }
            else
            {
                ans.push_back(ar[i]);
                // ans.back()
                int l = sums.size();
                loop(j, l)
                {
                    int k = sums[j] + ar[i];
                    sums.push_back(k);
                    sumSet.insert(k);
                }
                sums.push_back(ar[i]);
            }
        }
        for (int a : ans)
            cout << a << ' ';
        cout<<endl;
    }
#ifdef NAVONIL
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
    return 0;
}