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
    short opposite[109] = {0};
    short side[109] = {0};
    string a[] = {"WS", "MS", "AS"};
    for (int i = 1; i <= 97; i += 12)
    {
        for (int j = 0; j < 3; ++j)
        {
            opposite[i + j] = i + 11 - j; opposite[i + 11 - j] = i + j;
            side[i + j] = j;
            side[i + 9 + j] = 2-j;

            side[i + 6 + j] = j;
            side[i + 3 + j] = 2-j;
            
            opposite[i + 6 + j] = i + 5 - j;
            opposite[i + 5 - j] = i + 6 + j;
        }
    }
    short n;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout<<(int)opposite[n]<<" "<<a[side[n]]<<endl;
    }
    return 0;
}