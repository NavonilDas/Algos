class Solution {
public:
    vector<vector<int>> rects;
    vector<int> areas;
    
    int sumArea = 0;
    Solution(vector<vector<int>>& rects): rects(rects) {
        int area;
        sumArea = 0;
        for(auto re:rects){
            area = (re[2]-re[0] + 1) * ( re[3] - re[1]+ 1);
            sumArea += area;
            areas.push_back(sumArea);
        }
    }
    
    vector<int> pick() {
        // Get a Random Area
        int rarea = rand()%sumArea;
        
        vector<int> ans(2);
        // Find a area such that the chosen area > random area
        auto it = upper_bound(areas.begin(),areas.end(),rarea);
        // Find the position of chosen rectangle
        int k = it - areas.begin();
        // Calculate Random Point
        ans[0] = rand() % (rects[k][2]-rects[k][0] + 1) + rects[k][0];        
        ans[1] = rand() % (rects[k][3] - rects[k][1]+ 1) + rects[k][1];
        
        return ans;
    }
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */