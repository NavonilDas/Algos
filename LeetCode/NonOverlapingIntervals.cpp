bool myS(vector<int> &a,vector<int> &b){
       if(a[0] == b[0])
           return a[1] < b[1];
        return a[0] < b[0];
    }
    
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& ar) {
        const int n = ar.size();
        if(n <= 1) return 0;
        sort(ar.begin(),ar.end(),myS);
        int ans = 0;
        int prev = 0;
        for(int i=1;i<n;++i){
            if(ar[i][0] < ar[prev][1]){
                ++ans;
                // For complete overlap
                if(ar[i][1] < ar[prev][1]) {
                    // cout<<ar[prev][0]<<","<<ar[prev][1]<<"  "<<ar[i][0]<<","<<ar[i][1]<<endl;
                    prev = i;
                }
            }else prev = i;
        }
        return ans;
    }
};