class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& A) {
        // It is like sliding window of size 3
        // we don't need to sort as we have to consider consecutive elements
        const int n = A.size();
        int cur = 0;
        int sum = 0;
        /**
            [1,2,3,4,5,6]
            
            for window of size 3
            [1,2,3] => sum+1
            for [1,2,3,4] => sum + 2
            we add two because [2,3,4] and [1,2,3,4] itself both are possible
            similarly for [1,2,3,4,5] => sum + 3
            [3,4,5] , [2,3,4,5]  [1,2,3,4,5]
            similarly for [1,2,3,4,5,6] => sum + 4
            [4,5,6]  [3,4,5,6]   [2,3,4,5,6]   [1,2,3,4,5,6]
        **/
        for(int i=2;i<n;++i){
            if( (A[i] - A[i-1]) == (A[i-1] - A[i-2]) ){
                cur += 1;
                sum += cur;
            }else cur = 0;
        }
        
        return sum;
    }
};