#include <bits/stdc++.h>
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define ll long long
#define ull long long
#define vi vector<int>

using namespace std;

vi tree;
vi ar;

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree.at(node) = ar.at(start);
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);

        tree.at(node) = min(
            tree.at(2 * node + 1),
            tree.at(2 * node + 2));
    }
}

void update(int node, int start, int end, const int &index, const int &value)
{
    if (start == end)
    {
        tree.at(node) = value;
    }
    else
    {
        int mid = (start + end) / 2;
        if (index >= start && index <= mid)
            update(2 * node + 1, start, mid, index, value);
        else
            update(2 * node + 2, mid + 1, end, index, value);
        tree.at(node) = min(tree.at(2 * node + 1), tree.at(2 * node + 2));
    }
}

int query(int node, int start, int end, const int &l, const int &r)
{

    // Complete overlap
    if (l <= start && end <= r)
    {
        return tree.at(node);
    }

    // do not overlap
    if (l > end || r < start)
    {
        return INT_MAX;
    }
    int mid = (start + end) / 2;
    return min(
        query(2 * node + 1, start, mid, l, r),
        query(2 * node + 2, mid + 1, end, l, r));
}

int main()
{
    FASTIO;
    int n, q;
    cin >> n >> q;
    ar = vector<int>(n);
    int x = ceil(log2(n));
    x = 2 * (1 << x) - 1;
    tree = vector<int>(x);

    for (int i = 0; i < n; ++i)
        cin >> ar[i];

    build(0, 0, n - 1);
    char ch;
    int i, j;
    while (q--)
    {
        cin >> ch >> i >> j;
        if (ch == 'u')
            update(0, 0, n - 1, i - 1, j);
        else
            cout << query(0, 0, n - 1, i - 1, j - 1) << endl;
    }
    return 0;
}