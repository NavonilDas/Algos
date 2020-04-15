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
struct Pos
{
    int x, y;
};
// void isPossible(int i,int j){
//     if(i >= 0 && j >= 0 && i)
// }
/**
 * mat(char) & paths,
 *  const int &m,
 * const int &n, 
 * mat(bool) & visited, 
 * int i, int j, Pos &final, int count = 0
 * */
void solve(mat(char) & paths, const int &m, const int &n, mat(bool) & visited, int i, int j, Pos &final, int k, bool &ans, int count = 0)
{
    // if (visited.at(i).at(j))
    //     return;
    visited.at(i).at(j) = true;
    // cout << i << "," << j << " " << count << endl;
    if (i == final.x && j == final.y)
    {
        // found
        ans = ans || (count == k);
        // if(count != 0)
        // ans = min(ans,count);
        // cout << "found" << endl;
        return;
    }
    // cout << (i + 1) << " " << m << endl;
    bool top = ((i - 1) >= 0 && paths.at(i - 1).at(j) != 'X') && !visited[i - 1][j],
         left = ((j - 1) >= 0 && paths.at(i).at(j - 1) != 'X') && !visited[i][j - 1],
         bottom = ((i + 1) < m && paths.at(i + 1).at(j) != 'X') && !visited[i + 1][j],
         right = ((j + 1) < n && paths.at(i).at(j + 1) != 'X') && !visited[i][j + 1];
    int c = top + bottom + left + right;
    if (c > 1)
        ++count;
    // if(top)

    // RECURSION
    // return;
    // Check left
    if (left)
    {
        solve(paths, m, n, visited, i, j - 1, final, k, ans, count);
    }
    // Check Right
    if (right)
    {
        solve(paths, m, n, visited, i, j + 1, final, k, ans, count);
    }
    // Check Top
    if (top)
    {
        solve(paths, m, n, visited, i - 1, j, final, k, ans, count);
    }
    // Check Bottom
    if (bottom)
    {
        solve(paths, m, n, visited, i + 1, j, final, k, ans, count);
    }
}
int main()
{
    // clock_t tStart = clock();
    FASTIO;
#ifdef NAVONIL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, k;
    Pos final = {0, 0}, initial = {0, 0};
    mat(char) paths;
    mat(bool) visited;
    till(t)
    {
        cin >> n >> m;
        paths = mat(char)(n);
        visited = mat(bool)(n);
        loop(i, n)
        {
            paths.at(i) = vector<char>(m);
            visited.at(i) = vector<bool>(m, false);
            loop(j, m)
            {
                cin >> paths.at(i).at(j);
                if (paths.at(i).at(j) == '*')
                {
                    final.x = i;
                    final.y = j;
                }
                else if (paths.at(i).at(j) == 'M')
                {
                    initial.x = i;
                    initial.y = j;
                }
            }
        }
        cin >> k;
        bool ans = false;
        solve(paths, n, m, visited, initial.x, initial.y, final, k, ans);
        if (ans)
            cout << "Impressed\n";
        else
            cout << "Oops!\n";
        paths.clear();
        visited.clear();
    }
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}