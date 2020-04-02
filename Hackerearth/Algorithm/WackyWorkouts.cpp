// Har Har Mahadev
// By Navonil Das
#include <bits/stdc++.h>
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define endl '\n'
#define ll long long
#define ull long long
#define vi vector<int>

// change ull to ll for negative
// ull gcd(ull a,ull b){return (b==0)?a:gcd(b,a%b);}
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #include <boost/multiprecision/cpp_int.hpp>
// using boost::multiprecision::cpp_int;
using namespace std;
int MOD = 1e9 + 7;
bool debug = false;
/// MATRIX Exponential
void mul(ull a[2][2], ull b[2][2], ull c[2][2])
{
    c[0][0] = ((a[0][0] * b[0][0]) % MOD + (a[0][1] * b[1][0]) % MOD) % MOD;
    c[0][1] = ((a[0][0] * b[0][1]) % MOD + (a[0][1] * b[1][1]) % MOD) % MOD;

    c[1][0] = ((a[1][0] * b[0][0]) % MOD + (a[1][1] * b[1][0]) % MOD) % MOD;
    c[1][1] = ((a[1][0] * b[0][1]) % MOD + (a[1][1] * b[1][1]) % MOD) % MOD;
}

void add(int a[2][2], int b[2][2], int c[2][2])
{
    c[0][0] = (a[0][0] + b[0][0]) % MOD;
    c[0][1] = (a[0][1] + b[0][1]) % MOD;
    c[1][0] = (a[1][0] + b[1][0]) % MOD;
    c[1][1] = (a[1][1] + b[1][1]) % MOD;
}

int main()
{
    FASTIO;
#ifdef NAVONIL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ull dp[61][2][2];
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    dp[0][1][0] = 1;
    dp[0][1][1] = 0;
    dp[1][0][0] = 2;
    dp[1][0][1] = 1;
    dp[1][1][0] = 1;
    dp[1][1][1] = 1;

    for (int i = 2; i <= 60; ++i)
    {
        mul(dp[i - 1], dp[i - 1], dp[i]);
    }
    debug = true;
    // cout << dp[3][0][0] << " " << dp[3][0][1] << endl;
    // cout << dp[3][1][0] << " " << dp[3][1][1] << endl;
    int t;
    cin >> t;
    ull n;
    while (t--)
    {
        cin >> n;
        ull res[2][2] = {1, 0, 0, 1},tmp[2][2] = {0,0,0,0};
        for (int i = 60; ~i; --i)
        {
            if ((n >> i) & 1)
            {
                // cout << dp[i][0][0] << " " << dp[i][0][1] << endl;
                // cout << dp[i][1][0] << " " << dp[i][1][1] << endl;
                // // cout<<i<<endl;
                mul(res, dp[i], tmp);
                res[0][0] = tmp[0][0];
                res[0][1] = tmp[0][1];
                res[1][0] = tmp[1][0];
                res[1][1] = tmp[1][1];
            }
        }
        // cout << res[0][0] << " " << res[0][1] << endl;
        // cout << res[1][0] << " " << res[1][1] << endl;
        cout<<((res[0][0]+res[0][1])%MOD)<<endl;
    }
    return 0;
}