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
    int t;
    cin>>t;
    int hash1[256] = {0},hash2[256] = {0};
    while(t--){
        string a,b;
        cin>>a>>b;
        for(int c:a)
            ++hash1[c];

        for(int c:b)
            ++hash2[c];
        int dele = 0;
        for(int i=0;i<256;++i){
            dele += abs(hash1[i] - hash2[i]);
            hash1[i] = 0;
            hash2[i] = 0;
        }
        cout<<dele<<endl;
    }
    return 0;
}