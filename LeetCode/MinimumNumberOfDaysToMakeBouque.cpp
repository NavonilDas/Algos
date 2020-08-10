class Solution {
public:
    
    bool isPossible(vector<int>& ar,int d,int &k,int &m){
        /// Check if it is possible to make a boque after d days
        int seqn = 0;
        int bouque = 0;
        for(int i=0;i<ar.size();++i){
            if(ar[i] > d) seqn = 0;
            else{
                ++seqn;
                if(seqn >= k) {
                    ++bouque;
                    seqn = 0;
                }
                if(bouque >= m) return true;
            }
        }
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        const int n = bloomDay.size();
        if(n < m*k) return -1;
        int l = INT_MAX;
        int r = INT_MIN;
        for(int i=0;i<n;++i){
            l = min(bloomDay[i],l);
            r = max(bloomDay[i],r);
        }
        if(l == INT_MAX) assert(false);
        int ans = -1;
        while(l <= r){
            int mid = (l+r)>>1;
            if(isPossible(bloomDay,mid,k,m)){
                r = mid-1;
                ans = mid;
            }else 
                l = mid + 1;
        }
        return ans;
    }
};