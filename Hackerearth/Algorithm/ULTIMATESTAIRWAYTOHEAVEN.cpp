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
#define mp make_pair
// change ull to ll for negative
// ull gcd(ull a,ull b){return (b==0)?a:gcd(b,a%b);}
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #include <boost/multiprecision/cpp_int.hpp>
// using boost::multiprecision::cpp_int;
using namespace std;
// ull rec(int *ar, int n, int cur)
// {
//     ull ans = 0;
//     if (cur == n - 1)
//         return 1;
//     if (cur >= n)
//         return 0;
//     if (dp[cur])
//         return dp[cur];
//     for (int i = min(ar[cur], n); i >= 1; --i)
//     {
//         if (ar[cur + i] == 0 || cur + i >= n)
//             continue;
//         ans += rec(ar, n, cur + i);
//         ans = ans % MOD;
//     }
//     return (dp[cur] = ans);
// }
// ll itr(int *a, int n)
// {
//     // ll ad[100001] = {0};
//     // ll sum = 0;
//     // ad[0] = 1; // Base Case
//     // for(int i=1;i<=n-1;++i){
//     //     ad[i] = (ad[i]+ad[i-1])%MOD;

//     //     if(i + ar[i] < n)
//     //         ad[i] = (MOD + ad[i + ar[i]] - ad[i-1])%MOD;
//     //     sum = (sum + ad[i])%MOD;
//     //     ad[i] = sum;
//     // }

//     // return ad[n-1];
//     int dp[100001] = {0};
//     // memset(dp, 0, 100001);
//     dp[0] = 1;
//     long long int sum = 0;
//     long long int mod = 1000000007;
//     for (int i = 0; i < n - 1; i++)
//     {
//         dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
//         if (i + 1 + a[i] < n)
//             dp[i + 1 + a[i]] = (mod + dp[i + 1 + a[i]] - dp[i]) % mod;
//         sum = (sum + dp[i + 1]) % mod;
//         dp[i + 1] = sum;
//     }
//     // for(int i=0;i<n;++i)
//     //     cout<<dp[i]<<" ";
//     // cout<<endl;
//     return dp[n - 1];
//     // vector<ull> prev(n,0);
//     // vector<bool> curr(n,false);
//     // if(n == 1) return 1;
//     // for(int i=n-2;~i;--i){
//     //     if(ar[i]+i >= n-1) curr[i] = true;
//     // }
//     // for(int i=n-2;~i;--i){
//     //     if(ar[i] == 0) continue;
//     //         for(int j=1;j<=min(ar[i],n) && i+j < n;++j){
//     //             prev[i] += prev[i+j];
//     //         }
//     //     prev[i] += curr[i];
//     // }
//     // // for(bool x:curr)
//     // //     cout<<x<<" ";
//     // // cout<<endl;
//     // // for(int x:prev)
//     // //     cout<<x<<" ";
//     // // cout<<endl;

//     // return prev[0];
// }

int MOD = 1e9 + 7;
ull sums[100001];
ull ans[100001];
int ar[100001];

int main()
{
    FASTIO;
#ifdef NAVONIL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    ull sum = 0;
    sums[n - 1] = ans[n - 1] = 1;
    for (int i = n - 2; ~i; --i)
    {
        if (ar[i] + i >= n)
            ans[i] = sums[i + 1] % MOD;
        else
            ans[i] = (sums[i + 1] - sums[i + ar[i] + 1] + MOD) % MOD;

        sums[i] = (sums[i + 1] % MOD + ans[i] % MOD) % MOD;
    }
    cout << ans[0] << endl;
    return 0;
}