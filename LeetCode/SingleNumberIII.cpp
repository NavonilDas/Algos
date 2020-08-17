class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        /**
        Let a and b be the two unique numbers
        XORing all numbers gets you (a xor b)
        (a xor b) must be non-zero otherwise they are equal
        If bit_i in (a xor b) is 1, bit_i at a and b are different.
        Find bit_i using the low bit formula m & -m
        Partition the numbers into two groups: one group with bit_i == 1 and the other group with bit_i == 0.
        a is in one group and b is in the other.
        a is the only single number in its group.
        b is also the only single number in its group.
        XORing all numbers in a's group to get a
        XORing all numbers in b's group to get b
        Alternatively, XOR (a xor b) with a gets you b
        **/
        if(nums.size() == 0) return {};
        
        // Find the Xor of the two unique number
        int Xor = nums[0];
        const int n = nums.size();
        for(int i=1;i<n;++i){
            Xor ^= nums[i];
        }
        // Find the right most set bit
        int diff = Xor & -Xor;
        
        vector<int> ans = {0,0};
        for(int i=0;i<n;++i){
            // if the bit on the nums and diff are not set then xor it one group
            if((nums[i]&diff) == 0) ans[0] ^= nums[i];
            else ans[1] ^= nums[i];
        }
        return ans;
    }
};