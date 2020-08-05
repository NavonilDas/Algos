class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // Coin Change Problem
        const int n = nums.size();
        vector<long long> dp(target + 1,0);
        dp[0] = 1;
        
        /*
        for(int i=1;i<=n;++i){
            for(int j=1;j<=target;++j){
                if(j >= nums[i-1]){
                    dp[j] += dp[j-nums[i-1]];
                }
            }
        }*/
        
        for(int i=1;i<=target;++i){
            for(int j=0;j<n;++j){
                if(i >= nums[j]){
                    dp[i] = (dp[i] + dp[i-nums[j]])%2147483647;
                }
            }
        }
        
        return dp[target];
    }
};