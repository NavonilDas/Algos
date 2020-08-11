class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(3,vector<int>(prices.size(),0));
        for(int i=1;i<=2;++i){
            int prev = INT_MIN;
            for(int j=1;j<n;++j){
                prev = max(
                    prev,
                    dp[i-1][j-1] - prices[j-1]
                );
                dp[i][j] = max(dp[i][j-1],prices[j] + prev);
            }
        }
        
        return dp[2][n-1];
    }
};