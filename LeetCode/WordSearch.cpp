class Solution {
public:
    
    bool dfs(int i,int j,int c,vector<vector<char>>& board,string &word){
        if(c >= word.size()) return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if(board[i][j] != word[c]) return false;
        board[i][j] = '#'; // Make it visited
        
        bool ans = 
            dfs(i-1,j,c+1,board,word) || 
            dfs(i+1,j,c+1,board,word) || 
            dfs(i,j-1,c+1,board,word) || 
            dfs(i,j+1,c+1,board,word);
        
        board[i][j] = word[c]; // Revert Back
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        const int n = board.size();
        const int m = board[0].size();
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(dfs(i,j,0,board,word)) return true;
            }
        }
        
        return false;
    }
};