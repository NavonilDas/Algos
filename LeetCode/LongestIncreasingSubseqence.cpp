class Solution {
public:
    int lengthOfLIS(vector<int>& ar) {
        if(ar.size() == 0) return 0;
        vector<int> active(ar.size());
        int len = 1;
        const int n = ar.size();
        active[0] = ar[0];
        for(int i=1;i<n;++i){
            auto pos = lower_bound(active.begin(),active.begin()+len,ar[i]);
            if((pos-active.begin())==len)
                active[len++] = ar[i];
            else
                *pos = ar[i];
        }
        return len;
    }
};