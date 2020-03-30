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
int main()
{
    FASTIO;
    #ifdef NAVONIL
    freopen("input.txt","r",stdin);
    #endif
    int n;
    cin>>n;
    bool *visited = new bool[n];
    memset(visited,0,n);
    int a;
    for(int i=0;i<n;++i){
        cin>>a;
        visited[a-1] = true;
    }
    for(int i=0;i<n;++i)
        if(!visited[i])
            cout<<(i+1)<<" ";
   	delete visited;
    return 0;
}