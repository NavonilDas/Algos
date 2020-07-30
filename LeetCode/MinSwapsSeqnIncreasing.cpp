#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    const int INF = 1e9;
    int dp[1005][2];
    /**
    [3,3,8,9,10] [1,7,4,6,8]**/
    int solve(vector<int> &A, vector<int> &B, int i, int pA, int pB, bool swp = false)
    {
        if (i >= (int)A.size())
            return 0;
        if (dp[i][swp] != -1)
            return dp[i][swp];

        int ret = INF;
        int swaps;
        if (A[i] > pA and B[i] > pB)
        {
            swaps = solve(A, B, i + 1, A[i], B[i]);
            ret = min(ret, swaps);
        }
        if (A[i] > pB and B[i] > pA)
        {
            swaps = solve(A, B, i + 1, B[i], A[i], true);
            ret = min(ret, swaps + 1);
        }
        return dp[i][swp] = ret;
    }
    int minSwap(vector<int> &A, vector<int> &B)
    {
        memset(dp, -1, sizeof(dp));
        return solve(A, B, 0, -1, -1);
    }
};

int main()
{
    Solution s;
    vector<int> A = {0, 1, 4, 6, 8};
    vector<int> B = {1, 2, 2, 7, 10};
    cout << "Answer " << s.minSwap(A, B) << endl;
    return 0;
}