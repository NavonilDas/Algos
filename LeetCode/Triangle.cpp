class Solution {
public:
    int getAdaj(int i,int j,int m,vector<vector<int>>& triangle){
        int mn = INT_MAX;
        if(j - 1 >= 0){
            mn = min(mn,triangle[i-1][j-1]);
        }
        // cout<<j<<endl;
        if(j < m){
            mn = min(mn,triangle[i-1][j]);            
        }
        if(mn == INT_MAX){
            cout<<endl<<j<<" "<<m<<endl<<endl;
        }
        return mn;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        const int n = triangle.size();
        if(n == 0) return 0;
        if(n == 1) return triangle[0][0];
        int ans = 0;
        // Simple DFS
        for(int i=1;i<n;++i){
            int mn = INT_MAX - 100;
            const int m = triangle[i].size();
            for(int j=0;j<m;++j){
                triangle[i][j] += getAdaj(i,j,m-1,triangle);
                mn = min(mn,triangle[i][j]);
                // cout<<triangle[i][j]<<","<<getAdaj(i,j,m-1,triangle)<<" ";
            }
            if(i == n-1)
                ans = mn;
            // cout<<endl;
        }
        
        /*for(int i=0;i<n;++i){
            const int m = triangle[i].size();
            for(int j=0;j<m;++j){
                
                // triangle[i][j] += getAdaj(i,j,m-1,triangle);
                cout<<triangle[i][j]<<" ";//<<","<<getAdaj(i,j,m-1,triangle)<<" ";
            }
            cout<<endl;
        }*/

        
        return ans;
    }
};