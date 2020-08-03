class Solution {
public:
    int nthUglyNumber(int n) {
        // 2^a * 3^b * 5^c
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        // minumum value can be 2^0*3^0*5^0
        dp[0] = 1;
        int a,b,c;
        a = b = c = 0;
        
        for(int i=1;i<n;++i){
            // the next number will always be a multiple of (2,3,5) of some previous number
            // find the minimum among them
            dp[i] = min({ dp[a]*2,dp[b]*3,dp[c]*5 });
            
            
            // increment the previous number if the calculated number is multiple of 2 or 3 or 5
            if(dp[i] == dp[a]*2) ++a;
            if(dp[i] == dp[b]*3) ++b;
            if(dp[i] == dp[c]*5) ++c;
            
            // cout<<dp[i]<<" ";
        }
        return dp[n-1];
    }
};