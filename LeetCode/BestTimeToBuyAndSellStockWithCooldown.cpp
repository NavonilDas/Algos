class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /**
            Similar to LIS
            On selling stock at index i what can be the maximum profit at that day 
        **/
        const int n = prices.size();
        if(n == 0) return 0;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for(int i=1;i<n;++i){
            
            dp[i] = dp[i-1]; // The Profit on day i is equal to profit on previous day
            
            for(int j=0;j<i;++j){
                int previousSell = (j >= 2)?dp[j-2]:0;
                int profit = prices[i] - prices[j];
                
                dp[i] = max(
                    dp[i],
                    profit + previousSell
                );
                ans = max(ans,dp[i]);
            }
        }
        
        return dp[n-1];
    }
};