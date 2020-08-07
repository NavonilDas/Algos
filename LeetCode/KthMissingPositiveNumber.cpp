class Solution {
public:
    int findKthPositive(vector<int>& ar, int k) {
        int ans = 1,i = 0;
        while(k > 0){
            if(i < ar.size() && ans == ar[i]){
                ++i;
            }else{
                --k;
            }
            ++ans;
        }
        return ans - 1;
    }
};