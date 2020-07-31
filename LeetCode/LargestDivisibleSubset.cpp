class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        /**
        It is kind of similar to Longest increasing Subsequence 
        the < or > operator changes to a modulus operator
        
        we traverse back to get the original array
        **/
        const int n = nums.size();
        if(n <= 1)
            return nums;
        
        sort(nums.begin(),nums.end());
        
        vector<int> dp(n+1,1);
        int mx = 1;        
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]%nums[j] == 0){
                    dp[i] = max(dp[i],dp[j]+1);   
                    if(mx < dp[i]){
                        mx = dp[i];
                    }
                }
            }
        }
        
        // for(int i=0;i<n;++i){
        //     cout<<dp[i]<<" ";
        // }
        vector<int> ans;
        int prev = -1;

        for(int i=n-1;~i;--i){
            if(dp[i] == mx && (prev%nums[i] == 0 || prev == -1)){
                ans.push_back(nums[i]);
                prev = nums[i];
                --mx;
            }
        }
        return ans;
    }
};