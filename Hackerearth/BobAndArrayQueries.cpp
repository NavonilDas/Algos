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
// change ull to ll for negative
// ull gcd(ull a,ull b){return (b==0)?a:gcd(b,a%b);}
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

using namespace std;
const int MAX = 500001;
int tree[4 * MAX];
// void build(int node, int start, int end)
// {
//     if(start == end){
//         tree[node] = 0;
//         return;
//     }

// }

void update1(int node, int start, int end, int index)
{
    if (start == end)
    {
        ++tree[node];
        return;
    }
    int mid = (start + end) >> 1;
    if (index >= start && index <= mid)
        update1(2 * node + 1, start, mid, index);
    else
        update1(2 * node + 2, mid + 1, end, index);
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

void update2(int node, int start, int end, int index)
{
    if (start == end)
    {
        if (tree[node])
            --tree[node];
        return;
    }
    int mid = (start + end) >> 1;
    if (index >= start && index <= mid)
        update2(2 * node + 1, start, mid, index);
    else
        update2(2 * node + 2, mid + 1, end, index);
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

int query(int node, int start, int end, int l, int r)
{
    if (l > end || r < start)
        return 0;
    if (l <= start && r >= end)
        return tree[node];
    int mid = (start + end) >> 1;
    return query(2 * node + 1, start, mid, l, r) +
           query(2 * node + 2, mid + 1, end, l, r);
}

int main()
{
    FASTIO;
#ifdef NAVONIL
    freopen("input.txt", "r", stdin);
#endif
    int n, q, typ, a, b;
    cin >> n >> q;
    while (q--)
    {
        cin >> typ;
        if (typ == 1)
        {
            cin >> a;
            update1(0,0,n-1,a-1);
        }
        else if (typ == 2)
        {
            cin >> a;
            update2(0,0,n-1,a-1);
        }
        else
        {
            cin >> a >> b;
            // cout<<a<<" "<<b<<endl;
            cout<<query(0,0,n-1,a-1,b-1)<<endl;
        }
    }
    return 0;
}