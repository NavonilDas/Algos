class Solution {
public:
    void dfs(int n,vector<vector<int>>& graph,int &target,vector<int> &tmp,vector<vector<int>> &ans){
        if(n == target){
            ans.push_back(tmp);
        }
        for(int child:graph[n]){
            tmp.push_back(child);
            dfs(child,graph,target,tmp,ans);
            tmp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {      
        vector<vector<int>> ans;
        vector<int> tmp;
        int n = graph.size() - 1;
        tmp.push_back(0);
        dfs(0,graph,n,tmp,ans);
        
        return ans;
    }
};