class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        // A + B + C + D = 0
        // A + B = -C-D
        map<int,int> hsh;
        for(int i=0;i<A.size();++i){
            for(int j=0;j<B.size();++j){
                // A[i] + B[j]
                ++hsh[A[i] + B[j]];
            }
        }
        int ans = 0;
        for(int i=0;i<C.size();++i){
            for(int j=0;j<D.size();++j){
                ans += hsh[-(C[i] + D[j])];
            }
        }        
        return ans;
    }
};