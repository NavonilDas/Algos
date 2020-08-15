class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> forw(nums.size(),0);
        vector<int> bac(nums.size(),0);
        int k = 0,c = 0;
        for(int n:nums){
            if(n == 1) ++c;
            else c = 0;
            forw[k++] = c;
        }
        c = 0;
        k = 0;
        for(int i=n-1;i>=0;--i){
            if(nums[i] == 1) ++c;
            else c = 0;
            bac[i] = c;
        }
        int ans = -1;
        for(int i=0;i<n;++i){
            ans = max( ans , ((i > 0)?forw[i-1]:0) + ((i < n-1) ? bac[i+1]:0)); 
        }
        
        // for(int i:forw)
        //     cout<<i<<" ";
        // cout<<endl;
        // for(int i:bac)
        //     cout<<i<<" ";
        // cout<<endl;
        return ans;
    }
};