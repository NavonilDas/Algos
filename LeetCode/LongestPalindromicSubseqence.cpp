class Solution {
public:
    int longestPalindromeSubseq(string A) {
        const int n = A.size();
        int dp[1001][1001] = {0};
        
        for(int i=0;i<n;++i){
            dp[i][i] = 1;
        }
        for(int len=2;len<=n;++len){
            for(int i=0;i<n-len+1;++i){
                int j = i+len -1;
                if(A[i] == A[j]){
                    dp[i][j] = 2 + ((len > 2)?dp[i+1][j-1]:0);
                }else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};