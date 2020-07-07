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

bool mys(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}
bool opm(const pair<ll, int> &a, const pair<ll, int> &b)
{
    return a.first < b.first;
}

template <typename T>
int first_element(vector<T> &rank, T &se)
{
    int l = 0, r = rank.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if ((mid == 0 || (se > rank[mid - 1])) && rank[mid] == se)
        {
            return mid;
        }
        else if (se > rank[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int qfirst_element(vector<pair<int, int>> &rank, int &se)
{
    int l = 0, r = rank.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if ((mid == 0 || (se > rank[mid - 1].first)) && rank[mid].first == se)
        {
            return mid;
        }
        else if (se > rank[mid].first)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}


int main()
{
    FASTIO;
#ifdef NAVONIL
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n, k;
    cin >> n >> k;

    vector<ll> orig;
    vector<ll> rank;
    int a, b;
    ll tmp;
    loop(i, n)
    {
        cin >> tmp;
        orig.push_back(tmp);
        rank.push_back(tmp);
    }
    sort(rank.begin(), rank.end());
    vector<pair<int, int>> quar;
    loop(j, k)
    {
        cin >> a >> b;
        if (a > b)
        {
            swap(a, b);
        }
        quar.push_back(make_pair(a, b));
        quar.push_back(make_pair(b, a));
    }
    sort(quar.begin(), quar.end(), mys);

 
    loop(i, n)
    {
        int pos = first_element<ll>(rank, orig[i]);

        if (pos > 0)
        {
            int tmp = i + 1;
            int qpos = qfirst_element(quar, tmp);
            if (qpos >= 0)
            {
                while (qpos < (2 * k) && quar[qpos].first == (i + 1))
                {
                    int part = quar[qpos].second - 1;
                    if (orig[part] < orig[i])
                    {
                        --pos;
                    }
                    ++qpos;
                }
            }
        }
        cout << pos << ' ';
    }
    cout << endl;

#ifdef NAVONIL
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
    return 0;
}