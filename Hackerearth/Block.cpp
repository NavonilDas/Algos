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
// #define max(a,b) ((a>b)?a:b)
// change ull to ll for negative
// ull gcd(ull a,ull b){return (b==0)?a:gcd(b,a%b);}
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

using namespace std;
const int Max = 120000;

int lazy[4*Max] = {0};
int tree[4*Max] = {0};

// Print max in range of l to r
int query(int node,int start,int end,int l,int r){
    if(lazy[node] != 0){
        tree[node] = lazy[node];
        if(start != end){
            lazy[2*node + 1] = lazy[node];
            lazy[2*node + 2] = lazy[node];
        }
        lazy[node] = 0;
    }
    // no overlap
    if(l > end || r < start)
        return 0;
    
    if(l<=start && r >= end)
        return tree[node];
    
    int mid = (start + end) >> 1;
    return max(
        query(2*node+1,start,mid,l,r),
        query(2*node+2,mid+1,end,l,r)
    );
}
// Update from l to r
void update(int node,int start,int end,int l,int r,int val){
    if(node >= 4*Max){
        cout<<"yes";
    }
    if(lazy[node] != 0){
        tree[node] = lazy[node];
        if(start != end){
            lazy[2*node + 1] = lazy[node];
            lazy[2*node + 2] = lazy[node];
        }
        lazy[node] = 0;
    }
    // no overlap
    if(l > end || r < start)
        return;
    // overlap
    if(l<=start && r >= end){
        tree[node] = val;

        if(start != end){
            lazy[2*node + 1] = val;
            lazy[2*node + 2] = val;
        }
        return;
    }
    int mid = (start + end) >> 1;
    update(2*node+1,start,mid,l,r,val);
    update(2*node+2,mid+1,end,l,r,val);
    tree[node] = max(tree[2*node+1],tree[2*node+2]);
}

void solve(int l,int h,int p,const int &c,int x){
    int y = x + l - 1; // x + y
    int meet = x + p - 1;

    int high = query(0,0,Max - 1,x,y);
    if(c == 1){
        /// Upside
        update(0,0,Max-1,x,y,1+high); 
        update(0,0,Max-1,meet,meet,1+h+high); 
    }else{
        //// down
        int atThat = query(0,0,Max-1,meet,meet);
        high = max(high,atThat+h);
        update(0,0,Max-1,x,y,high+1);
    }
}

int main()
{
    FASTIO;
    #ifdef NAVONIL
    freopen("input.txt","r",stdin);
    #endif
    int n;
    cin>>n;
    int l,h,p,c,x;
    // memset(tree,0,4*Max);
    // memset(lazy,0,4*Max);
    while(n--){
        cin>>l>>h>>p>>c>>x;
        cout<<l<<" "<<h<<" "<<p<<" "<<c <<" "<<x<<endl;
        solve(l,h,p,c,x);
    }
    cout<<tree[0]<<endl;
    return 0;
}