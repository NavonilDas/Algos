class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /**
        General Problem
        Divide a set into two parts such that the sum of both subset is same
        
        find sum divide it by 2 if not divisible then it is not possible to solve
        
        the problem breaks into solving a subset sum problem where we our sum is (sum_of_set/2)
        
        **/
        long sum = 0;
        for(int &x:nums)
            sum += x;
        const int n = nums.size();
        if(sum&1) return false;
        int check = sum>>1;
        // cout<<sum<<" "<<check<<endl;
        bool dp[n+1][check+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<=n;++i)
            dp[i][0] = true;
        // for(int i=1;i<=check;++i)
        //     dp[0][i] = false;
        
        for(int i=1;i<=n;++i){
            for(int j=1;j<=check;++j){
                if(j < nums[i-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        
        return dp[n][check];
    }
};