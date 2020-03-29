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
const int Max = 1000001;
int tree[4 * Max];
bool values[Max];
void build(int node, int start, int end)
{
    if (start == end)
    {
        // cout<<start<<endl;
        tree[node] = 1;
        return;
    }
    int mid = (start + end) >> 1;
    build(2 * node + 1, start, mid);
    build(2 * node + 2, mid + 1, end);

    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

void update(int node, int start, int end, int index)
{
    if (start == end)
    {
        tree[node] = 0;
        return;
    }
    int mid = (start + end) >> 1;
    if (index >= start && index <= mid)
        update(2 * node + 1, start, mid, index);
    else
        update(2 * node + 2, mid + 1, end, index);

    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

int query(int node, int start, int end, int k)
{
    if (start == end)
        return end;

    // if (tree[node] == k)
    //     return end;
    int mid = (start + end) >> 1;
    int left = 2 * node + 1;
    int right = 2 * node + 2;
    if (tree[left] >= k)
        return query(left, start, mid, k);
    return query(right, mid + 1, end, k - tree[left]);
}
 // Guarntee To Solve
// int g(int n, int k)
// {
//     int c = 0;
//     for (int i = 0; i < n; ++i)
//     {
//         if (!values[i])
//             ++c;
//         if (c == k)
//             return i+1;
//     }
//     return -1;
// }

int solve(int n, int k)
{
    if (tree[0] < k)
        return -1;
    return (query(0, 0, n - 1, k) + 1);
}

int main()
{
    FASTIO;
#ifdef NAVONIL
    freopen("input.txt", "r", stdin);
#endif
    int n, q;
    cin >> n >> q;
    build(0, 0, n - 1);

    bool typ;
    int nodeNo;
    while (q--)
    {
        cin >> typ >> nodeNo;
        if (!typ)
        {
            --nodeNo;
            if (!values[nodeNo])
                update(0, 0, n - 1, nodeNo);
            values[nodeNo] = true;
        }
        else
        {
            cout<<solve(n,nodeNo)<<endl;
        }
    }

    return 0;
}