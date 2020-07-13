#include <bits/stdc++.h>
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define endl '\n'
#define ll long long
#define ull long long
#define vi vector<int>

struct post{
    ll id,diffs,ns;
    bool operator()(post &a,post &b){
        if(a.diffs == b.diffs)
            return a.id < b.id;

        return a.diffs < b.diffs;
        
    }
};

using namespace std;
int main()
{
    FASTIO;
    priority_queue<post,vector<post>,post> pq;
    int n,nn;
    ll id,z,p,l,c,s;
    cin>>n;
    nn= n;
    while(n--){
        cin>>id>>z>>p>>l>>c>>s;
        ll nz = p*50 + l*5 + c*10 + s * 20;
        // cout<<id<<" "<<z<<" "<<nz<<" "<<(nz-z)<<endl;
        post tmp;
        tmp.id = id;
        tmp.ns = nz;
        tmp.diffs = nz-z;
        pq.push(tmp);
    }
    // cout<<endl;
    int k = min(5ll,(ll)nn);
    while(k--){
        auto y = pq.top();
        pq.pop();
        cout<<y.id<<" "<<y.ns<<endl;
    }
    return 0;
}