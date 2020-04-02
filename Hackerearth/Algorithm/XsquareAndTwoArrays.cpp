// Har Har Mahadev
// By Navonil Das
#include <bits/stdc++.h>
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define endl '\n'
#define ll long long
#define ull long long
#define vi vector<int>
// change ull to ll for negative
// ull gcd(ull a,ull b){return (b==0)?a:gcd(b,a%b);}
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #include <boost/multiprecision/cpp_int.hpp>
// using boost::multiprecision::cpp_int;
using namespace std;
int A[100001] = {0};
int B[100001] = {0};
int C[100001] = {0};
int D[100001] = {0};

inline int get(int *ar, int i, bool o)
{
    if (i < 0 && (i & 1 && o))
        return 0;
    return ar[i];
}

int main()
{
    FASTIO;
#ifdef NAVONIL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // prefix sum
    int n, q, tmp, l, r;
    cin >> n >> q;

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
        C[i] = A[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> B[i];
        D[i] = B[i];
    }
    C[0] = 0;
    A[1] = 0;
    for (int i = 2; i < n; ++i)
    {
        if(i&1){
            A[i] = A[i-1];
            B[i] = B[i-1];
            C[i] += C[i-2];
            D[i] += D[i-2];
            continue;
        }
        A[i] += A[i - 2];
        B[i] += B[i - 2];
        C[i] = C[i-1];
        D[i] = D[i-1];
    }
    for(int i=0;i<n;++i){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;++i){
        cout<<C[i]<<" ";
    }
    cout<<endl;
    while (q--)
    {
        cin >> tmp >> l >> r;
        --l;
        --r;
        int sum = 0;
        if (tmp == 1)
        {
            if (l & 1 && r & 1)
            {
                sum = get(A, r, true) - get(A, l - 1, true) + get(B, r - 1, false) - get(B, l, false);
            }
            else if (l & 1)
            {
            }
            else if (r & 1)
            {
            }
            else
            {
                // cout<<(l)<<"-"<<r<<endl;
                // cout<<get(A,l-1)<<get(B,l)<<endl;
                sum = get(A, r, false) - get(A, l - 1, false) + get(B, r - 1, true) - get(B, l - 1, true);
            }
        }
        else
        {
        }
        cout << sum << endl;
    }
    return 0;
}