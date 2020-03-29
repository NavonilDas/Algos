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
ll pwr(ll a, ll p, ll m)
{
    if(a == 1) return 1;
    ll ret = 1;
    a = a%m;
    while (p > 0)
    {
        if (p & 1)
            ret = (ret*a) % m;
        a = (a * a)%m;
        p >>= 1;
    }
    return ret%m;
}

bool millerTest(ll d,ll no){
    ll a = rand()%(no-4) + 2;
    ll x = pwr(a,d,no); // a^d mod no
    // cout<<x<<endl;
    if(x == 1 || x == no-1) return true;
    while (d != no-1) 
    { 
        x = (x * x) % no; 
        d *= 2; 
  
        if (x == 1)      return false; 
        if (x == no-1)    return true; 
    } 
    return false;
}

bool primeTest(const ll no,int itr){
    if(no < 2 || !(no&1)) return false;
    if(no == 2 || no == 3) return true;
    
    int k = no - 1;
    while(!(k&1)){
        k >>= 1;
    }

    while(itr--){
        if(!millerTest(k,no))
            return false;
        }
    return true;
}
int main()
{
    // FASTIO;
    int itr = 4;
    // cout<<pwr(30,2,53);
    for(int i=2;i<=100;++i)
        if(primeTest(i,itr)) cout<<i<<' ';

    return 0;
}