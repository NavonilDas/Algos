class Solution {
public:
    int countSubstrings(string s) {
        int ans = s.size();
        const int n = s.size();
        if(n == 0) return 0;
        bool dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;++i)
            dp[i][i] = true;
        
        for(int len = 2;len <= n;++len){
            for(int i=0;i<n-len+1;++i){
                int j = i + len - 1;
                if(s[i] == s[j]){
                    if(len == 2){
                        dp[i][j] = true;
                    }else
                        dp[i][j] = dp[i+1][j-1];
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};