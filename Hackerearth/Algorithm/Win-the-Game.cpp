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
    int t,r,g;
    cin>>t;
    double ans = 0,total = 0;
    while(t--){
        cin>>r>>g;
        ans = 0;
        if(r == 0 || g == 0){
            ans = 1;
        }else{
            int i = 0;
            while (true)
            {
                double red = r,green = g,res = 1;
                total = red + green;
                
                if(green - i > 0)
                    for(int j=0;j<i;++j){
                        res *= (green / total);
                        // cout<<green<<"/"<<total<<endl;
                        --green;
                        total = red + green;
                    }
                else break;
                if(red == total) break;
                res *= (red / total);
                ans += res;
                // cout<<red<<"/"<<total<<endl<<endl;
                i += 2;
            }
        }
        printf("%lf\n",ans);
    }   
    return 0;
}