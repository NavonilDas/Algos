class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        const int n = A.size();
        vector<int> ans;
        for(int i=n;i>0;--i){
            int j = 0;
            while(j < n && A[j] != i) ++j;
            reverse(A.begin(),A.begin() + j + 1);
            ans.push_back(j+1);
            // for(int i:A)
            //     cout<<i<<" ";
            // cout<<endl;
            reverse(A.begin(),A.begin() + i);
            ans.push_back(i);
            // for(int i:A)
            //     cout<<i<<" ";
            // cout<<endl;
            // cout<<(j+1)<<endl;
        }
        return ans;
    }
};