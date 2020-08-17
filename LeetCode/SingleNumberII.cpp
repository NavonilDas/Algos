class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int ans = 0;
        for(int i=0;i<32;++i){
            int c = 0;
            for(int &n:nums){
                if((n >> i)&1)++c;
            }
            if(c%3 != 0) ans |= (1<<i);
        }
        return ans;
    }
};