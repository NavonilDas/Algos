class Solution {
public:
    void helper(int n,int &k,int &target,vector<int> &tmp,vector<int> &ans){
        if(n > target) return;
        if(n == target){
            int x = 0;
            for(int i=0;i<tmp.size();++i){
                x = x*10 + tmp[i];
            }
            ans.push_back(x);
            return;
        }
        
        int start = 0;
        if(n == 0) start = 1;
        for(int i=start;i<=9;++i){
            if(n > 0){
                if(abs(tmp[n-1] - i) == k){
                    tmp.push_back(i);
                    helper(n+1,k,target,tmp,ans);
                    tmp.pop_back();
                }
            }
            else {
                tmp.push_back(i);
                helper(n+1,k,target,tmp,ans);
                tmp.pop_back();
            }
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ans;
        if(N == 1) ans.push_back(0);
        vector<int> tmp;

        helper(0,K,N,tmp,ans);
        return ans;
    }
};