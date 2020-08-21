class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0,r = A.size() - 1;
        while(l < r){
            if(!(A[l]&1)) ++l;
            else if(A[r]&1) --r;
            else if((A[l]&1) && !(A[r]&1)){
                swap(A[l],A[r]);
                ++l;
                --r;
            }
        }
        return A;
    }
};