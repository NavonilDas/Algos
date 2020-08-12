class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // long long sum = 0;
        const int n = nums.size();
        if(n == 0) return false;
        /**
        Alternative 
        // if(k == 0) return false;
        vector<int> pre(n,0);
        pre[0] = nums[0];
        for(int i=1;i<n;++i){
            pre[i] = nums[i] + pre[i-1];
        }
        for(int len = 2;len<=n;++len){
            for(int i=0;i<=(n-len);++i){
                int j = i + len - 1;
                if(k == 0 and (pre[j] - (i>0?pre[i-1]:0)) == 0) return true;
                if(k != 0 and (pre[j] - (i>0?pre[i-1]:0))%k == 0){
                    return true;
                }
            }
        }
        **/
        map<int,int> pos; // Store Position respect to sum
        int runningSum = 0;
        pos[0] = -1;
        for(int i=0;i<n;++i){
            runningSum += nums[i];
            if(k != 0) runningSum %= k;
            if(pos.find(runningSum) != pos.end()){
                if(i - pos[runningSum] > 1) return true;
            }else pos[runningSum] = i;
        }
        return false;
    }
};