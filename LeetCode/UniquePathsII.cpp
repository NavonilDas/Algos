class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ar) {
        int dp[102][102];
        const int n = ar.size();
        const int m = ar[0].size();
        // Initial Value of DP
        memset(dp,0,sizeof(dp));
        
        if(ar[0][0] == 1 || ar[n-1][m-1] == 1)
            return 0;
        
        dp[1][0] = 1;
        
        for(int i=1;i <= n;++i){
            for(int j=1;j <= m;++j){
                if(!ar[i-1][j-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};