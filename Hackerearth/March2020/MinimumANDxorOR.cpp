#include <bits/stdc++.h>
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define ull long long
#define vi vector<int>

using namespace std;
int main()
{
    FASTIO
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vi ar(n);
        for (int i = 0; i < n; ++i)
            cin >> ar[i];
        sort(ar.begin(), ar.end());
        int Min = INT_MAX, j;
        for (int i = 0; i < ar.size() - 1; ++i)
        {
            j = i + 1;
            Min = min((ar[i] & ar[j]) ^ (ar[i] | ar[j]), Min);
        }
        cout<<Min<<endl;
        ar.clear();
    }
    return 0;
}