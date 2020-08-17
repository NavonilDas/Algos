class Solution {
public:
    int minSetSize(vector<int>& arr) {
        /**
            Create a Map of number -> frequence
        **/
        map<int,int> freq;
        for(int &n:arr) ++freq[n];
        
        // Group together numbers having same frequency
        map<int,vector<int>> freqToAr;
        for(auto &p:freq){
            freqToAr[p.second].push_back(p.first);
        }
        
        int ans = 0,items = 0;
        // Choose elements having maximum frequency
        // ans will store the unique numbers
        // add the frequency to the items 
        // if the size of items is more than or equal to half 
        // return ans
        for(int i=arr.size();i>0;--i){
            if(freqToAr.find(i) == freqToAr.end()) continue;
            for(int j:freqToAr[i]){
                ++ans;
                items += i;
                if(items >= arr.size()/2) return ans;
            }
        }
        return arr.size();
    }
};