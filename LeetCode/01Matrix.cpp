class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        if(n == 0) return matrix;
        const int m = matrix[0].size();
        if(m == 0)
            return matrix;
        
        int mx = n*m; // Maximum distance
        vector<vector<int>> ans(n,vector<int>(m,0));
        // From top, left to bottom right
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j] != 0){
                    int up = i > 0? ans[i-1][j]:mx;
                    int left = j > 0? ans[i][j-1]:mx;
                    ans[i][j] = min(up,left) + 1;
                } else ans[i][j] = 0;       
            }
        }
        // From Bottom right to top left
        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=0;--j){
                if(matrix[i][j] != 0){
                    int down = i < n-1? ans[i+1][j]:mx;
                    int right = j < m-1? ans[i][j+1]:mx;
                    ans[i][j] = min(ans[i][j], min(down,right)+1 );
                }else ans[i][j] = 0;
            }            
        }
        
        return ans;
    }
};