class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int n = nums.size();
        if(n == 0) return 0;
        /**
        While Building The LIS dp array we have to maintain another array for storing the count this array will tell us that for some index this is the number of sequences we can get.
        Then We have to find the maximum length from the dp.
        If there are multiple maximum length at some index then for those index add the count to the answer.
        **/
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int mxLen = 1,ans = 1;
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i] > nums[j]){
                    if(dp[i] == dp[j]+1){
                        cnt[i] += cnt[j];
                    }
                    else if(dp[i] < dp[j]+1){
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }                 
                }
            }
            
            if(mxLen == dp[i]){
                ans += cnt[i];
            }
            else if(mxLen < dp[i]){
                mxLen = dp[i];
                ans = cnt[i];
            }
        }
        /*
        for(int i:dp){
            cout<<i<<" ";
        }
        cout<<endl;
        for(int i:cnt){
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<endl;*/
        return ans;
    }
};