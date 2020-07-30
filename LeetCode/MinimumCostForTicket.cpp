#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dp;
    const vector<int> D = {0, 6, 29};
    int rec(vector<int> &days, vector<int> &costs, int i, int inRange)
    {
        if (i >= (int)days.size())
        {
            return 0;
        }

        if (days[i] <= inRange)
        {
            return rec(days, costs, i + 1, inRange);
        }
        if(dp[i] != -1)
            return dp[i];
        
        int tmp = 1e9;
        for (int j = 0; j < 3; ++j)
        {
            tmp = min(
                tmp,
                rec(days, costs, i + 1, days[i] + D[j]) + costs[j]

            );
        }
        return dp[i] = tmp;
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        dp = vector<int>(1000, -1);
        return rec(days, costs, 0, 0);
    }
};

int main()
{
    Solution s;
    vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vector<int> costs = {2, 7, 15};
    cout << "Answer " << s.mincostTickets(days, costs) << endl;
    return 0;
}