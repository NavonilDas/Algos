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
// For no of bits till n
void solve(int *ar,int i){
    int x = floor(log2(i));
    ar[i] = ar[i-(1<<x)] + 1;
}

ull test(ull n){
    if(n <= 1) return n;
    ull x = log2(n);
    ull y = (1 << x);
    return x*(1 << (x-1)) + test(n - y) + n - y + 1;
}

int main()
{
    FASTIO;
    #ifdef NAVONIL
    freopen("input.txt","r",stdin);
    #endif
    // For no of bits till n
    // int N[10000];
    // memset(N,-1,10000);
    // N[0] = 0;N[1] = 1;
    // for(int i=0;i<=15;++i){
    //     if(N[i] == -1)
    //         solve(N,i);
    //     cout<<N[i]<<endl;
    // }
    cout<<test(63)<<endl;
    return 0;
}