class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        /*
            Goal is flip the column only to make it more closer to the first column
            
            we need to make the first column all to 1 as it contribute more
            Column j will contribute (total matches) * (power(2, N - 1 - j ))
            example column 3 will contribute 4
        */
        const int rows = A.size();
        const int cols = A[0].size();
        int ans = rows * (1 << (cols - 1));
        int matches = 0;
        for(int c = 1; c < cols; ++c){
            matches = 0;
            for(int r = 0; r < rows; ++r){
                matches += (A[r][c] == A[r][0]);
            }
            ans += max(matches, rows - matches) * (1 << ( cols - c - 1 ));
        }
                
        return ans;
    }
};