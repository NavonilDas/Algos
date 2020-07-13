#include <bits/stdc++.h>
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define endl '\n'
#define ll long long
#define ull long long
#define vi vector<int>

using namespace std;
int main()
{
    FASTIO;
    priority_queue<int> pq;
    int n,f;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>f;
        pq.push(f);
        if(i>=2){
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            ll c = pq.top();
            pq.pop();
            cout<<(a*b*c)<<endl;
            pq.push(a);
            pq.push(b);
            pq.push(c);
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}