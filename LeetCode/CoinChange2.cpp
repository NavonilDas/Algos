class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const int n = coins.size();
        if(amount == 0 and n == 0)
            return 1;
        if(n == 0)
            return 0;
        
        int dp[505][5005];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;++i)
            dp[i][0] = 1;
        
        for(int i=0;i<n;++i){
            for(int j=1;j<=amount;++j){
                int x,y;
                x = y = 0;
                if(i > 0)
                    x = dp[i-1][j];
                if(j >= coins[i])
                y = dp[i][j - coins[i]];
                dp[i][j] = x+y;                
            }
            
        }
        
        return dp[n-1][amount];
    }
};