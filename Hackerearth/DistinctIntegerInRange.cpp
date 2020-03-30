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
#define crap bitset<5001>

crap treeA[400004], treeB[400004];
int A[100001], B[100001];

void build(int node, int start, int end)
{
    if (start == end)
    {
        treeA[node][A[start]] = 1;
        treeB[node][B[start]] = 1;
        return;
    }
    int mid = (start + end) >> 1;
    build(2 * node + 1, start, mid);
    build(2 * node + 2, mid + 1, end);
    treeA[node] = treeA[(node << 1) | 1] | treeA[(node << 1) + 2];
    treeB[node] = treeB[(node << 1) | 1] | treeB[(node << 1) + 2];
}

crap count(int node, int start, int end, const int &l, const int &r, crap *tree)
{
    /// No overlap
    if (l > end || r < start)
        return crap(0);
    // Complete overlap
    if (l <= start && r >= end)
    {
        return tree[node];
    }
    int mid = (start + end) >> 1;
    return (
        count((node << 1) | 1, start, mid, l, r, tree) |
        count(2 * node + 2, mid + 1, end, l, r, tree));
}

int solve(int a, int b, int x, int y, const int &n)
{
    return (
               count(0, 0, n - 1, a, b, treeA) |
               count(0, 0, n - 1, x, y, treeB))
        .count();
}

int main()
{
    FASTIO;
#ifdef NAVONIL
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> A[i];

    for (int i = 0; i < n; ++i)
        cin >> B[i];

    build(0, 0, n - 1);

    int q, a, b, x, y;
    cin >> q;
    while (q--)
    {
        cin >> a >> b >> x >> y;
        cout << solve(a - 1, b - 1, x - 1, y - 1, n) << endl;
    }
    return 0;
}