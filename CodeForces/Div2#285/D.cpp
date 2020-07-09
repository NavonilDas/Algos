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

// ll findRank(vector<int> &n)
// {
// }
const int MAX = 2e6 + 5;
int ftree[MAX] = {0};
int sum[MAX] = {0};
int query(int node)
{
    int sum = 0;
    while (node > 0)
    {
        sum += ftree[node];
        node -= (node & -node);
    }
    return sum;
}

void update(int node, int diff, int &mx)
{
    while (node <= mx)
    {
        ftree[node] += diff;
        node += (node & -node);
    }
}
/**
 * Binary Search the element based on the index s from the binary indexed tree
 * 
 * */
int bsearch(int &n, int s)
{
    int l = 1;
    int r = n;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        int p = query(m);
        if (p < s)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;
}

// vi getFactoradic(int n)
// {
//     vi factoradic(13);
//     int i = 1;
//     while (n != 0)
//     {
//         factoradic[13 - i] = n % i;
//         n = n / i;
//         i++;
//     }
//     return factoradic;
// }

int main()
{
    FASTIO;
#ifdef NAVONIL
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    memset(ftree, 0, sizeof(ftree));
    memset(sum, 0, sizeof(sum));

    int n;
    cin >> n;
    from(i, 1, n)
    {
        update(i, 1, n);
    }

    int p;
    loop(i, n)
    {
        cin >> p;
        int less = query(p + 1) - 1;
        sum[i] += less;
        // cout << less << "x" << (n - i - 1) << "! " << endl;
        update(p + 1, -1, n);
    }

    // cout << endl;
    from(i, 1, n)
    {
        update(i, 1, n);
    }
    loop(i, n)
    {
        cin >> p;
        int less = query(p + 1) - 1;
        sum[i] += less;
        // cout << less << "x" << (n - i - 1) << "! " << endl;
        update(p + 1, -1, n);
    }

    for (int i = 0; i < n; ++i)
    {
        int carry = sum[n - i - 1] / (i + 1);
        sum[n - i - 2] += carry;
        sum[n - i - 1] %= (i + 1);
        update(i + 1, 1, n);
    }
    loop(i, n)
    {
        int f = bsearch(n, sum[i] + 1);
        cout << (f - 1) << ' ';
        update(f, -1, n);
        // cout << query(i + 1) << " ";
        // cout << sum[i] << " ";
    }
    cout << endl;

#ifdef NAVONIL
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
    return 0;
}

/**
 * 

3x2! 2x1! 0x0! => 8
9x2! 8x1! 1x0! => 28

12 * 2 + 10*1 + 1
24 + 10 + 1 => 35


35/1 => 0
35/2 => 1
17/3 => 2
5/4  => 1
1/5 => 1
1 1 2 1 0

2*6 1*2 0*1 0*1


1
1
2
1
0

1x4! 1x3! 2x1! 1x0!
24 + 6 + 2 

110
210


3 2 0

1 0 0

5
2 1 3 0 4
2 0 4 3 1

1 3

2*4! + 1*3! + 1*2! + 0 * 1! + 0*0! => (48+6 + 2) => 56

2*4! + 0*3! + 2*2! + 1*1! + 0*0! =>  (48 + 4+1) => 53

109 => 4*4! + 1*3! + 3*2! + 1*1 + 0*0! => (96 + 6 + 6 + 1)

4 1 3 1 0

4 2 0 1 0

0/1 => 0
1/2 => 0
3/3 => 1
2/4 => 0
4/5 => 0


4 2 0 3 1

0 1
*/