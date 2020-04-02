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

using namespace std;
int main()
{
    FASTIO;
    #ifdef NAVONIL
    freopen("input.txt","r",stdin);
    #endif
    int l,r,k;
    cin>>l>>r>>k;
    int div = (l-1) / k;
    div = (r / k) - div;
    // for(int i=l;i<=r;++i)
    //     if(i%k == 0)
    //         ++div;
    cout<<div<<endl;
    return 0;
}