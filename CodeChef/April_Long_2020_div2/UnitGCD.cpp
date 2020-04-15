// Har Har Mahadev
// By Navonil Das
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// change ull to ll for negative
ull gcd(ull a, ull b) { return (b == 0) ? a : gcd(b, a % b); }
// ull pwrm(ull a,ull p,ull m){
//     ull res = 1;
//     a = a%m;
//     while(p > 0){
//         if(res&1)
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
const int MAX = 1000000;
// bool primes[MAX + 5];
// vector<int> ps, np;
// void s()
// {
//     fill(primes, primes + MAX, true);
//     primes[1] = true;

//     for (int p = 2; p * p <= MAX; p++)
//     {
//         if (primes[p] == true)
//         {
//             for (int i = p * p; i <= MAX; i += p)
//                 primes[i] = false;
//         }
//     }
//     for (int i = 1; i <= MAX; ++i)
//         if (primes[i])
//         {
//             ps.pb(i);
//         }
//         else
//             np.pb(i);
//     // cout << ps.size() << endl;
//     // for(int i=0;i<ps.size();++i){
//     //     if(np[i]%ps[i] == 0){
//     //         cout<<np[i]<<" "<<ps[i]<<endl;
//     //     }
//     //         // cout<<"Yup\n";
//     // }
// }

// map<int, int> lastPos;

// void startFill(int pos, int n, int Max, mat(int) & test, bool *visited)
// {
//     // cout << "CALLED " << n << " at " << pos << endl;
//     for (int i = n; i <= Max; i += n)
//     {
//         if (visited[i])
//             continue;
//         // if(pos >= test.size())
//         //     test.pb(vector<int>());
//         test.at(pos++).pb(i);
//         visited[i] = true;
//     }
//     lastPos[n] = pos;
// }
// int ar[MAX][3];
int main()
{
    FASTIO;
#ifdef NAVONIL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // clock_t tStart = clock();
    // s();
    // cout<<(ll)(1e6)<<endl;
    int n;
    // mat(int) ans;
    till(t)
    {
        cin >> n;
        if (n == 1)
        {
            cout << "1\n1 1\n";
        }
        else
        {
            // ans = mat(int)(n);
            bool done = false;
            int k = n >> 1, inti = 1, second = 2;
            cout<<k<<endl;
            loop(j, k)
            {
                if (n & 1 && !done)
                {
                    cout << "3 " << inti << " " << second << " " << n << endl;
                    done = true;
                }
                else
                    cout << "2 " << inti << " " << second<<endl;
                // ans[j].pb(inti);
                inti += 2;
                second += 2;
            }
            //     inti = 2;
            //     loop(j, k)
            //     {
            //         ans[j].pb(inti);
            //         inti += 2;
            //     }
            //     if (n & 1)
            //         ans[0].pb(n);
            //     cout << k << endl;
            //     loop(j, k)
            //     {
            //         auto &x = ans[j];
            //         cout << x.size() << " ";
            //         for (auto &y : x)
            //             cout << y << " ";
            //         cout << endl;
            //     }
        }
        // ans.clear();
    }
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}