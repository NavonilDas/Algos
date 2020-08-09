class NumArray {
public:
    vector<int> bit;
    vector<int> orig;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        bit = vector<int>(nums.size() + 1,0);
        orig = vector<int>(nums.size());
        for(int i=0;i<n;++i){
            update(i,nums[i]);
            orig[i] = nums[i];
        }
    }
    
    void update(int i, int val) {
        int diff = val - orig[i];
        orig[i] = val;
        i=i+1;
        while(i <= n){
            bit[i] += diff;
            i += (i&(-i));
        }
    }
    int get(int i){
        if(i < 0) return 0;
        i = i+1;
        int ans = 0;
        while(i > 0){
            ans += bit[i];
            i -= (i&(-i));
        }
        return ans;
    }
    int sumRange(int i, int j) {
        return get(j) - get(i-1);
        return 0;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */