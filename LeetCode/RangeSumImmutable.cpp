class NumArray {
public:
    vector<long long> pre;
    NumArray(vector<int>& nums) {
        if(nums.size() == 0) return; 
        pre = vector<long long>(nums.size());
        
        pre[0] = nums[0];
        for(int i=1;i<nums.size();++i)
            pre[i] = nums[i] + pre[i-1];
        
    }
    
    int sumRange(int i, int j) {
        return (pre[j] - ((i>0)?pre[i-1]:0));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */