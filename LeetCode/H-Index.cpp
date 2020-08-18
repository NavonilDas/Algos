class Solution {
public:
    int hIndex(vector<int>& ar) {
        const int n = ar.size();
        if(n == 0) return 0;
        
        // Sort the array
        sort(ar.begin(),ar.end());
        
        int l = 0,r = n - 1;
        int mid,ans;
        
        while(l <= r){
            mid = (l+r)>>1;
            // n - mid as there are no more than n - h citations
            if(ar[mid] < n - mid){
                // ans = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        
        // cout<<ans<<endl;
        return n - l;
    }
};