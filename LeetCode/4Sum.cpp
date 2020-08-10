class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& ar, int target) {
        vector<vector<int>> ans;
        const int n = ar.size();
        sort(ar.begin(),ar.end());
        
        for(int i=0;i<n;++i){
            if(i > 0 && ar[i] == ar[i-1]) continue;
            for(int j=i+1;j<n;++j){
                if(j > (i+1) && ar[j] == ar[j-1]) continue;
                int l = j+1,r = n-1;
                while(l < r){
                    int sum = ar[i] + ar[j] + ar[l] + ar[r]; 
                    if(sum == target){
                        ans.push_back({ar[i] , ar[j] , ar[l] , ar[r]});
                        while(l < r && ar[l] == ar[l+1]) ++l;
                        while(l < r && ar[r] == ar[r-1])  --r;
                        ++l;
                        --r;
                    }else if(sum < target) ++l;
                    else --r;
                }
            }
        }
        
        return ans;
    }
};