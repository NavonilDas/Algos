#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &pre, int mid, int k)
{
    for (int i = mid; i < (int)pre.size(); ++i)
    {
        if (pre[i] - pre[i - mid] > k)
            return false;
    }

    return true;
}
int binSearch(vector<int> &pre, int k)
{
    int l = 1;
    int r = pre.size() - 1;
    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (isPossible(pre, mid, k))
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> ar = {1, 2, 10, 4};
    int n = ar.size();
    int k = 8;
    vector<int> pre(n + 1);
    pre[1] = ar[0];

    for (int i = 1; i < n; ++i)
    {
        pre[i + 1] = pre[i] + ar[i];
    }
    cout << binSearch(pre, k) << endl;
    return 0;
}