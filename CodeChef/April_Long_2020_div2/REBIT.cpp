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
#define ull long long int
#define vi vector<int>
#define vt(type) vector<type>
#define mat(type) vector<vector<type>>
#define pb push_back
#define mp make_pair
#define mii map<int, int>
#define setbits(a) __builtin_popcountll(a)
#define zrobits(a) __builtin_ctzll(a)
#define MOD 998244353
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
ull pwrm(ull a, ull p, ull m)
{
    ull res = 1;
    a = a % m;
    if (a == 0)
        return 0;
    while (p > 0)
    {
        if (p & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        p >>= 1;
    }
    return res % m;
}
ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

ll modDivide(ll a, ll b, ll m)
{
    a = a % m;
    ll inv = modInverse(b, m);
    return (inv * a) % m;
}
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// fill,copy,lower_bound,upper_bound,max_element,min_element
class Fraction
{
public:
    ll nr;           // numerator
    unsigned int dr; // Power of 4 Denominator
    Fraction()
    {
        nr = 1;
        dr = 1;
    }
    Fraction(int a, int b) : nr(a), dr(b)
    {
    }
    // Fraction operator/(Fraction &b)
    // {
    //     // TODO: May be Later
    //     return *this;
    // }
    Fraction operator*(Fraction b)
    {
        int a = (this->dr + b.dr);
        int k = (this->nr * b.nr) % MOD;
        return Fraction(k, a);
    }
    Fraction operator*(int a)
    {
        return Fraction((this->nr * a), this->dr);
    }
    // Fraction operator+(Fraction x){
    //     return this->operator+(x);
    // }
    Fraction operator+(Fraction b)
    {
        if (b.dr == this->dr)
        {
            return Fraction((this->nr + b.nr) % MOD, b.dr);
        }
        if (b.dr > this->dr)
        {
            int diff = b.dr - this->dr;
            // ull tmp = (pow(4,diff) * (this->nr%MOD))%MOD;
            ull tmp = pwrm(4, diff, MOD);
            tmp = (tmp * this->nr) % MOD;
            tmp = (tmp + b.nr) % MOD;
            return Fraction(tmp, b.dr);
        }
        if (b.dr < this->dr)
        {
            int diff = this->dr - b.dr;
            // ull tmp = (((ull)pow(4, diff)) * (b.nr % MOD)) % MOD;
            ull tmp = pwrm(4, diff, MOD);
            tmp = (tmp * b.nr) % MOD;
            tmp = (tmp + this->nr) % MOD;
            return Fraction(tmp, b.dr);
        }
        return *this;
    }
    Fraction operator-()
    {
        return Fraction(-1 * this->nr, this->dr);
    }
    Fraction operator-(Fraction b)
    {
        Fraction tmp = -b;
        return this->operator+(tmp);
    }
    Fraction operator%(ull modulus)
    {
        return Fraction(this->nr % modulus, this->dr);
    }
    void print()
    {
        cout << this->nr << "/(4^" << this->dr << ")" << endl;
    }
    void result()
    {
        cout << modDivide(this->nr, pwrm(4, this->dr, MOD), MOD);
    }
};
struct State
{
    int state;
    bool isIndex;
};
int state_counter = 0;
/*
INDEX -> Detail
0 -> Probablity of Zero
1 -> Probablity of One
2 -> Probablity of a
3 -> Probablity od A
*/
vector<Fraction> hash_sy = {{1, 1}, {1, 1}, {1, 1}, {1, 1}};

map<int, vector<Fraction>> states_table;

vector<Fraction> solve_and(vector<Fraction> &op1, vector<Fraction> &op2)
{
    vector<Fraction> new_state(4);
    new_state[1] = op1[1] * op2[1];
    new_state[0] = (op1[0]) + (op2[0]) - (op1[0] * op2[0]) + (op1[2] * op2[3]) + (op1[3] * op2[2]);
    new_state[2] = (op1[2] + op1[1]) * (op2[2] + op2[1]) - new_state[1];
    new_state[3] = (op1[3] + op1[1]) * (op2[3] + op2[1]) - new_state[1];
    return new_state;
}

vector<Fraction> solve_or(vector<Fraction> &op1, vector<Fraction> &op2)
{
    vector<Fraction> new_state(4);
    new_state[0] = op1[0] * op2[0];
    new_state[1] = op1[1] + op2[1] - op1[1] * op2[1] + op1[2] * op2[3] + op1[3] * op2[2];
    new_state[2] = (op1[2] + op1[0]) * (op2[2] + op2[0]) - new_state[0];
    new_state[3] = (op1[3] + op1[0]) * (op2[3] + op2[0]) - new_state[0];
    return new_state;
}

vector<Fraction> solve_xor(vector<Fraction> &op1, vector<Fraction> &op2)
{
    vector<Fraction> new_state(4);
    new_state[0] = op1[1] * op2[1] + op1[0] * op2[0] + op1[2] * op2[2] + op1[3] * op2[3];
    new_state[1] = op1[0] * op2[1] + op1[1] * op2[0] + op1[2] * op2[3] + op1[3] * op2[2];
    new_state[2] = op1[2] * op2[0] + op1[0] * op2[2] + op1[3] * op2[1] + op1[1] * op2[3];
    new_state[3] = op1[3] * op2[0] + op1[0] * op2[3] + op1[2] * op2[1] + op1[1] * op2[2];
    return new_state;
}

// Return the index of new State
// int op_and(

vector<Fraction> solve_op(vector<Fraction> &op1, vector<Fraction> &op2, char &op)
{
    if (op == '&')
        return solve_and(op1, op2);
    else if (op == '|')
        return solve_or(op1, op2);
    return solve_xor(op1, op2);
}
int solve_middleware(State &a, State &b, char &op)
{
    if (!a.isIndex && !b.isIndex)
    {
        states_table[state_counter] = solve_op(hash_sy, hash_sy, op);
    }
    else if (a.isIndex && !b.isIndex)
    {
        states_table[state_counter] = solve_op(states_table[a.state], hash_sy, op);
    }
    else if (!a.isIndex && b.isIndex)
    {
        states_table[state_counter] = solve_op(hash_sy, states_table[b.state], op);
    }
    else if (a.isIndex && b.isIndex)
    {
        states_table[state_counter] = solve_op(states_table[a.state], states_table[b.state], op);
    }
    return state_counter++;
}

int solve(vector<State> &exp)
{
    if (sz(exp) != 3)
    {
        // cerr << exp.size() << endl;
        // for (State &tmp : exp)
        //     cerr << tmp.isIndex << " " << tmp.state << endl;
        for (auto it = states_table.begin(); it != states_table.end(); ++it)
            cerr << it->first << " ";
        cerr << "Something Went Wrong!\n";
        exit(0);
    }
    State a = exp[0];
    State b = exp[2];
    char opr = exp[1].state;
    return solve_middleware(a, b, opr);
    // if (opr == '&')
    // {
    //     return op_and(op1, op2);
    // }
    // else if (opr == '|')
    // {
    // }
    // else if (opr == '^')
    // {
    // }
    // return 97;
}
void print_details(vector<Fraction> &a)
{
    a[0].result();
    cout << " ";
    a[1].result();
    cout << " ";
    a[2].result();
    cout << " ";
    a[3].result();
    cout << endl;
}
void mine(string &inp)
{
    stack<State> st;
    // st.push()
    int cur = 0, n = sz(inp);
    while (cur < n)
    {
        if (inp[cur] == ')')
        {
            vector<State> exp; // Expression
            while (true)
            {
                State tmp = st.top();
                st.pop();
                if (!tmp.isIndex && tmp.state == (int)'(')
                {
                    break;
                }
                exp.pb(tmp);
                // if (!tmp.isIndex)
                //     cout << (char)(tmp.state) << " ";
                // else
                //     cout << (tmp.state) << " ";
            }
            // cout << endl;
            // if (sz(exp) != 3)
            // {-
            // }
            State bk;
            bk.state = solve(exp);
            bk.isIndex = true;
            st.push(bk);
            // if (bk.state == 40)
            // {
            //     while (!st.empty())
            //     {
            //         State fuxk = st.top();
            //         st.pop();
            //         if (!fuxk.isIndex)
            //             cout << (char)(fuxk.state) << "";
            //         else
            //             cout << (fuxk.state) << "";
            //     }
            //     exit(0);
            // }
            exp.clear();
        }
        else
        {
            State tmp;
            tmp.state = inp[cur];
            tmp.isIndex = false;
            st.push(tmp);
        }
        ++cur;
    }
    State tmp = st.top();
    // cout<<tmp.isIndex<<" "<<tmp.state<<endl;
    // print_details(states_table[0]);
    print_details(states_table[tmp.state]);
    // cout<<st.size()<<endl;
}

// vector<State> test(1000000);
int main()
{
    // clock_t tStart = clock();
    FASTIO;
#ifdef NAVONIL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string a = "";
    till(t)
    {
        cin >> a;
        if (sz(a) == 1)
        {
            cout << "748683265 748683265 748683265 748683265\n";
        }
        else
            mine(a);
    }
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}