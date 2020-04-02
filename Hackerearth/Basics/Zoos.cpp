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
    freopen("input.txt", "r", stdin);
#endif
    int z = 0, o = 0;
    char x;
    do
    {
        x = getchar();
        if(x == 0 || x == '\n' || x == -1) break;
        if(x == 'Z' || x == 'z') ++z;
        if(x == 'O' || x == 'o') ++o;
    } while (true);
    if(z*2 == o)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}