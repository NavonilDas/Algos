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
    priority_queue<int> pq;
    int m,n,a;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a;
        pq.push(a);
    }
    ll cost = 0;
    while(m--){
        int t = pq.top();
        pq.pop();
        cost += t;
        pq.push(--t);
    }
    cout<<cost<<endl;
    return 0;
}