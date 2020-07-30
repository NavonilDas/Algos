class Solution {
public:
    int longestCommonSubsequence(string A, string B) {
        int dp[1002][1002];
        int n = A.size();
        int m = B.size();
        for(int i=0;i<max(n,m);++i){
            dp[i][0] = dp[0][i] = 0;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(B[j-1] == A[i-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};