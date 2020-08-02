class Solution {
public:
    vector<int> twoSum(vector<int>& A, int S) {
        const int n = A.size();
        vector<int> ans;
        if(n == 0 and S == 0)
            return ans;
        if(n == 1 and S == A[0]){
            ans.push_back(1);
            return ans;
        }
        int l = 0,r = n - 1;
        while(l < n and r >= 0 and l < r){
            int tmp = (A[l] + A[r]);
            if(tmp == S){
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }
            if(tmp > S){
                --r;
            }else if(tmp < S){
                ++l;
            }
        }
        return ans;
    }
};