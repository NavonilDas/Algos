class Solution {
public:
    vector<int> countBits(int n) {
        /**
            if a number is even then then number of set bits = set bits in number / 2
            if a numbet is odd then the number of set bits = set bits in number / 2 + 1
            
        */
        vector<int> ans(n+1);
        ans[0] = 0;
        if(n > 0)
            ans[1] = 1;
        if(n > 1)
            ans[2] = 1;
        if(n > 2)
            for(int i=3;i<=n;++i)
                ans[i] = (i&1)?ans[i>>1]+1:ans[i>>1];
        return ans;
    }
};