class Solution {
public:
    void wiggleSort(vector<int>& ar) {
        // median
        const int n = ar.size();
        if(n == 0) return;
        
        // Finc the Median
        auto medi = ar.begin() + (n >> 1);
        // it modifies array
        nth_element(ar.begin(),medi, ar.end());
        int med = *medi;
        
        
        
        int place = 0; // Scan Element From Left Right
        int left = 1; // Odd Position
        int right = n&1?n-1:n-2; // Even Position
        
        while(place < n){
            // For number greater then median place it to odd position
            if(ar[place] > med && (place > left || place%2 == 0) ){
                swap(ar[place],ar[left]);
                left += 2;
            }
            // For number less than median place it to even position
            else if(ar[place] < med && (place < right || place%2 != 0) ){
                swap(ar[place],ar[right]);
                right -= 2;
            }
            else ++place;
        }
    }
};