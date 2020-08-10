class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        int n = s.size()-1;
        for(int i=0;i<s.size();++i){
            ans += pow(26,n-i)*(s[i] - 'A' + 1);
        }
        return ans;
    }
};