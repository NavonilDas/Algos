class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            int p = abs(nums[i]);
            if(nums[p-1] < 0) return p;
            nums[p-1] *= -1;
        }
        return 0;
    }
};