class Solution {
public:
    int nCr(int n,int r){
        long long ans = 1;
        if( r > n-r)
            r = n-r;
        for(int i=0;i<r;++i){
            ans *= (n-i);
            ans /= (i+1);
        }
        return ans;
    }
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        if(rowIndex == 1) return {1,1};
        vector<int> ans(rowIndex+1);
        const int n = ans.size();
        ans[0] = ans[n-1] = 1;
        for(int i=1;2*i<=n;++i){
            ans[i] = ans[n-1-i] = nCr(n-1,i);
        }
        return ans;
    }
};