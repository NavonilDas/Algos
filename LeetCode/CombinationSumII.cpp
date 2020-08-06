class Solution {
public:
    void Back(int sum,int s,vector<int> &ar,vector<int> &tmp,vector<vector<int>> &ans){
        if(sum == 0){
            ans.push_back(tmp);
            return;
        }
        if(sum < 0){
            return;
        }
        for(int i=s;i<ar.size();++i){
            if(i > s and ar[i] == ar[i-1]) continue;
            tmp.push_back(ar[i]);
            Back(sum - ar[i],i+1,ar,tmp,ans);
            tmp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        Back(target,0,candidates,tmp,ans);
        return ans;
    }
};