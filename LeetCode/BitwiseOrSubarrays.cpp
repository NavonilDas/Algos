class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int l=0,r; // l=> left, r=> right
        // Generally r will store the size of tmp before inserting the element
        
        // It will store the result of previous Ors
        vector<int> tmp;
        // This is to Store Unique ORs
        map<int,bool> hsh;
        
        // For each items in the array
        for(int item:A){
            // Current Size of Array
            r = tmp.size();
            // Insert Current Element as the element itself is a substring
            tmp.push_back(item);
            // mark element as visited
            hsh[item] = true;
            
            // From left to right
            for(int i=l;i<r;++i){
                // Calculate For each previous_or LOGICAL_OR current element
                int x = (item|tmp[i]);
                // Check if or is present or not
                // this is done to stop the tmp upto 30bits (bits in 10^9)
                if(tmp.back() != x){
                    // Insert the calculated or
                    tmp.push_back(x); 
                    hsh[x] = true;
                }
            }
            // Change the value of left
            l = r;
            // left will be equal to the index from where all subarray containing current element
            // we do this because we already know that if we have compute AR[i]^AR[i+1]...AR[j]
            // then we don't have to compute it again ie. if the or already computed in subarray
            // then while or of new element we don't have to iterate all subarray till new element
            // instead we can take all subarrays of previous or
        }            
        return hsh.size();
    }
};