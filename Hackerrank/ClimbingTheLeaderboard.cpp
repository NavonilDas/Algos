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
#define loop(i, n) for (int i = 0; i < n; ++i)
#define from(i, a, b) for (int i = a; i <= b; ++i)
#define dloop(i, n) for (int i = n, ~i; --i)
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
int bsearch(vi &ar, int &val)
{
    int l = 0, r = sz(ar) - 1, mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (ar[mid] == val)
            return mid;

        if (ar[mid] < val)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}
int main()
{
    // clock_t tStart = clock();
    FASTIO;
#ifdef NAVONIL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n;
    vi ar(n);
    loop(i, n)
    {
        cin >> ar[i];
    }
    cin >> k;
    vi pos(k);

    loop(i, k)
    {
        cin >> pos[i];
    }
    vi rank(n);
    sort(all(ar), greater<int>());
    rank[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        if (ar[i] == ar[i - 1])
            rank[i] = rank[i - 1];
        else
            rank[i] = 1 + rank[i - 1];
    }
    // cout << rank[5] << endl;
    loop(i, k)
    {
        int z = bsearch(ar, pos[i]);
        if (z == n)
        {
            cout << (rank[n - 1] + 1) << endl;
            continue;
        }
        if (ar[z] == pos[i])
            cout << rank[z] << endl;
        else if (ar[z] > pos[i])
            cout << (rank[z] + 1) << endl;
        else
            cout << rank[z]<< endl;
        // cout << pos[i] << " " << z << endl;

        // auto z = upper_bound(all(ar), pos[i]);
        // cout <<pos[i]<<" "<< (z - ar.begin())<<endl;
    }
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}