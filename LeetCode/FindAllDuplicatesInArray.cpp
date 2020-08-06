class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        // cout<<nums.size()<<endl;
        
        for(int i=0;i<nums.size();++i){
            int p = (abs(nums[i])-1);
            // cout<<(abs(nums[i])-1)<<endl;
            if(nums[p] < 0){
                // cout<<(p+1)<<endl;
                ans.push_back(p+1);
            }else{
                nums[p] *= -1;
            }
        }
        return ans;
    }
};