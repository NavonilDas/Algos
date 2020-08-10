class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> rot;
        queue<pair<int,int>> tmp;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] == 2){
                    rot.push({i,j});
                }
            }
        }
        int ans = 0;
        while(true){
            while(!rot.empty()){
                auto fr = rot.front();
                int i = fr.first,j = fr.second;
                rot.pop();
                if(i-1 >= 0 && grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    tmp.push({i-1,j});
                }
                if(j-1 >= 0 && grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    tmp.push({i,j-1});
                }
                if(i+1 < n && grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    tmp.push({i+1,j});
                }
                if(j+1 < m && grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    tmp.push({i,j+1});
                }
            }
            if(tmp.empty()) break;
            ++ans;
            rot = tmp;
            tmp = queue<pair<int,int>>();
        }
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return ans;
    }
};