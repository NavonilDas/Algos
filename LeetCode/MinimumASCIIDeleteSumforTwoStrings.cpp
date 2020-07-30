class Solution {
public:
    int minimumDeleteSum(string A, string B) {
        long sum = 0;
        const int n = A.size();
        const int m = B.size();
        // for(char &c:A)
        //     sum += (int)c;
        // if(B.size() == 0) return (int)sum;
        // for(char &c:B)
        //     sum += (int)c;
        // if(A.size() == 0) return (int)sum;    
        int dp[1002][1002];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;++i){
            sum += (int)A[i-1];
            
            for(int j=1;j<=m;++j){
                if(i == 1)
                    sum += (int)B[j-1];
                
                if(A[i-1] == B[j-1]){
                    dp[i][j] = (int)A[i-1] + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        sum = sum - 2*dp[n][m];
        return (int)sum;
    }
};