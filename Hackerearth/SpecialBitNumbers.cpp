// Navonil Das
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
bool isCon(int n){
    int x = 3;
    while(x <= n){
        if((x&n) == x) return true;
        x <<= 1;
    }
    return false;   
}



int ar[100001];
int main()
{
    FASTIO;
    #ifdef NAVONIL
    freopen("input.txt","r",stdin);
    #endif
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;++i){
        cin>>ar[i];
        if(isCon(ar[i]))
        ar[i] = 1;
        else ar[i] = 0;
    }
    for(int i=1;i<n;++i)
        ar[i] += ar[i-1];
    int l,r;
    while(q--){
        cin>>l>>r;
        --l,--r;
        if(l == 0)
            cout<<ar[r]<<endl;
        else
            cout<<(ar[r] - ar[l-1])<<endl;
    }
    return 0;
}