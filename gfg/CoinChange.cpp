#include <bits/stdc++.h>
using namespace std;
/**
 * Get Total Ways
 * Minimum number of Coins
 * is it pssible
 * */
int getTotalWays(vector<int> &coins, const int n)
{
    int m = coins.size();
    int dp[m][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; ++i)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int x, y;
            x = y = 0;
            if (coins[i] <= j)
                x = dp[i][j - coins[i]];

            if (i > 0)
                y = dp[i - 1][j];
            dp[i][j] = x + y;
        }
    }
    return dp[m - 1][n];
}
int minCoins(vector<int> &coins, const int n)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
        dp[i] = 99999;
    int m = coins.size();
    for (int i = 0; i < m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (j >= coins[i])
            {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }
    return dp[n];
}
bool isPossible(vector<int> &coins, int n)
{
    int m = coins.size();
    int dp[m][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; ++i)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int x, y;
            x = y = 0;
            if (coins[i] <= j)
                x = dp[i][j - coins[i]];

            if (i > 0)
                y = dp[i - 1][j];
            if (x != 0)
                dp[i][j] = x;
            else
                dp[i][j] = y;
        }
    }
    return dp[m - 1][n] > 0;
}
int main()
{
    vector<int> coins = {1,2,3,4,5,6};
    cout << getTotalWays(coins, 3) << endl;
    // cout << minCoins(coins, 10) << endl;
    // cout << isPossible(coins, 10) << endl;
    return 0;
}