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
int ar[100001];
ll rec(int *ar, const int &k, int n,ll sum = 0, int no_pearls = 0, int ele = 0)
{
    if (no_pearls == k || no_pearls == -k || ele >= n)
        return sum;
    
    ll a = rec(ar, k, sum - ar[ele], no_pearls + 1, ele + 1); // Buy
    ll b = rec(ar, k, sum, no_pearls, ele + 1);               // do nothing
    ll c = 0;
    if (no_pearls > 0)
        rec(ar, k, sum + ar[ele], no_pearls - 1, ele + 1); // sell
    return max(max(a,b), c);
}

int main()
{
    FASTIO;
#ifdef NAVONIL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    ll profit = 0,Min = INT_MAX;
    for(int x:ar){
        if(Min > x) Min = x;
        profit = max(profit,k*(x - Min));
    }
    cout<<profit<<endl;
    return 0;
}