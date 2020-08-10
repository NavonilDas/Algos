class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        // Longest Common Substring
        // if(A.size() == 0 and B.size() == 0) return 0;
        vector<vector<int>> dp(A.size()+1,vector<int>(B.size()+1,0));
        int ans = 0;
        for(int i=1;i<=A.size();++i){
            for(int j=1;j<=A.size();++j){
                if(A[i-1] == B[j-1])
                    dp[i][j] = 1+ dp[i-1][j-1];
                else dp[i][j] = 0;
                ans = max(dp[i][j],ans);
            }
        }
        return ans;
    }
};