#include <bits/stdc++.h>
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define endl '\n'
#define ll long long
#define ull long long
#define vi vector<int>
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

using namespace std;
int main()
{
    FASTIO;
    bool vowels[256] = {false};
    vowels['a'] = vowels['e'] = vowels['i'] = vowels['o'] = vowels['u'] = true;
    vowels['A'] = vowels['e'] = vowels['I'] = vowels['O'] = vowels['U'] = true;
    ull v,c;
    int t;
    cin>>t;
    string a;
    while(t--){
        cin>>a;
        v = 0;
        for(int i=0;i<(int)a.size();++i)
            if(isalpha(a[i]) && vowels[(int)a[i]]) ++v;
        c = a.size()-v;
        a.clear();
        cout<<v<<" "<<c<<" "<<(v*c)<<endl;
    }
    return 0;
}