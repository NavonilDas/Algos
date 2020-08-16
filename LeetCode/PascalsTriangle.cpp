class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows == 0) return {};
        ans.push_back({1});
        if(numRows == 1) return ans;
        // if(numRows)
        ans.push_back({1,1});
        for(int i=3;i<=numRows;++i){
            vector<int> tmp;
            tmp.push_back(1);
            for(int j=1;j<i-1;++j){
                // cout<<(i-2)<<","<<j<<","<<(j-1)<<endl;
                tmp.push_back(ans[i-2][j] + ans[i-2][j-1]);
            }
            tmp.push_back(1);
            ans.push_back(tmp);
        }
        return ans;
    }
};