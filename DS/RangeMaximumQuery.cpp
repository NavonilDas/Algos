#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class Segment
{
public:
    int lo, hi;
    int data;
    int delta; // For Lazy Propogation;
    Segment()
    {
        lo = hi = data = delta = 0;
    }
};

class SegmentTree
{
private:
    vector<Segment> tree;
    int n;
    void update(int n)
    {
        // Modify Update Function
        tree[n].data = max(
            tree[2 * n].data + tree[2 * n].delta,
            tree[2 * n + 1].data + tree[2 * n + 1].delta);
    }
    // For Lazy Propogation
    void propogation(int n)
    {
        tree[2 * n].delta += tree[n].delta;
        tree[2 * n + 1].delta += tree[n].delta;
        tree[n].delta = 0;
    }
    void init(int p, int l, int r, vector<int> &ar)
    {
        tree[p].lo = l;
        tree[p].delta = 0;
        tree[p].hi = r;
        if (l == r)
        {
            tree[p].delta = 0;
            tree[p].data = ar[l];
            return;
        }
        int m = (l + r) >> 1; // (l+r)/2
        init(2 * p, l, m, ar);
        init(2 * p + 1, m + 1, r, ar);
        update(p);
    }
    void init(int p, int l, int r)
    {
        tree[p].lo = l;
        tree[p].hi = r;

        if (l == r)
        {
            tree[p].data = 0;
            return;
        }
        int m = (l + r) >> 1; // (l+r)/2
        init(2 * p, l, m);
        init(2 * p + 1, m + 1, r);
        update(p);
    }
    void increment(int p, int &qL, int &qR, int &val)
    {
        // Check No Overlap
        if (qR < tree[p].lo || qL > tree[p].hi)
            return;
        // Full Overlap
        // if my tree range inside query range
        if (qL <= tree[p].lo && tree[p].hi <= qR)
        {
            tree[p].delta += val;
            return;
        }
        propogation(p);
        increment(2 * p, qL, qR, val);
        increment(2 * p + 1, qL, qR, val);
        update(p);
    }
    int maximum(int p, int &qL, int &qR)
    {
        // Check No Overlap
        if (qR < tree[p].lo || qL > tree[p].hi)
            return INT_MIN;
        // Full Overlap
        // if my tree range inside query range
        if (qL <= tree[p].lo && tree[p].hi <= qR)
            return tree[p].data + tree[p].delta;
        propogation(p);
        int left = maximum(2 * p, qL, qR);
        int right = maximum(2 * p + 1, qL, qR);
        update(p);
        return max(left, right);
    }

public:
    // n is the size of array
    SegmentTree(int size)
    {
        n = size;
        tree = vector<Segment>(4 * n + 1, Segment());
    }
    void debug()
    {
        for (auto z : tree)
            cout << z.lo << "-" << z.hi << " " << z.data << endl;
        cout << "#\n";
    }
    void init(vector<int> &ar)
    {
        init(1, 0, ar.size() - 1, ar);
    }
    void init()
    {
        init(1, 0, n - 1);
    }
    // Find minimum in range
    int maximum(int l, int r)
    {
        return maximum(1, l, r);
    }
    void change(int l, int r, int val)
    {
        increment(1, l, r, val);
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> ar[i];
    }
    SegmentTree st(n);
    st.init(ar);
    // st.init();
    int q;
    cin >> q;
    while (q--)
    {
        int t, u, v, val;
        cin >> t >> u >> v;
        if (t == 2)
        {
            cin >> val;
            st.change(u, v, val);
        }
        else
        {
            cout << st.maximum(u, v) << endl;
        }
    }
    return 0;
}