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
    int t,n,g,p;
    cin>>t;
    while(t--){
        cin>>g>>p>>n;
        int a,b,cost= 0;
        int prob1 = 0,prob2 = 0;
        while(n--){
            cin>>a>>b;
            if(a == 1) ++prob1;
            if(b == 1) ++prob2;
        }
        int ans = min(prob1,prob2) * max(g,p) + max(prob1,prob2) * min(g,p);
        cout<<ans<<endl;
    }
    return 0;
}