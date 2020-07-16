// Har Har Mahadev
#include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// #include <boost/multiprecision/cpp_int.hpp>
// using boost::multiprecision::cpp_int;

using namespace std;

#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define endl '\n'
#define ll long long
#define ull long long
#define vi vector<int>
#define vt(type) vector<type>
#define mat(type) vector<vector<type>>
#define pb push_back
#define mp make_pair
#define mii map<int, int>
#define setbits(a) __builtin_popcountll(a)
#define zrobits(a) __builtin_ctzll(a)
#define MOD 1000000007
#define INF 1e18
#define pqb priority_queue<int>
#define pqs priority_queue<int, greater<int>>
#define prec(a, b) fixed << setprecision(b) << a
#define till(a) \
    int a;      \
    cin >> a;   \
    while (a--)
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)
#define from(i, a, b) for (int i = (a); i <= (b); ++i)
#define dloop(i, n) for (int i = n; ~i; --i)
#define debug(x1) cout << #x1 << ": " << x1 << endl;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v.size()))

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// change ull to ll for negative
// ull gcd(ull a,ull b){return (b==0)?a:gcd(b,a%b);}
// ull pwrm(ull a,ull p,ull m){
//     ull res = 1;
//     a = a%m;
//     while(p > 0){
//         if(p&1)
//             res = (res*a)%m;
//         a = (a*a)%m;
//         p >>=1;
//     }
//     return res%m;
// }
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// fill,copy,lower_bound,upper_bound,max_element,min_element
class DisjointSet
{
    vector<int> parent;
    vector<int> rank;
    vector<int> pow;

public:
    DisjointSet(int N)
    {
        parent = vector<int>(N);
        rank = vector<int>(N, 0);
        pow = vector<int>(N);
        for (int i = 0; i < N; ++i)
        {
            parent[i] = i;
            pow[i] = i + 1;
        }
    }
    // DisjointSet(vector<T> &Ar){

    // }
    int getPow(int i)
    {
        int ri = root(i);
        return pow[ri];
    }
    int root(int i)
    {
        while (parent[i] != i)
        {
            i = parent[i];
        }
        return i;
    }
    void Union(int i, int j)
    {
        int ri = root(i);
        int rj = root(j);
        if (ri == rj)
            return;
        if (rank[ri] < rank[rj])
        {
            parent[ri] = rj;
            pow[rj] = max(pow[ri], pow[rj]);
        }
        else if (rank[ri] > rank[rj])
        {
            parent[rj] = ri;
            pow[ri] = max(pow[ri], pow[rj]);
        }
        else
        {
            parent[rj] = ri;
            pow[ri] = max(pow[ri], pow[rj]);
            rank[ri] = rank[ri] + 1;
        }
    }
    bool find(int i, int j)
    {
        return (root(i) == root(j));
    }
};
int main()
{
    FASTIO;
#ifdef NAVONIL
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, a, b, q;
    cin >> n >> m;
    DisjointSet ds(n);
    while (m--)
    {
        cin >> a >> b;
        ds.Union(a - 1, b - 1);
    }
    cin >> q;
    while (q--)
    {
        cin >> a >> b;
        if (ds.find(a - 1, b - 1))
        {
            cout << "TIE\n";
        }
        else
        {
            int pa = ds.getPow(a - 1), pb = ds.getPow(b - 1);
            if (pa > pb)
                cout << a << endl;
            else
                cout << b << endl;
            // cout << max(ds.getPow(a - 1), ds.getPow(b - 1)) << endl;
        }
    }

#ifdef NAVONIL
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
    return 0;
}