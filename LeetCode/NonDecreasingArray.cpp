class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i = 0,cnt = 0;
        const int n = nums.size();
        while(i < n-1){
            if(nums[i] <= nums[i+1]) ++i;
            else {
                // cout<<nums[i]<<" "<<nums[i+1]<<endl;
                if(i - 1 < 0 || nums[i-1] <= nums[i+1]) nums[i] = nums[i+1];
                else nums[i+1] = nums[i];
                ++cnt;
                if(cnt > 1) return false;
            }
        }
        
        return (cnt<=1);
    }
};