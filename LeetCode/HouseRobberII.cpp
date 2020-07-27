#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        int dpi[n+1]; // First element is included
        int dpn[n+1]; // First Element is not included
        dpi[0] = dpn[0] = dpn[1] = 0;
        dpi[1] = nums[0];
        for(int i=2;i<n;++i){
            dpi[i] = max(nums[i-1] + dpi[i-2],dpi[i-1]);
            dpn[i] = max(nums[i-1] + dpn[i-2],dpn[i-1]);
        }
        dpi[n] = dpi[n-1];
        dpn[n] = max(dpn[n-1],nums[n-1]+dpn[n-2]);
        return max(dpi[n],dpn[n]);
    }
};