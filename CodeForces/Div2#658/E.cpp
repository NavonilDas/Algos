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
#define pii pair<int, int>

// int cse = 1;
// #define google(a) cout << "Case #" << (cse++) << ": " << a << endl;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

// For Input
int ar[100007];
int result[100007];

struct Data
{
    int element;
    int freq;
    bool operator()(Data &a, Data &b)
    {
        return a.freq < b.freq;
    }
};

void solve(const int n, const int x, const int y)
{

    map<int, vector<int>> positions;

    // Heap on the basis of the Frequency
    priority_queue<Data, vector<Data>, Data> pq;

    // The remaining elements which needs to be replace ie they should not have any match
    int to_append = -1;
    for (int i = 0; i < n; ++i)
    {
        // Take Input Array
        cin >> ar[i];
        // Store the Position in map
        positions[ar[i]].push_back(i);
        result[i] = -1;
    }
    // Create The Heap
    for (int i = 1; i <= (n + 1); ++i)
    {
        auto ele = positions.find(i);
        if (ele != positions.end())
        {
            pq.push({ele->first, (int)ele->second.size()});
        }
        else
        {
            if (to_append == -1)
                to_append = i;
        }
    }
    // cout << pq.top().element << " " << pq.top().freq << endl
    //      << endl;

    // choose upto x Elements on the basis of frequency
    for (int i = 0; i < x; ++i)
    {
        Data t = pq.top();
        pq.pop();
        --t.freq;

        // Get the locatin of most frequent and append it to result
        int loc = positions[t.element].back();
        positions[t.element].pop_back();
        // We will insert it later as we need to insert remaininf (n-y) elements such that no elements matches
        result[loc] = 0;
        // debug(loc);

        if (t.freq)
            pq.push(t);
    }
    // Check if it is possible to make the resulting array
    if (pq.size())
    {
        // Let f be the number of occurrences of the most frequent color in the n−x indices. Then the number of forced matches is clearly at least 2f−(n−x)
        int ok = pq.top().freq; // f
        if (2 * ok - (n - x) > (n - y))
        {
            cout << "NO\n";
            return;
        }
    }
    // we know that array is possible
    // Step 1: Get Remaining elements which are not placed
    // remaining elemnts with their position
    vector<pii> remaining;
    while (!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        for (int i = 0; i < t.freq; ++i)
        {
            remaining.push_back({t.element,
                                 positions[t.element][i]});
        }
    }
    // Step 2: Rotate Array by n-x/2
    int rotate = (n - x) >> 1;
    for (int i = 0; i < (int)remaining.size(); ++i)
    {
        // Calculate the Rotated Position
        int to_insert = remaining[(rotate + i) % remaining.size()].second;
        // Insert it to the result
        result[to_insert] = remaining[i].first;
    }
    // Using greedy approach to fill the position of n-y
    int done = 0;
    for (int i = 0; i < n; ++i)
    {
        if (result[i] == ar[i])
        {
            result[i] = to_append;
            ++done;
        }
    }
    // fill remaining n-y-done
    for (int i = 0; done < (n - y); ++i)
    {
        if (result[i] != 0 && result[i] != to_append)
        {
            result[i] = to_append;
            ++done;
        }
    }
    // Fill the empty places
    for (int i = 0; i < n; ++i)
    {
        if (result[i] == 0)
            result[i] = ar[i];
    }
    // Print The array
    // cout << "For " << n << " " << x << " " << y << endl;
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main()
{
    FASTIO;
#ifdef NAVONIL
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    till(t)
    {
        int n, x, y;
        // x is number of perfect match
        // y is total number of match
        cin >> n >> x >> y;
        solve(n, x, y);
    }

#ifdef NAVONIL
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
    return 0;
}