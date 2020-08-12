class Solution {
public:
    int numTeams(vector<int>& rating) {
        // Brute Force Aproach
        
        int less[2],greater[2];
        // less[0] will store the count of those numbers where nums[i] < nums[j] and i > j
        // less[1] will store the count of those number where nums[i] < nums[j] and i < j
        // greater[0] will store the count of those number where nums[k] > nums[j] and k > j
        // greter[1] will store the count of those number where nums[k] > nums[j] and k < j
        // For rating[i] < rating[j] < rating[k] and 0 <= i < j < k < n
        // less[1] * greater[0]
        // For rating[i] > rating[j] > rating[k] and 0 <= i < j < k < n
        // less[0] * greater[1]
        const int n = rating.size();
        int ans = 0;
        for(int i=0;i<n;++i){
            // Reset Value for a Particular i , j pair
            less[0] = less[1] = greater[0] = greater[1] = 0;
            
            for(int j=0;j<n;++j){
                if(rating[i] < rating[j])
                    ++less[j > i];
                if(rating[i] > rating[j])
                    ++greater[j > i];
            }
            
            // 
            ans += less[0] * greater[1] + less[1]*greater[0];
        }
        
        return ans;
    }
};