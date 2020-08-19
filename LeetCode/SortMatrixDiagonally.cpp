class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // if element are in same diagonal the i - j  is constant
        const int n = mat.size();
        const int m = mat[0].size();
        map<int,priority_queue<int,vector<int>,greater<int>>> tmp;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                tmp[i-j].push(mat[i][j]);
            }
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                mat[i][j] = tmp[i-j].top();
                tmp[i-j].pop();
                // tmp[i-j].push(mat[i][j]);
            }
        }
        
        return mat;
    }
};