class Solution {
public:
    void Back(int sum,int start,vector<int> &ar,vector<int> &tmp,vector<vector<int>> &ans){
        if(sum == 0){
            ans.push_back(tmp);
            return;
        }
        if(sum < 0){
            return;
        }
        for(int j = start;j<ar.size();++j){
            int i = ar[j];
            tmp.push_back(i);
            Back(sum-i,j,ar,tmp,ans);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        Back(target,0,candidates,tmp,ans);
        return ans;
    }
};