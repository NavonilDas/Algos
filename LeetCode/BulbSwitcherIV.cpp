class Solution {
public:
    int minFlips(string target) {
        const int n = target.size();
        // use reverse approach
        int ans = 0;
        char prev = '0';
        for(int i=0;i<n;++i){
            if(target[i] != prev){
                // flipped till this 
                ++ans;
            }
            prev = target[i];
        }
        return ans;
    }
};