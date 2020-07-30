class Solution {
public:
    int maximumSum(vector<int>& arr) {
        const int n = arr.size();
        if(n == 0) return 0;
        
        int res = arr[0];
        int not_deleted = arr[0];
        int deleted = 0;
        for(int i=1;i<n;++i){
            // add current element to the already deleted or delete the current element and add the remaining array
            deleted = max(not_deleted,deleted + arr[i]);
            
            // Add Element to existing subarray or start array from current element
            not_deleted = max(not_deleted+arr[i], arr[i]); 
            
            // Find the largest among them
            res = max({res,deleted,not_deleted});
        }
        return res;
    }
};