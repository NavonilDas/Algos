// Har Har Mahadev
// By Navonil Das
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
#define from(i, a, b) for (int i = a; i <= b; ++i)
#define loop(i, n) for (int i = 0; i < n; ++i)
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
void mul(ull a[3][3], ull b[3][3], ull c[3][3])
{
    loop(i, 3)
    {
        loop(j, 3)
        {
            c[i][j] = 0;
            loop(k, 3)
            {
                c[i][j] = (c[i][j] % MOD + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }
}
void print(ull a[3][3])
{
    loop(i, 3)
    {
        loop(j, 3)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void cp(ull a[3][3],ull b[3][3])
{
    loop(i, 3)
    {
        loop(j, 3)
        {
            a[i][j] = b[i][j];
        }
    }
}

ull dp[60][3][3];
int main()
{
    FASTIO;
#ifdef NAVONIL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    dp[0][0][2] = 1;
    dp[0][1][0] = 1;
    dp[0][1][1] = 0;
    dp[0][1][2] = 0;
    dp[0][2][0] = 0;
    dp[0][2][1] = 1;
    dp[0][2][2] = 0;
    from(i, 1, 59)
    {
        mul(dp[i - 1], dp[i - 1], dp[i]);
    }
    // print(dp[0]);
    // print(dp[1]);
    // print(dp[2]);
    cout << (ull)(1e18 + 1) << endl;

    ull n;
    ull tmp[3][3],res[3][3];        
    till(t)
    {
        cin >> n;
        res[0][0] = 1;res[0][1] = 0;res[0][2] = 0;
        res[1][0] = 0;res[1][1] = 1;res[1][2] = 0;
        res[2][0] = 0;res[2][1] = 0;res[2][2] = 1;
        
        tmp[0][0] = 1;tmp[0][1] = 0;tmp[0][2] = 0;
        tmp[1][0] = 0;tmp[1][1] = 1;tmp[1][2] = 0;
        tmp[2][0] = 0;tmp[2][1] = 0;tmp[2][2] = 1;

        from(i, 0, 59)
        {
            if ((n >> i) & 1){
                mul(dp[i],res,tmp);
                cp(res,tmp);
            }
        }
        cout<<res[0][0]<<endl;
        // print(res[0][0]);
    }
    return 0;
}