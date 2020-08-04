class Solution {
public:
    int singleNonDuplicate(vector<int>& ar) {
        // Binary Search
        int l = 0;
        int r = ar.size() - 1;
        while(l < r){
            int mid = (l + r) >> 1;
            // if the mid is the element we are loking for
            if(ar[mid]!=ar[mid-1] && ar[mid] != ar[mid+1])
                return ar[mid];
            
            // in case mid is odd subtract 1 to make even
            mid -= mid&1;
            // if the mid and mid+1 are not equal split at mid
            if(ar[mid] != ar[mid+1]) r = mid;
            // if they are same split ahead of them
            else l = mid + 2;
        }
        return ar[l];
    }
};