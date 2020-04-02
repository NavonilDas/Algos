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
int main()
{
    FASTIO;
#ifdef NAVONIL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string a;
    cin>>a;
    int ans[10001] = {0};
    for(int i=a.size()-1;~i;--i){
        ans[i] += ans[i+1] + !(a[i]&1);
    }

    for(int i=0;i<a.size();++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}