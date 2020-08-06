class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hsh;
        for(int &i:nums){
            ++hsh[i];
        }
        // size + 1 if same element is repeated n number of times
        vector<vector<int>> bucket(nums.size() + 1);
        int mx = -1;
        for(auto &p:hsh){
            bucket[p.second].push_back(p.first);
            if(mx < p.second)
                mx = p.second;
        }
        const int n = bucket.size();
        /*
        for(auto x:bucket){
            for(int y:x)
            cout<<y<<" ";
            cout<<endl;
        }
        cout<<endl<<endl;*/
        vector<int> ans;
        int tmp = 0;
        while(true){
            if(mx < 0 || ans.size()==k)
                break;
            for(int n:bucket[mx]){
                // cout<<n<<" ";
                ans.push_back(n);
                // ++tmp;
                if(ans.size() == k) break;
            }
            --mx;
        }
        // cout<<endl;
        /*
        for (int i = bucket.size() - 1; i >= 0 && ans.size() < k; --i) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }*/
        return ans;
    }
};