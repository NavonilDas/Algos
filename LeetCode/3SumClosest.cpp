class Solution {
public:
    int threeSumClosest(vector<int>& ar, int target) {
        const int n = ar.size();
        
        sort(ar.begin(),ar.end());
        int mn = INT_MAX,ans = 0;
        for(int i=0;i<n;++i){
            int l = i+1,r = n - 1;
            while(l < r){
                int sum = ar[i]+ar[l]+ar[r];
                if(sum == target){
                    return sum;
                }
                if(sum < target){
                    ++l;
                    if(mn > (target-sum)){
                        mn = target - sum;
                        ans = sum;
                    }
                }else{
                    --r;
                    if(mn > (sum-target)){
                        mn = sum - target;
                        ans = sum;
                    }
                }
            }
        }
        
        return ans;
    }
};