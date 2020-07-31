class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        if(n == 0) return "";
        bool dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<=n;++i){
            dp[i][i] = true;
        }
        int ans = 1,start = 0;
        for(int len=2;len<=n;++len){
            for(int i=0;i<n-len+1;++i){
                int j = i + len - 1;
                dp[i][j] = false;
                if(s[i] == s[j]){
                    if(j == i+1)
                        dp[i][j] = true;
                    
                    else if(dp[i+1][j-1])
                        dp[i][j] = true;
                }
                if(dp[i][j] and ans < len){
                    ans = len;
                    start = i;
                }
            }
        }
        if(start == -1)
            assert(false);
        // cout<<ans<<"  "<<start<<endl;
        return s.substr(start,ans);
    }
};