class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        const int n = groupSizes.size();
        vector<vector<int>> ans;
        
        map<int,vector<int>> hsh; 
        for(int i=0;i<n;++i){
            hsh[groupSizes[i]].push_back(i);
            if(hsh[groupSizes[i]].size() == groupSizes[i]){
                ans.push_back(hsh[groupSizes[i]]);
                hsh[groupSizes[i]] = {};
            }
        }
        return ans;
    }
};