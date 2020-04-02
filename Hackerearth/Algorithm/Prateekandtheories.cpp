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
    // Find the point where maximum intervals overlap
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        vector<int> entry(n), exit(n);
        while (n--)
        {
            cin >> entry[n] >> exit[n];
        }
        sort(entry.begin(), entry.end());
        sort(exit.begin(), exit.end());
        int Max = 1,cnt = 1,i = 1,j = 0;
        n = entry.size();
        while(i < n && j < n){
            if(entry[i] < exit[j]){
                ++cnt;
                Max = max(Max,cnt);
                ++i;
            }else{
                --cnt;
                ++j;
            }
        }
        cout<<Max<<endl;
    }
    return 0;
}