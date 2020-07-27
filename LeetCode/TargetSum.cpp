#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long long sum = 0;
        for(int i:nums)
                sum += i;
        long long ok = (S+sum);
        if(S > sum || -S < -sum || ok&1) return 0;
        int k = ok>>1;
        vector<int> dp(k+1,0);
        dp[0] = 1;
        for(int i:nums){
            for(int j=k;j>=i;--j){
                dp[j] += dp[j - i];
            }
        }
        return dp[k];
   }
};