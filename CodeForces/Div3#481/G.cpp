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
struct Activity
{
    int s, d, c;
    int i; // day
};
bool myS(const Activity &a, const Activity &b)
{
    if (a.s != b.s)
        return a.s > b.s;
    return a.d > b.d;
}
void addToStack(stack<Activity> &cur, Activity &r)
{
    if (cur.empty())
    {
        cur.push(r);
    }
    else
    {
        if (cur.top().d > r.d)
        {
            cur.push(r);
        }
        else
        {
            stack<Activity> tmpSt;
            while (!cur.empty())
            {
                if (cur.top().d < r.d)
                {
                    tmpSt.push(cur.top());
                    cur.pop();
                }else break;
            }
            cur.push(r);
            while (!tmpSt.empty())
            {
                cur.push(tmpSt.top());
                tmpSt.pop();
            }
        }
    }
}
int main()
{
    FASTIO;
#ifdef NAVONIL
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;

    vector<int> res(n, 0);
    vector<Activity> act(m);
    map<int, vector<Activity>> starts;
    loop(i, m)
    {
        act[i].i = i + 1;
        cin >> act[i].s >> act[i].d >> act[i].c;
        res[act[i].d - 1] = m + 1;
        starts[act.at(i).s - 1].pb(act[i]);
    }
    sort(act.begin(), act.end(), myS);
    // loop(i, m)
    // {
    //     cout << act[i].s << " " << act[i].d << " " << act[i].c << endl;
    // }
    // for (int &n : res)
    //     cout << n << " ";
    // cout << endl;

    // int k = m - 1;
    stack<Activity> cur;
    loop(i, n)
    {

        auto start = starts.find(i);
        if (start != starts.end())
        {
            for (Activity &a : start->second)
            {
                addToStack(cur, a);
            }
        }
        if (cur.empty())
            continue;
        if (res[i] == 0)
        {
            if (cur.top().d < (i + 1) && cur.top().c != 0)
            {
                cout << -1 << endl;
                return 0;
            }
            res[i] = cur.top().i;
            --cur.top().c;
            if (cur.top().c == 0)
            {
                cur.pop();
            }
        }
    }

    if (!cur.empty())
    {
        cout << -1 << endl;
        return 0;
    }
    // if (act.size() != 0)
    // {
    //     cout << -1 << endl;
    //     return 0;
    // }
    for (int &n : res)
        cout << n << " ";
    cout << endl;
#ifdef NAVONIL
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
    return 0;
}